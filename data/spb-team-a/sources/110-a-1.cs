using System;
using System.IO;

namespace ConsoleApplication3
{
    class Program
    {
        static Boolean prov(UInt64 a)
        {
            if ((Math.Pow(a % 100,2) + Math.Pow(a / 100,2)) % 7 == 1)
                return true;
            else return false;
        }

        static void Main(string[] args)
        {
            StreamReader str = new StreamReader("abcd.in");
            StreamWriter stw = new StreamWriter("abcd.out");
            UInt64 a;

            a = Convert.ToUInt64(str.ReadLine());
            for (UInt64 i = 0; i < a; i++)
            {
                if (prov(Convert.ToUInt64(str.ReadLine())))
                    stw.WriteLine("YES");
                else stw.WriteLine("NO");
            }
            stw.Close();
            str.Close();
        }
    }
}
