using System;
using System.IO;

namespace ConsoleApplication3
{
    class Program
    {
        

        static void Main(string[] args)
        {
           StreamReader str = new StreamReader("merlin.in");
            StreamWriter stw = new StreamWriter("merlin.out");

            UInt64 a = Convert.ToUInt64(str.ReadLine());
            UInt64 sum = 0;
            string[] s = str.ReadLine().Split(' ');
            foreach (string i in s)
                sum += Convert.ToUInt64(i);
            stw.WriteLine(a - (sum / a));
            stw.Close();
           str.Close();
        }
    }
}
