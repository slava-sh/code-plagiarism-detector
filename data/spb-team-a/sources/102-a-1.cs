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
        static void Main(string[] args)
        {
            string path = "abcd.";

            args = File.ReadAllLines(path + "in");
            StringBuilder sb = new StringBuilder();

            int count = int.Parse(args[0]);
            for(int i = 1; i <= count; i++)
            {
                int x = int.Parse(args[i]);

                int a = x / 100;
                int b = x % 100;

                if ((a * a + b * b) % 7 == 1) sb.AppendLine("YES");
                else sb.AppendLine("NO");
            }

            File.WriteAllText(path + "out", sb.ToString());
        }
    }
}
