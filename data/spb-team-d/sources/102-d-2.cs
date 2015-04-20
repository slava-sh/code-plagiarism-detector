using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace solution
{
    class Tree
    {
        public int x = 0;
        public bool reverse = false;

        public Tree Right;
        public Tree Left;

        public int Begin = 0;
        public int End = int.MaxValue;

        public int GetValue(int i)
        {
            if(Begin == End && Begin == i)
            {
                if (reverse) 
                    return -this.x;
                return 
                    this.x;
            }

            int center = (Begin + End) / 2;
            int v = 0;
            if(i <= center)
            {
                if (Left != null) v = Left.GetValue(i);
            }
            else
            {
                if (Right != null) v = Right.GetValue(i);
            }

            bool plus = ((i - Begin) % 2 == 0) ^ reverse;

            if (plus) v += this.x;
            else v -= this.x;

            return v;
        }
        public void Set(int l, int r, int x, bool reverse)
        {
            if(l == Begin && r == End)
            {
                this.x += x;
                this.reverse = reverse;
                return;
            }

            int center = (Begin + End) / 2;
            if(r <= center)
            {
                if(Left == null)
                {
                    Left = new Tree();
                    Left.Begin = Begin;
                    Left.End = center;
                }
                Left.Set(l, r, x, reverse);
                return;
            }
            if(l > center)
            {
                if(Right == null)
                {
                    Right = new Tree();
                    Right.Begin = center + 1;
                    Right.End = End;
                }
                Right.Set(l, r, x, reverse);
                return;
            }
            if (Left == null)
            {
                Left = new Tree();
                Left.Begin = Begin;
                Left.End = center;
            }
            if (Right == null)
            {
                Right = new Tree();
                Right.Begin = center + 1;
                Right.End = End;
            }
            

            Left.Set(l, center, x, reverse);
            Right.Set(center + 1, r, x, reverse ^ ((center - l) % 2 == 0));
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            string path = "dunes.";
            args = File.ReadAllLines(path + "in");

            string[] subArgs = args[0].Split(' ');

            int n = int.Parse(subArgs[0]);
            int m = int.Parse(subArgs[1]);

            int[] l = new int[n];
            int[] r = new int[n];
            int[] x = new int[n];


            for (int i = 1; i <= n; i++)
            {
                subArgs = args[i].Split(' ');
                l[i - 1] = int.Parse(subArgs[0]);
                r[i - 1] = int.Parse(subArgs[1]);
                x[i - 1] = int.Parse(subArgs[2]);
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 1 + n; i <= n + m; i++)
            {
                int v = int.Parse(args[i]);
                int res = 0;

                for(int j = 0; j < l.Length; j++)
                {
                    if(v <= r[j] && v >= l[j])
                    {
                        bool reverse = ((v - l[j]) & 1) == 0;
                        if (reverse) res += x[j];
                        else res -= x[j];
                    }
                }
                sb.AppendLine(res.ToString());

            }
            File.WriteAllText(path + "out", sb.ToString());

            /*
            Tree tree = new Tree();
            tree.Begin = 1;
            tree.End = 1000000000;

            for(int i = 1; i <= n; i++)
            {
                subArgs = args[i].Split(' ');
                int l = int.Parse(subArgs[0]);
                int r = int.Parse(subArgs[1]);
                int x = int.Parse(subArgs[2]);

                tree.Set(l, r, x, false);
            }

            StringBuilder sb = new StringBuilder();
            
            for(int i = 1 + n; i <= n + m; i++)
            {
                int x = int.Parse(args[i]);
                sb.AppendLine(tree.GetValue(x).ToString());
            }

            File.WriteAllText(path + "out", sb.ToString());
            */
        }
    }
}
