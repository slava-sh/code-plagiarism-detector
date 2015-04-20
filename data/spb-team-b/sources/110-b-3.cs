using System;
using System.IO;

namespace ConsoleApplication3
{
    class Program
    {
        

        static void Main(string[] args)
        {
           StreamReader str = new StreamReader("chess.in");
            StreamWriter stw = new StreamWriter("chess.out");
            UInt64 a,kol=1,x=1;

            a = Convert.ToUInt64(str.ReadLine());
            string [] s = str.ReadLine().Split(' ');

            for (UInt64 i = 1; i < a; i++)
            {
                UInt64 b = Convert.ToUInt64(s[i]);
                if (b > x)
                {
                    x++;
                    kol++;
                }
                else i = a+1; 
            }
            stw.WriteLine(kol);
            if (kol==1)
               stw.WriteLine("1 1"); else
            for (UInt64 i = 0; i < kol; i++)
            {
                stw.WriteLine("{0} {1}", i+1 , i+1);
            }
            stw.Close();
           str.Close();
        }
    }
}
