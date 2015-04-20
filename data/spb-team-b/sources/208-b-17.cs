using System;
using System.IO;
using System.Text;

namespace ConsoleApplication3
{
    class Program
    {
        static void Main()
        {
           /* FILE *in, *out;
	int n, i = 1, k;
	in = fopen("chess.in", "r");
	out = fopen("chess.out", "w");
	fscanf(in, "%d\n%d", &n, &k);
	for (; i < n; ++i)
		fscanf(in, " %d", &n);
	fprintf(out, "%d\n", i);
	
	fflush(out);
	return 0;*/
            string[] input = File.ReadAllLines("chess.in");
            int n = int.Parse(input[0]), i, k = n;
            
            string[] ai = input[1].Split(' ');
            int[] a = new int[n];
            
            for(i = 0; i < n; ++i)
            {
                a[i] = int.Parse(ai[i]);
            }
            for(i = 0; i < n; ++i)
            {
                if(a[i] < i)
                {
                    k = i;
                }
            }

            StringBuilder output = new StringBuilder();
            output.Append(k);

            for (i = 1; i <= k; ++i)
	        {
                output.Append("\r\n" + i + " " + i);
	        }
            File.WriteAllText("chess.out", output.ToString());
        }
    }
}
