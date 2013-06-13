using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;


class Test 
{
    public static void Main() 
    {
        string path1 = "C:\\Users\\Draper\\Desktop\\";
        path1 = path1 + "file.txt";
        string path2 = "";
        string line;
        try
        {
            using (StreamReader sr = new StreamReader(path1))
            {
                while ((line = sr.ReadLine()) != null)
                {
                    Console.WriteLine(line);
                }
            }
        }
        catch (ArgumentException e)
        {
            Console.WriteLine("Path is an empty string");
            Console.WriteLine(e);
        }
        catch (FileNotFoundException e)
        {
            Console.WriteLine("File not found");
            Console.WriteLine(e);
        }
        catch (IOException e)
        {
            Console.WriteLine("Read error");
            Console.WriteLine(e);
        }
    }
}

   
