using System;
using System.IO;

class FStream
{
    static void Main()
    {
        
        const string pathName = "C:\\users\\paul\\Desktop\\";
        const string fileName = "Julia.txt";

        ReadForward(pathName + fileName);
        Console.WriteLine();
        ReadBackWards(pathName + fileName);
        Console.WriteLine();
        ReadBytes(pathName + fileName);
        
    }
    static void ReadForward(string file)
    {
        using (FileStream
            fileStream = new FileStream(file, FileMode.Open))
        {


            // Set the stream position to the beginning of the file.
            fileStream.Seek(0, SeekOrigin.Begin);
            for (int i = 0; i < fileStream.Length; i++)
                Console.Write(Convert.ToChar(fileStream.ReadByte()));
        }
    }
    static void ReadBytes(string file)
    {
        using (FileStream
            fileStream = new FileStream(file, FileMode.Open))
        {
            // Set the stream position to the beginning of the file.
            fileStream.Seek(0, SeekOrigin.Begin);
            for (int i = 0; i < fileStream.Length; i++)
                Console.WriteLine(fileStream.ReadByte());
        }
    }
    static void ReadBackWards(string file)
    {
        using (FileStream
            fileStream = new FileStream(file, FileMode.Open))
        {
            // Set the stream position to the beginning of the file.
            fileStream.Seek(0, SeekOrigin.End);
            fileStream.Seek(-1, SeekOrigin.End);
            const long stopPos = 1;
            // Read and verify the data.
            for (int i = 0; i < fileStream.Length; i++)
            {
                Console.Write(Convert.ToChar(fileStream.ReadByte()));
                if (fileStream.Position > stopPos)
                    fileStream.Seek(-2, SeekOrigin.Current);
            }
        }
    }
}


