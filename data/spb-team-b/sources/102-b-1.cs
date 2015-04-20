using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace solution1
{
    class Program
    {
        static void Main(string[] args)
        {
            args = File.ReadAllLines("chess.in");
            int count = int.Parse(args[0]);
            args = args[1].Split(' ');

            int[] array = new int[count];
            for (int i = 0; i < count; i++)
            {
                array[i] = int.Parse(args[i]);
            }
            int max = 0;
            for(int i = 0; i < array.Length; i++)
            {
                if(i < array[i])
                {
                    max++;
                }
            }
            StringBuilder sb = new StringBuilder();
            sb.AppendLine(max.ToString());
            for(int i = 0; i < max; i++)
            {
                sb.AppendLine((i + 1) + " " + (i + 1));
            }

            File.WriteAllText("chess.out", sb.ToString());
        }
    }
}
