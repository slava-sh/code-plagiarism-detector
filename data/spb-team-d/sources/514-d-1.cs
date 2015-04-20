using System;
using System.IO;
using System.Collections.Generic;

namespace ConsoleApplication3
{
    class Program
    {
        public class Wind
        {
            public int Start;
            public int End;
            public int Power;
            public Wind(string row)
            {
                string[] temp = row.Split(' ');
                Start = Convert.ToInt32(temp[0]);
                End = Convert.ToInt32(temp[1]);
                Power = Convert.ToInt32(temp[2]);
            }

            public bool InWind(int Sector)
            {
                return Start <= Sector && Sector <= End;
            }
        }
        static void Main(string[] args)
        {
            List<Wind> Winds = new List<Wind>();
            string[] file = File.ReadAllLines("dunes.in");
            if (File.Exists("dunes.out")) File.Delete("dunes.out");
            string[] temp = file[0].Split(' ');
            int WindCount = Convert.ToInt32(temp[0]);
            int TestCount = Convert.ToInt32(temp[1]);
            for(int i = 0; i < WindCount; i++)
                Winds.Add(new Wind(file[i + 1]));

            for(int i = 0; i < TestCount; i++)
            {
                int res = 0;
                int sector = Convert.ToInt32(file[WindCount + 1 + i]);
                for(int i2 = 0; i2 < WindCount; i2++)
                {
                    if(Winds[i2].InWind(sector))
                    {
                        res += (Winds[i2].Power * (((Winds[i2].Start % 2) == (sector % 2)) ? 1 : -1));
                    }
                }
                File.AppendAllText("dunes.out", res.ToString() + "\r\n");
            }
            
        }
    }
}
