using System;
using System.IO;

namespace ConsoleApplication5
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader str = new StreamReader("dunes.in");
            StreamWriter stw = new StreamWriter("dunes.out");
            string[]s = str.ReadLine().Split(' ');

           
            UInt64 f=Convert.ToUInt64(s[0]), ff = Convert.ToUInt64(s[1]);
            Int64 poriv=0;
            UInt64[] l = new UInt64[f];
            UInt64[] r = new UInt64[f];
            Int64[] x = new Int64[f];

            for (UInt64 i = 0; i < f; i++)
            {
                string[]ss=str.ReadLine().Split(' ');
                l[i] = Convert.ToUInt64(ss[0]);
                r[i] = Convert.ToUInt64(ss[1]);
                x[i] = Convert.ToInt64(ss[2]);
            }

            for (UInt64 i = 0; i < ff; i++)
            {
                poriv = 0;
                UInt64 need = Convert.ToUInt64(str.ReadLine());
                for (UInt64 j = 0; j < f; j++)
                {
                    if (need <= r[j] && need >= l[j])
                    {
                        if (l[j] % 2 == need % 2)
                        {
                            poriv += x[j];
                        }
                        else
                        {
                            poriv -= x[j];
                        }
                    }
                }


                stw.WriteLine(poriv);
            }
            stw.Close();
            str.Close();
        }
    }
}
