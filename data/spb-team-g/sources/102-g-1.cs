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

            int count = int.Parse(args[0]);
            args = args[1].Split(' ');

            int[] array = new int[count];
            for(int i = 0; i < count; i++)
            {
                array[i] = int.Parse(args[i]);
            }

            Array.Sort(array);

            int[] table = new int[count];

            int sum = 0;
            for(int i = 0; i < array.Length; i++)
            {
                table[i] = (array[i] * i) - sum;
                sum += array[i];
            }

            sum = 0;
            int counter = 0;
            for (int i = count - 1; i >= 0; i--)
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
