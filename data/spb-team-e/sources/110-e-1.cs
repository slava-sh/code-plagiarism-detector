using System;
using System.IO;

namespace ConsoleApplication4
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader str = new StreamReader("game.in");
            StreamWriter stw = new StreamWriter("game.out");

            Int64 n,m,lp,rp,lv,rv,op=0,ov=0;
            Int64 kolobsh=0,kolp=0,kolv=0;
            string[] ss = str.ReadLine().Split(' ');
            n = Convert.ToInt64(ss[0]);
            m = Convert.ToInt64(ss[1]);

            string[] ss1 = str.ReadLine().Split(' ');
            lp = Convert.ToInt64(ss1[0]);
            rp = Convert.ToInt64(ss1[1]);

            string[] ss2 = str.ReadLine().Split(' ');
            lv = Convert.ToInt64(ss2[0]);
            rv = Convert.ToInt64(ss2[1]);


            string[] s = str.ReadLine().Split(' ');
            for (Int64 i = 0; i < n; i++)
            {
                Int64 ne = Convert.ToInt64(s[i]);

                if (ne>=lv && ne <=rv && ne>=lp && ne<=rp)
                {
                    kolobsh++;
                } else if (ne>=lv && ne<=rv) 
                {
                    kolv++;
                }else if (ne>=lp && ne <=rp)
                {
                    kolp++;
                }
            }

            if (m <= kolobsh)
            {
                if (m % 2 == 1)
                    stw.WriteLine("Petya");
                else
                    stw.WriteLine("Draw");
            }
            else
            {
                Int64 razn = m - kolobsh;
                
                if (kolobsh % 2==1)
                
                {

                
                    op++;

                    while (razn > 0 && (kolv>0 || kolp>0))
                    {
                        if (kolv>0)
                        {
                            kolv--;
                            ov++;
                            razn--;
                        }
                        if (kolp > 0 && razn > 0)
                        {
                            kolp--;
                            op++;
                            razn--;
                        }
                 
                    }
                } else
                {
                    while (razn > 0 && (kolv > 0 || kolp > 0))
                    {
                        if (kolp > 0)
                        {
                            kolp--;
                            op++;
                            razn--;
                        }
                        if (kolv > 0 && razn > 0)
                        {
                            kolv--;
                            ov++;
                            razn--;
                        }

                    }
                }

                if (op > ov)
                    stw.WriteLine("Petya");
                else if (op == ov)
                    stw.WriteLine("Draw");
                else stw.WriteLine("Vasya");

               
            }

            stw.Close();
            str.Close();
    }
    }
}
