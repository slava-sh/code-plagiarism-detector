using System;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines("names.in");
            int i, n;
            string[] name;
            bool Vasya = false;

            int length = int.Parse(input[0]);
            string[] names = new string[length];
            Array.Copy(input, 1, names, 0, length);

            // SORT (FIO)

            for (n = 0; n < length; ++n)
            {
                name = names[n].Split(' ');
                for (i = 0; i < length; ++i)
                {
                    if (i == n)
                        continue;
                    if(names[i].Contains(name[0] + " "))
                    {
                        Vasya = true;
                        break;
                    }
                }
                if(Vasya == true)
                {
                    names[n] = name[2] + " " + name[0] + " " + name[1];
                }
                Vasya = false;
            }
            Array.Sort(names);
            File.WriteAllLines("names.out", names);

        }
    }
}
