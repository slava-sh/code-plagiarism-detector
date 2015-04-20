using System;
using System.IO;

namespace ConsoleApplication4
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] file = File.ReadAllLines("seq.in");
            string[] temp = file[0].Split(' ');
            int n = Convert.ToInt32(temp[0]);
            int h = Convert.ToInt32(temp[1]);
            temp = file[1].Split(' ');
            int[] vals = new int[n];
            for(int i = 0; i < n; i++)
            {
                vals[i] = Convert.ToInt32(temp[i]);
            }
            int res = -1;
            for(int i = 0; i < n - h + 1; i++)
            {
                int tempres = 0;
                for(int i2 = 1; i2 <= h; i2++)
                {
                    if (vals[i2 + i - 1] > i2)
                    {
                        tempres = -1;
                        break;
                    }
                    tempres += (i2 - vals[i2 + i - 1]);
                }
                if (tempres != -1 && (res > tempres || res == -1)) res = tempres;
            }
            File.WriteAllText("seq.out", res.ToString());
        }
    }
}
