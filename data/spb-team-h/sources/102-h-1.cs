using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace solution1
{
    class Tree
    {
        public Tree[] SubTrees = new Tree[26];
        public int Count = 0;

        public void Set(string name, int i)
        {
            if(i == name.Length)
            {
                Count++;
                return;
            }

            int pos = name[i] - 'a';
            if (SubTrees[pos] == null) SubTrees[pos] = new Tree();

            SubTrees[pos].Set(name, i + 1);
        }
        public bool IsName(string name, int i)
        {
            if (name.Length == i)
            {
                return Count > 1;
            }
            int pos = name[i] - 'a';
            if (SubTrees[pos] == null) return false;

           return SubTrees[pos].IsName(name, i + 1);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            args = File.ReadAllLines("names.in");

            int count = int.Parse(args[0]);

            Tree tree = new Tree();
            string[,] data = new string[count, 3];

            for(int i = 1; i <= count; i++)
            {
                string[] subArg = args[i].Split(' ');

                data[i - 1, 0] = subArg[0];
                data[i - 1, 1] = subArg[1];
                data[i - 1, 2] = subArg[2];

                tree.Set(subArg[0].ToLower(), 0);
                tree.Set(subArg[1].ToLower(), 0);
                tree.Set(subArg[2].ToLower(), 0);
            }

            string[] fullNames = new string[count];
            for(int i = 0; i < count; i++)
            {
                string name = data[i, 0].ToLower();
                bool isName = tree.IsName(name, 0);

                if (isName)
                    fullNames[i] = string.Format("{2} {0} {1}", data[i, 0], data[i, 1], data[i, 2]);
                else
                    fullNames[i] = string.Format("{0} {1} {2}", data[i, 0], data[i, 1], data[i, 2]);
            }

            Array.Sort(fullNames);

            File.WriteAllLines("names.out", fullNames);
        }
    }
}
