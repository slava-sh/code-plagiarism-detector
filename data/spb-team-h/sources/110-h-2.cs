using System;
using System.IO;

namespace ConsoleApplication5
{
    class Program
    {
        static void Main(string[] args)
        {
            
            StreamReader str = new StreamReader("names.in");
            StreamWriter stw = new StreamWriter("names.out");
            UInt64 kol = Convert.ToUInt64(str.ReadLine());
            string[] ss = new string[kol * 3];
            for (UInt64 i = 0; i < kol; i++)
            {
                string[] s = str.ReadLine().Split(' ');
                ss[3 * i] = s[0];
                ss[(3 * i) + 1] = s[1];
                ss[(3 * i) + 2] = s[2];
               
            }
            string[] otv = new string[kol];
            Array.Sort(ss);

            str.Close();
            StreamReader str1 = new StreamReader("names.in");
            kol=Convert.ToUInt64(str1.ReadLine());
            for (UInt64 i = 0; i < kol; kol++)
            {
                string[] s = str1.ReadLine().Split(' ');
                if( (ss[(Array.BinarySearch(ss, s[0])) + 1] == s[0]) || (ss[Array.BinarySearch(ss, s[0]) - 1]== s[0]))
                {
                    otv[i] = s[2] + s[0] + s[1];
                }

            }
            Array.Sort(otv);

            foreach (string c in otv)
                stw.WriteLine(c);

            str1.Close();
            stw.Close();
        }
    }
}
