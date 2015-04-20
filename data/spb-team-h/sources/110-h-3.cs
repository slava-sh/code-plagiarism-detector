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
            string[] ss1 = new string[kol * 3];
            for (UInt64 i = 0; i < kol; i++)
            {
                string[] s = str.ReadLine().Split(' ');
                ss[3 * i] = s[0];
                ss[(3 * i) + 1] = s[1];
                ss[(3 * i) + 2] = s[2];

                ss1[3 * i] = s[0];
                ss1[(3 * i) + 1] = s[1];
                ss1[(3 * i) + 2] = s[2];
               
            }

            string[] otv = new string[kol];
            Array.Sort(ss);

            str.Close();
            
            
            for (UInt64 i = 0; i < kol; kol++)
            {
                
                if( (ss[(Array.BinarySearch(ss, ss1[i*3])) + 1] == ss1[i*3]) || (ss[Array.BinarySearch(ss, ss1[i*3]) - 1]== ss1[i*3]))
                {
                    
                    otv[i]=ss1[(i*3)+2]+' '+ss1[i*3] +' '+ ss1[(i*3)+1];
                }

            }
            Array.Sort(otv);

            foreach (string c in otv)
                stw.WriteLine(c);

          
            stw.Close();
        }
    }
}
