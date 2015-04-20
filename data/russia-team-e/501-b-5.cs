using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Threading.Tasks;

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
            Parallel.For (0, param[0],i=>
            {
                if (nums[nums.Length-1]-nums[i]>param[1])
                {for (long j = i + 1; j < param[0]; j++)
                {
                    if (nums[j] - nums[i] > param[1])
                    {
                        count += param[0] - j;
                        break;
                    }
                }
                }
            });
            using (StreamWriter w = new StreamWriter("che.out"))
            { w.WriteLine(count); }
        }
    }
}
