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
            if(counter == 0)
            {
                File.WriteAllText("gcm.out", a + " " + b);
                return;
            }

            int a1 = int.MaxValue;
            int b1 = int.MaxValue;

            foreach (var af in aFactor)
            {
                if (af.Key < a1 && af.Value == 1) a1 = af.Key;
            }
            foreach (var bf in bFactor)
            {
                if (bf.Key < b1 && bf.Value == 1) b1 = bf.Key;
            }

            int delta1 = Math.Abs(a / a1 - b * a1);
            int delta2 = Math.Abs(b / b1 - a * b1);

            int aRes = 0;
            int bRes = 0;

            if(delta1 < delta2)
            {
                aRes = Math.Min(a / a1, b * a1);
                bRes = Math.Max(a / a1, b * a1);
            }
            else
            {
                aRes = Math.Min(b / b1, a * b1);
                bRes = Math.Max(b / b1, a * b1);
            }

            File.WriteAllText("gcm.out", aRes + " " + bRes);
        }
    }
}
