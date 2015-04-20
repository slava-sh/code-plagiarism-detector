using System;
using System.IO;

namespace ApplicationF
{
    class Program
    {
        static void Main()
        {
            Console.WriteLine(DateTime.Now);
            
            long a, b, x, y, nodab, nokab, nodxy, nokxy;
            
            string[] input = File.ReadAllText("gcm.in").Split(' ');
            Int64.TryParse(input[0], out a);
            Int64.TryParse(input[1], out b);
            nodab = NOD(a, b);
            nokab = NOK(a, b, nodab);

            for(y = 1; y < 1000000000; ++y)
                for(x = 1; x + y < 1000000000; ++x)
                {
                    nodxy = NOD(x, x + y);
                    nokxy = NOK(x, x + y, nodxy);
                    if(nodab == nodxy && nokab == nokxy)
                    {
                        File.WriteAllText("gcm.out", x + " " + (x + y));
                        return;
                    }
                }

            Console.WriteLine(DateTime.Now);
            Console.ReadKey();
        }

        static long NOD(long a, long b)
        {
            long max = 1, temp, n = a<b?a:b;
            long sqr = (long)Math.Sqrt(n) + 1;
            for(int i = 1; i <= sqr; ++i)
            {
                temp = n / i;
                if (a % temp == 0 && b % temp == 0)
                    return temp;
                if (a % i == 0 && b % i == 0)
                    max = i;
            }
            return max;
        }

        static long NOK(long a, long b, long nod)
        {
            return a * b / nod;
        }
    }
}
