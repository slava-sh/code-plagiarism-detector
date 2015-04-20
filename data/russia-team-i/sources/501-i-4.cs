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
            List<uint> param,nums;
            using (StreamReader r = new StreamReader("sochi.in"))
            {
                param = r.ReadLine().Split().Select(uint.Parse).ToList();
                nums = r.ReadLine().Split().Select(uint.Parse).ToList();
            }
            long sum;
            if (param[0] == 1)
                sum = nums[0];
            else if (nums.Any(s => s >= 3 * param[1]))
            {
                uint maxf=0, maxs=0;
                try
                {
                    maxf = nums.Where(n => n > 2 * param[1] && n < 3 * param[1]).Max();
                    nums.Remove(maxf);
                    maxs = nums.Where(n => n > 2 * param[1] && n < 3 * param[1]).Max();
                    nums.Remove(maxs);
                }
                catch { }
                nums.RemoveAll(s => s <= 2 * param[1]);
                sum = (nums.Sum(s => s = s) - (nums.Count - 1) * 2 * param[1]);
                if (maxf > 0)
                    sum += maxf - param[1]*2;
                if (maxs > 0)
                    sum += maxs - param[1]*2;
            }
            else { sum = nums.Max(); }
            using (StreamWriter w = new StreamWriter("sochi.out"))
            { w.WriteLine(sum); }
        }
        /*static void Main(string[] args)
        {
            List<uint> param, nums;
            using (StreamReader r = new StreamReader("che.in"))
            {
                param = r.ReadLine().Split().Select(uint.Parse).ToList();
                nums = r.ReadLine().Split().Select(uint.Parse).ToList();
            }
            long count = 0;
            for (int i = 0; i < param[0]; i++)
            {
                if (nums[nums.Count - 1] - nums[i] > param[1])
                {
                    count += param[0] - nums.IndexOf(nums.First(n => n > nums[i] + param[1]));
                    //count += nums.Count(n => n - nums[i] > param[1]);
                    Console.WriteLine(count);
                }
            }
            /*foreach (uint l in nums)
            {
                count += nums.Count(n => n - l > param[1]);
            }/////
            using (StreamWriter w = new StreamWriter("che.out"))
            { w.WriteLine(count); }
        }*/
    }
}




