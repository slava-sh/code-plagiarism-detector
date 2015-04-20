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
            StreamReader sr = new StreamReader("sochi.in");
            int[] nd = sr.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int[] ass = sr.ReadLine().Split(' ').Select(int.Parse).ToArray();           
            sr.Close();
            Array.Sort(ass);
            int s=0;
            int i=ass.Length-1;
            bool isAdd = false;
            while(i>=0) 
            {
                if (ass[i] >= 3 * nd[1])
                {
                    s += ass[i] - 2 * nd[1] ;
                }
                else if (ass[i] >= nd[1]*2)
                {
                    isAdd=true;
                    if (i == 0)
                    {
                        s += ass[i] - nd[1];
                        s += nd[1];
                        break;
                    }
                    else
                    {
                        s += (ass[i] - nd[1]) + (ass[i - 1] - nd[1]);
                        break;
                    }
                        
                }
                i--;
            }
            if (isAdd == false)
                s += nd[1] * 2;
            StreamWriter sw = new StreamWriter("sochi.out");
            sw.Write(s);
            sw.Close();
            //Console.Write(result);
        }
    }
}
