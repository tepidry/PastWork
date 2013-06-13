#include "RenderEngine.h"

//@creates a rendering engine
RenderEngine::RenderEngine() : world_ptr(NULL)
{}

//@ assigns a world to the render engine and creates it
//@pre w_ptr points to an existing world of objects, lights, and camera
//@post world_ptr also points to that world
//@usage  engine_ptr = new RenderEngine(the_world_ptr);
RenderEngine::RenderEngine(World* w_ptr)
{
    world_ptr = w_ptr;
}

//@destroys a rendering engine
RenderEngine::~RenderEngine()
{}

//@does a shallow copy of a rendering engine
RenderEngine::RenderEngine(const RenderEngine& other)
{
    world_ptr = other.world_ptr;
}

//@does a shallow copy of a rendering engine
RenderEngine&
RenderEngine::operator=(const RenderEngine& rhs)
{
    if (this == &rhs) return *this;
    world_ptr = rhs.world_ptr;
    return *this;
}

//@sets the world in a rendering engine
void
RenderEngine::set_world(World* w_ptr)
{
    world_ptr = w_ptr;
}

//@renders a scene composed of objects, lights, and a camera
//@pre a world of objects, lights, and camera has been created
//@post renders the world scene into an image
//@usage renderEngine.render_scene();
void
RenderEngine::render_scene()
{
    RGBColor pixel_color;
    ShadeRec sr;
    for (int row = 0; row < world_ptr -> camera_ptr -> vres; row++)			// up
        for (int col = 0; col < world_ptr -> camera_ptr -> hres ; col++)  	// across
        {
            Ray ray = (world_ptr -> camera_ptr -> pixelRay(col, row));   // ray is from camera to pixel in col COLUMN and row ROW

            pixel_color = trace_ray(ray, sr, world_ptr -> depth);

            pixel_color = max_to_one(pixel_color);

            int index = row * 3 * world_ptr -> camera_ptr -> hres + col * 3 ;

            world_ptr -> camera_ptr -> image[index    ] = pixel_color.r;
            world_ptr -> camera_ptr -> image[index + 1] = pixel_color.g;
            world_ptr -> camera_ptr -> image[index + 2] = pixel_color.b;
        }
}



// ----------------------------------------------------------------------------- hit_objects
//@finds the color for the pixel using the closest hit point of a ray to an object in the world
//@pre ray and rayDepth are assigned
//@post returns the color of the pixel
//@usage pixel_color = trace_ray(ray, sr, world_ptr -> depth);
RGBColor
RenderEngine::trace_ray(const Ray& ray, ShadeRec& sr, int rayDepth) //shade record
{
    Vector3D normal;
    Vector3D local_hit_point;

    double	t;
    float	tmin 			= kHugeValue;

    int 	num_objects 	= world_ptr->objects.size();
    RGBColor pixel_color(0,0,0);

    sr.hit_an_object = false;  // reset
    for (int j = 0; j < num_objects; j++) //finds the closest hit point and corresponding t value on the ray
    {
        if (world_ptr -> objects[j] -> hit(ray, t, sr) && (t < tmin))
        {
            sr.hit_an_object	= true;
            tmin 				= t;
            sr.material_ptr     = world_ptr -> objects[j] -> get_material();
            normal 				= sr.normal;
            local_hit_point	 	= sr.local_hit_point;
        }

        if(sr.hit_an_object) // if it was a t < tmin then sr has values set by object's hit else sr is reset to before objects-> hit
        {
            sr.t = tmin;
            sr.normal = normal;
            sr.local_hit_point = local_hit_point;
        }

    }

    if (sr.hit_an_object)
    {

        pixel_color =  calc_shade(ray, sr);  // local color

        double kr = sr.material_ptr -> kr;
        if (kr > 0 && rayDepth > 0 )       // reflected color
           pixel_color  += kr * calc_reflected(ray, sr, rayDepth - 1);
    }
    else
    {
        pixel_color = world_ptr -> background_color;
    }

    return pixel_color;
}

//------------------------------------------------------------------ calc shading
//@finds the contributions to the pixel color from ambient, diffuse, and specular light
//@pre the ray and sr are assigned
//@post returns the pixel color contribution from ambient, diffuse, and specular light
//@usage pixel_color =  calc_shade(ray, sr);
RGBColor
RenderEngine::calc_shade(const Ray& ray, const ShadeRec& sr)
{
    RGBColor pixel_color(0,0,0);
    Material *m_ptr = sr.material_ptr;
    int num_lights = world_ptr -> lights.size();

    for (int i = 0; i < num_lights; i++)
    {
        PointLight light = *(world_ptr -> lights[i]);

        // see page 9 of ray tracing notes
        RGBColor ambient = m_ptr -> ka * m_ptr -> ca * light.intensity * light.color;
        pixel_color 	+=  ambient;

  //start of commenting to get ambient contribution only

        if (!inShadow(sr.local_hit_point, &light)) //if in shadow contribution to pixel  color
        {
            // l_dir = normalized vector pointing from hit pt to light
           Vector3D light_dir( light.get_location() - sr.local_hit_point);
           light_dir.normalize(); // vecotr L in notes

            // viewDir = normalized vector pointing from hit point to camera
            Vector3D viewDir = ray.o - sr.local_hit_point;                               ;
            viewDir.normalize(); // vector V in notes

            double cosNV = viewDir * sr.normal; // cos of angle between N and V
            double cosNL = light_dir * sr.normal;   //cos of angle between N and L

            if (cosNL > 0  && cosNV > 0)   // tests to see if light and viewer are above surface rather than below.
            {
                RGBColor diffuse = cosNL * (m_ptr -> kd) * (m_ptr-> cd) * light.intensity * light.color; //page 10
                pixel_color 	+= diffuse;

                // start of commenting out reflective contribution
                // reflectDir = normalized vector in direction of reflected light
                Vector3D reflectDir =  2 * cosNL * sr.normal - light_dir;
                reflectDir.normalize(); //VectorR
                double cosVR = (viewDir * reflectDir); //(V * R) // cos of angle between reflected direction vector and view direction vector
                if (cosVR > 0 )      // tests to see if view and reflected light are within 90 degrees of each other.
                {
                    // !!!   Note (sr.material_ptr->cs) left off specular calculation since relfected light is normally color of light, not material
                    RGBColor specular = pow(cosVR, m_ptr -> sp)/*power depends on material shiney*/ * (m_ptr -> ks)/*coefficient spec*/ * (m_ptr -> cs) * light.intensity * light.color;
                    pixel_color 	+= specular;
                }

            }
       }
       //end of commenting for ambient contribution only*/
    }
    return pixel_color;
}

RGBColor
RenderEngine::calc_reflected(const Ray& ray, ShadeRec& sr, int rayDepth)
{

    Vector3D viewDir = ray.o - sr.local_hit_point;
    viewDir.normalize();
    double cosVN = viewDir * sr.normal;
    Vector3D  reflectedDir = 2 * cosVN * sr.normal - viewDir;

    Ray reflectedRay(sr.local_hit_point, reflectedDir);

    RGBColor reflected_color;
    reflected_color = trace_ray(reflectedRay, sr, rayDepth); // warning - this changes sr
    return reflected_color;

}

// ----------------------------------------------------------------------------- check for shadows

bool
RenderEngine::inShadow(Vector3D hit_point, PointLight* light) const
{
    //note: draw vector from origin to                    : vector
    //    : draw vector from origin to                    : vector
    //    : draw vector from hit point to light source
    //    :
    Vector3D lightDir = light -> get_location() - hit_point;
    double len = lightDir.length();
    lightDir.normalize();

    //now make a ray from hit point to light source
    Ray  shadowRay(hit_point, lightDir);

    int num_objects = world_ptr -> objects.size();
    for (int j = 0; j < num_objects; j++)
    {
        double	t;
        ShadeRec sr;  // this is not really used for anything here

        // note, if the intersected object is the same as the jth object, then we should not get a hit since t < kEpsilon
        if (world_ptr -> objects[j] -> hit(shadowRay, t, sr) && (t > kEpsilon) && (t < len) ) return true;
    }

    return false;
}


// ------------------------------------------------------------------ clamp

RGBColor
RenderEngine::max_to_one(const RGBColor& c) const
{
    float max_value = max(c.r, max(c.g, c.b));

    if (max_value > 1.0)
        return (c / max_value);
    else
        return (c);
}

// ------------------------------------------------------------------ clamp_to_color
// Set color to red if any component is greater than one

RGBColor
RenderEngine::clamp_to_color(const RGBColor& raw_color) const
{
    RGBColor c(raw_color);

    if (raw_color.r > 1.0 || raw_color.g > 1.0 || raw_color.b > 1.0)
    {
        c.r = 1.0;
        c.g = 0.0;
        c.b = 0.0;
    }

    return (c);
}


