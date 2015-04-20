using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;

namespace TestCS
{
    class Program
    {
        static void Main(string[] args)
        {
            int a;

            using (StreamReader Sw = new StreamReader("names.in"))
            {
                a = int.Parse(Sw.ReadLine());
            
                string[][]  In = new string[a][];

                for (int t = 0; t < a; t++)
                    In[t] = Sw.ReadLine().Split(' ');



                for(int i = 0; i < a; i++)
                    for(int j = 0; j < 2; j++)
                        for(int k = 0; k < a; k++)
                            for (int l = 0; l < 2; l++)
                            {
                                if(In[i][j] == In[k][l])
                                {
                                    if(j == l)
                                    {}
                                    else if (j == 0)
                                    {
                                        string s;
                                        s = In[i][0];
                                        In[i][0] = In[i][2];
                                        In[i][2] = s;
                                        
                                        s = In[i][1];
                                        In[i][1] = In[i][2];
                                        In[i][2] = s;
                                    }
                                    else if (k == 0)
                                    {
                                        string s;
                                        s = In[k][0];
                                        In[k][0] = In[k][2];
                                        In[k][2] = s;

                                        s = In[k][1];
                                        In[k][1] = In[k][2];
                                        In[k][2] = s;
                                    }
                                }
                            }

                string[] S = new string[a];
                for (int i = 0; i < a; i++)
                    S[i] = In[i][0] + " " + In[i][1] + " " + In[i][2];

                Array.Sort(S);
                using (StreamWriter W = new StreamWriter("names.out"))
                {
                    foreach (string r in S)
                        W.WriteLine(r);   
                }

            }
            

        }
    }
}
