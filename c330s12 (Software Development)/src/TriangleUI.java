import java.io.*;
public class TriangleUI {

 public static void main (String[] args)  {
  
  String s1 = null;
  byte j = 0;
  int[] in = null;
  int a = 0, b= 0, c=0, i;
  Triangle t;
  
  
 
  
  	for (i = 0; i<3; i++){
      
      try {
        BufferedReader is = new BufferedReader(
          new InputStreamReader(System.in));
        System.out.println("enter your line >");
        
        s1 = is.readLine();
        if (i == 0){
        	a = Integer.parseInt(s1);
        } else if (i == 1) {
        	b = Integer.parseInt(s1);
        } else {
        	c = Integer.parseInt(s1);
        	
        }
        
      } catch (NumberFormatException ex) {
        System.err.println("Not a valid number: " + a);
      } catch (IOException e) {
        System.err.println("Unexpected IO ERROR: " + e);
      }
      System.out.println("I read this number: " + a);
    }
  	
  	
  
  
  		t = new Triangle(a, b, c);
  		if (t.aWithinRange() && t.bWithinRange() && t.cWithinRange()) {
  			if (t.isEquilateral()){
  				System.out.println("is Equilateral");
  			} else if (t.isIsosceles()) {
  				System.out.println("Is Isosceles");
  			} else if (t.isScalene()) {
  				System.out.println("Is Scalene");
  			} else if (t.isNotATriangle()) {
  				System.out.println("Not a triangle");
  			}
  		} else {
  			System.out.println("Not with in range 1 ~ 200");
  		}
 
 }
 
}
