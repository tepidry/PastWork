#version 150

in vec4 vPosition; //not vec4 in vec.h //passes position of vertex

void
main()
{
    gl_Position = vPosition;
}
