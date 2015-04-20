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
            args = File.ReadAllLines("game.in");

            string[] subArgs = args[0].Split(' ');

            int n = int.Parse(subArgs[0]);
            int m = int.Parse(subArgs[1]);

            subArgs = args[1].Split(' ');

            int pL = int.Parse(subArgs[0]);
            int pR = int.Parse(subArgs[1]);

            subArgs = args[2].Split(' ');

            int vL = int.Parse(subArgs[0]);
            int vR = int.Parse(subArgs[1]);

            int pCount = 0;
            int vCount = 0;
            int pvCount = 0;

            subArgs = args[3].Split(' ');
            for (int i = 0; i < n; i++)
            {
                int h = int.Parse(subArgs[i]);

                bool pF = (h >= pL && h <= pR);
                bool vF = (h >= vL && h <= vR);

                if (pF && vF) pvCount++;
                else if (pF) pCount++;
                else if (vF) vCount++;
            }

            int pRes = 0;
            int vRes = 0;

            bool pAct = true;

            while(pvCount != 0 && m > 0)
            {
                m--;
                if (pAct)
                {
                    pRes++;
                    pAct = false;
                    pvCount--;
                    continue;
                }
                else
                {
                    vRes++;
                    pAct = true;
                    pvCount--;
                }
            }

            while (pCount + vCount > 0 && m > 0)
            {
                m--;
                if (pAct)
                {
                    if (pCount > 0)
                    {
                        pRes++;
                        pCount--;
                    }
                    pAct = false;
                    continue;
                }
                else
                {
                    if (vCount > 0)
                    {
                        vRes++;
                        vCount--;
                    }
                    pAct = true;
                }
            }

            string winner = pRes > vRes ? "Petya" : "Vasya";
            if (pRes == vRes) winner = "Draw";

            File.WriteAllText("game.out", winner);
        }
    }
}
