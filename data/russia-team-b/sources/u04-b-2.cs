using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("che.in");
            long[] n = sr.ReadLine().Split(' ').Select(long.Parse).ToArray();
            long[] s = sr.ReadLine().Split(' ').Select(long.Parse).ToArray();
            long result = 0;
            bool noSolution = false;
            sr.Close();
            for (int i = 0; i < n[0]; i++)
            {
                if (noSolution)
                    break;
                for (int j = i + 1; j < n[0]; j++)
                {
                    if (s[j] - s[i] > n[1])
                    {
                        result += n[0] - j;
                        break;
                    }
                    if (j == n[0] - 1)
                        noSolution = true;
                }
            }
            StreamWriter sw = new StreamWriter("che.out");
            sw.Write(result);
            sw.Close();
            //Console.Write(result);
        }
    }
}
