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
            StreamReader sr = new StreamReader("travel.in");
            List<Point> Ts = new List<Point>();
            int[] n = sr.ReadLine().Split(' ').Select(int.Parse).ToArray();
            string[] field = new string[n[1]];
            Point start = new Point(-1,-1);
            for (int i = 0; i < n[1]; i++)
            {
                field[i] = sr.ReadLine();
                for (int j = 0; j < field[i].Length; j++)
                {
                    if (field[i][j] == 'T')
                        Ts.Add(new Point(i, j));
                    if (field[i][j] == 'V')
                       start  = new Point(i, j);
                }
            }
            int visited = 0;
            string ans = "";
            while (visited < n[2])
            {
                Point closest = GetMin(start, ref Ts);
                if (closest.x - start.x > 0)
                {
                    ans += G(Math.Abs(closest.x - start.x), "E");
                }
                else if(closest.x - start.x < 0) ans += G(Math.Abs(closest.x - start.x), "W");
                if (closest.y - start.y > 0)
                {
                    ans += G(Math.Abs(closest.y - start.y), "S");
                }
                else if (closest.y - start.y < 0) ans += G(Math.Abs(closest.y - start.y), "N");                
                start = closest;
                visited++;
            }            
            StreamWriter sw = new StreamWriter("travel.out");
            sw.Write(ans);
            sw.Close();
           //Console.ReadKey();
        }
        static string G(int n, string l)
        {
            string s = "";
            for (int i = 0; i < n; i++)
            {
                s += l;
            }
            return s;
        }
        static Point GetMin(Point start, ref List<Point> Ts)
        {
            double min = double.MaxValue;
            Point closest = new Point(-1, -1);
            foreach (Point a in Ts)
            {
                if (min > D(start, a) && D(start,a)!=0)
                {
                    min = D(start, a);
                    closest = a;
                }                
            }
            return closest;
        }
        static double D(Point start, Point end)
        {
            return Math.Sqrt(Math.Pow(start.x - end.x, 2) + Math.Pow(start.y - end.y, 2));
        }
    }

    class Point
    {
        public int y;
        public int x;
        public Point(int _y, int _x)
        {
            y = _y;
            x = _x;
        }
    }
}
