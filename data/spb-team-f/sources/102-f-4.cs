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
        static Dictionary<int, int> Factorization(int x)
        {
            Dictionary<int, int> res = new Dictionary<int, int>();
            for (int i = 2; i * i <= x; i++)
            {
                int counter = 0;
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
        static void Main(string[] args)
        {
            args = File.ReadAllText("gcm.in").Split(' ');
            int a = int.Parse(args[0]);
            int b = int.Parse(args[1]);

            Dictionary<int, int> res1 = new Dictionary<int, int>();
            Dictionary<int, int> res2 = new Dictionary<int, int>();

            Dictionary<int, int> aFactor = Factorization(a);
            Dictionary<int, int> bFactor = Factorization(b);

            int counter = 0;
            foreach(var af in aFactor.ToArray())
            {
                int x = af.Value;
                int y = 0;
                if (bFactor.TryGetValue(af.Key, out y))
                {

                    int delta = Math.Min(x, y);

                    aFactor[af.Key] -= delta;
                    bFactor[af.Key] -= delta;
                    counter++;
                }
            }
            
            int min = Math.Abs(a - b);
            foreach (var af in aFactor)
            {
                if (af.Value != 1) continue;

                int x = af.Key;
                if (Math.Abs(x * b - a / x) < min)
                {
                    a /= x;
                    b *= x;
                    min = Math.Abs(a - b);
                }
            }
            foreach(var bf in bFactor)
            {
                if (bf.Value != 1) continue;

                int x = bf.Key;
                if (Math.Abs(b / x - a * x) < min)
                {
                    a *= x;
                    b /= x;
                    min = Math.Abs(a - b);
                }
            }

            File.WriteAllText("gcm.out", Math.Min(a, b) + " " + Math.Max(a, b));
        }
    }
}
