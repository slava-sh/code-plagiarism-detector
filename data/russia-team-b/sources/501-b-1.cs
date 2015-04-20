using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            long[] param, nums;
            using (StreamReader r = new StreamReader("che.in"))
            {
                param = r.ReadLine().Split().Select(long.Parse).ToArray();
                nums = r.ReadLine().Split().Select(long.Parse).ToArray();
            }
            long count = 0;
            for (long i = 0; i < param[0]; i++)
            {
                for (long j = i + 1; j < param[0]; j++)
                {
                    if (nums[j] - nums[i] > param[1])
                        count++;
                }
            }
            using (StreamWriter w = new StreamWriter("che.out"))
            { w.WriteLine(count); }
        }
    }
}
