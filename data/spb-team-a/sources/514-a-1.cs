using System;
using System.IO;
namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] file = File.ReadAllLines("abcd.in");
            int count = Convert.ToInt32(file[0]);
            if (File.Exists("adbc.out")) File.Delete("abcd.out");
            for(int i =0;i<count;i++)
            {
                int ab = Convert.ToInt32(file[i + 1].Substring(0, 2));
                int cd = Convert.ToInt32(file[i + 1].Substring(2));
                if ((ab * ab + cd * cd) % 7 == 1)
                {
                    File.AppendAllText("abcd.out", "YES\r\n");
                }
                else
                    File.AppendAllText("abcd.out", "NO\r\n");
            }
        }
    }
}
