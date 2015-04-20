using System;
using System.IO;

namespace ConsoleApplication6
{
    class Program
    {
        static Int64 evklid(Int64 a, Int64 b)
        {
            if (b == 0)
                return a;
            else
                return evklid(b, a % b);
        }

        static void Main(string[] args)
        {
            StreamReader str = new StreamReader("gcm.in");
            StreamWriter stw = new StreamWriter("gcm.out");
            string[] s = str.ReadLine().Split(' ');
            Int64 ev1,j=0;
            Int32 a = Convert.ToInt32(s[0]), b = Convert.ToInt32(s[1]);
            Int64 p = a * b;
            if (a > b)
                ev1 = evklid(a, b);
            else ev1 = evklid(b, a);
            for (Int64 i=Convert.ToInt64(Math.Sqrt(p));i>0; i--)
            {
                if (p % i == 0)
                {
                    if (ev1 == evklid(p / i, i))
                    {
                        j = i;
                        i = 0;
                    }

                }
            }
            stw.WriteLine("{0} {1}",j, p / j);

        }
    }
}
