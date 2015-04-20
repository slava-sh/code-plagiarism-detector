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
        static void Search(long[] array, long[] res, long[] ab, int pos)
        {
            if (pos == array.Length)
            {
                if(Math.Abs(res[0] - res[1]) > Math.Abs(ab[0] - ab[1]))
                {
                    res[0] = ab[0];
                    res[1] = ab[1];
                }
                return;
            }
            ab[0] *= array[pos];
            Search(array, res, ab, pos + 1);
            ab[0] /= array[pos];
            ab[1] *= array[pos];
            Search(array, res, ab, pos + 1);
            ab[1] /= array[pos];
            
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

            long c = 1;

            foreach(var af in aFactor.ToArray())
            {
                long x = af.Value;
                long y = 0;
                if (bFactor.TryGetValue(af.Key, out y))
                {

                    long delta = Math.Min(x, y);

                    c *= Pow(af.Key, delta);

                    aFactor[af.Key] -= delta;
                    bFactor[af.Key] -= delta;
                }
            }

            List<long> values = new List<long>();
            foreach(var af in aFactor.ToArray())
            {
                if(af.Value == 0) continue;
                values.Add(Pow(af.Key, af.Value));
            }
            foreach(var bf in bFactor.ToArray())
            {
                if(bf.Value == 0) continue;
                values.Add(Pow(bf.Key, bf.Value));
            }

            long a1 = c;
            long b1 = c;

            long[] array = values.ToArray();
            Array.Sort(array);

            long[] ab = new long[] { c, c };
            long[] res = new long[] { 0, long.MaxValue };

            Search(array, res, ab, 0);

            a1 = res[0];
            b1 = res[1];

            File.WriteAllText("gcm.out", Math.Min(a1, b1) + " " + Math.Max(a1, b1));
        }
    }
}
