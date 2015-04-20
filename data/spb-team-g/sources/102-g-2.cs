using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace solution2
{
    class Program
    {
        static void Main(string[] args)
        {
            args = File.ReadAllLines("merlin.in");

            long count = long.Parse(args[0]);
            args = args[1].Split(' ');

            long[] array = new long[count];
            for (long i = 0; i < count; i++)
            {
                array[i] = long.Parse(args[i]);
            }

            Array.Sort(array);

            long[] table = new long[count];

            long sum = 0;
            for (long i = 0; i < array.Length; i++)
            {
                table[i] = (array[i] * i) - sum;
                sum += array[i];
            }

            sum = 0;
            long counter = 0;
            for (long i = count - 1; i >= 0; i--)
            {
                if (sum >= table[i])
                {
                    break;
                }
                sum += array[i];
                counter++;
            }

            File.WriteAllText("merlin.out", counter.ToString());
        }
    }
}
