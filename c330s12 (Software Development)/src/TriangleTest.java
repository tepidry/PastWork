import org.junit.*;
import static org.junit.Assert.*;
public class TriangleTest {
	@Test
	public void WithinRange(){
        Triangle t = new Triangle(201, 201, 201);
        assertTrue(t.aWithinRange() == false);
        assertTrue(t.bWithinRange() == false);
        assertTrue(t.cWithinRange() == false);
        }
    @Test
	public void Equilateral(){
        Triangle t = new Triangle(20, 20, 20);
        assertTrue(t.isEquilateral() == true);
        assertTrue(t.isIsosceles() == false);
        assertTrue(t.isScalene() == false);
        assertTrue(t.isNotATriangle() == false);
    }
    @Test
    public void Isosceles(){
        Triangle r = new Triangle(20, 20, 21);
        assertTrue(r.isEquilateral() == false);
        assertTrue(r.isIsosceles() == true);
        assertTrue(r.isScalene() == false);
        assertTrue(r.isNotATriangle() == false); 
    }
    @Test
    public void Scalene(){
        Triangle q = new Triangle(20, 10, 5);
        assertTrue(q.isEquilateral() == false);
        assertTrue(q.isIsosceles() == false);
        assertTrue(q.isScalene() == true);
        assertTrue(q.isNotATriangle() == false); 
    }

}
