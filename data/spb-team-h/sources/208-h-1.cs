using System;
using System.IO;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] namesFromFile = File.ReadAllLines("names.in");
            string[] name, name2;
            int i, j;
            int length = int.Parse(namesFromFile[0]);

            string[] names = new string[length];
            Array.Copy(namesFromFile, 1, names, 0, length);
            
            for (i = 0; i < length; ++i)
            {
                name = names[i].Split(' ');
                for (j = 0; j < length; ++j)
                {
                    if (i == j)
                        continue;
                    name2 = names[j].Split(' ');
                    if (name[1].Equals(name2[0]))
                        names[j] = name2[2] + " " + name2[0] + " " + name2[1];
                }
            }
            Array.Sort(names);
            File.WriteAllLines("names.out", names);
        }
    }
}
