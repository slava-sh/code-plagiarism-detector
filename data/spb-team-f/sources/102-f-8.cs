using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace solution
{
    class Program
    {
        static Dictionary<long, long> Factorization(long x)
        {
            Dictionary<long, long> res = new Dictionary<long, long>();
            for (long i = 2; i * i <= x; i++)
            {
                long counter = 0;
                while (x % i == 0)
                {
                    x /= i;
                    counter++;
                }
                if (counter != 0)
                    res[i] = counter;
            }
            if(x != 1)
            {
                res[x] = 1;
            }
            return res;
        }
        static long Pow(long x, long pow)
        {
            if (pow == 0) return 1;
            if (pow % 2 == 0) return Pow(x * x, pow / 2);
            else return Pow(x * x, pow / 2) * x;
        }
        static void Main(string[] args)
        {
            args = File.ReadAllText("gcm.in").Split(' ');
            long a = long.Parse(args[0]);
            long b = long.Parse(args[1]);

            Dictionary<long, long> res1 = new Dictionary<long, long>();
            Dictionary<long, long> res2 = new Dictionary<long, long>();

            Dictionary<long, long> aFactor = Factorization(a);
            Dictionary<long, long> bFactor = Factorization(b);

            foreach(var af in aFactor.ToArray())
            {
                long x = af.Value;
                long y = 0;
                if (bFactor.TryGetValue(af.Key, out y))
                {

                    long delta = Math.Min(x, y);

                    aFactor[af.Key] -= delta;
                    bFactor[af.Key] -= delta;
                }
            }
            
            long min = Math.Abs(a - b);
            while (true)
            {
                bool minChanged = false;
                foreach (var af in aFactor.ToArray())
                {
                    if (af.Value == 0) continue;

                    long x = Pow(af.Key, af.Value);
                    if (Math.Abs(x * b - a / x) < min)
                    {
                        a /= x;
                        b *= x;
                        min = Math.Abs(a - b);

                        aFactor[af.Key] = 0;
                        bFactor[af.Key] = af.Value;

                        minChanged = true;
                    }
                }
                foreach (var bf in bFactor.ToArray())
                {
                    if (bf.Value == 0) continue;

                    long x = Pow(bf.Key, bf.Value);
                    if (Math.Abs(b / x - a * x) < min)
                    {
                        a *= x;
                        b /= x;

                        aFactor[bf.Key] = bf.Value;
                        bFactor[bf.Key] = 0;

                        min = Math.Abs(a - b);
                        minChanged = true;
                    }
                }
                if (!minChanged) break;
            }

            File.WriteAllText("gcm.out", Math.Min(a, b) + " " + Math.Max(a, b));
        }
    }
}
