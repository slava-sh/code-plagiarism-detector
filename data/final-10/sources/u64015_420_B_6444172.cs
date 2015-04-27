using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

public class Solver
{
    public object Solve()
    {
        int n = ReadInt();
        int m = ReadInt();

        int[] id = new int[m];
        int?[] status = new int?[n];

        int cand = -1;
        for (int i = 0; i < m; i++)
        {
            bool action = ReadToken() == "+";
            id[i] = ReadInt() - 1;
            if (status[id[i]] == null)
            {
                status[id[i]] = action ? 1 : 2;
                if (!action)
                    cand = id[i];
            }
        }
        if (cand == -1)
            cand = id[0];

        var set = new SortedSet<int>(Enumerable.Range(1, n).Where(i => status[i - 1] == null));
        bool[] on = Enumerable.Range(0, n).Select(i => status[i] == 2).ToArray();
        int onCount = status.Count(s => s == 2);
        int step;
        for (step = 0; step < m; step++)
        {
            if (id[step] == cand)
            {
                if (on[cand] && onCount > 1)
                    break;
            }
            else if (!on[cand])
                    break;
            on[id[step]] = !on[id[step]];
            if (on[id[step]])
                onCount++;
            else
                onCount--;
        }
        if (step == m)
            set.Add(cand + 1);

        writer.WriteLine(set.Count);
        WriteArray(set);

        return null;
    }

    #region Main

    protected static TextReader reader;
    protected static TextWriter writer;

    static void Main()
    {
#if DEBUG
        reader = new StreamReader("..\\..\\input.txt");
        writer = Console.Out;
        //writer = new StreamWriter("..\\..\\output.txt");
#else
        reader = Console.In;
        writer = Console.Out;
#endif
        try
        {
            object result = new Solver().Solve();
            if (result != null)
            {
                writer.WriteLine(result);
            }
        }
        catch (Exception ex)
        {
#if DEBUG
            Console.WriteLine(ex);
#else
            throw;
#endif
        }
        reader.Close();
        writer.Close();
    }

    #endregion

    #region Read/Write

    private static Queue<string> currentLineTokens = new Queue<string>();

    private static string[] ReadAndSplitLine()
    {
        return reader.ReadLine().Split(new[] {' ', '\t'}, StringSplitOptions.RemoveEmptyEntries);
    }

    public static string ReadToken()
    {
        if (currentLineTokens.Count == 0)
            currentLineTokens = new Queue<string>(ReadAndSplitLine());
        return currentLineTokens.Dequeue();
    }

    public static int ReadInt()
    {
        return int.Parse(ReadToken());
    }

    public static long ReadLong()
    {
        return long.Parse(ReadToken());
    }

    public static double ReadDouble()
    {
        return double.Parse(ReadToken(), CultureInfo.InvariantCulture);
    }

    public static int[] ReadIntArray()
    {
        return ReadAndSplitLine().Select(int.Parse).ToArray();
    }

    public static long[] ReadLongArray()
    {
        return ReadAndSplitLine().Select(long.Parse).ToArray();
    }

    public static double[] ReadDoubleArray()
    {
        return ReadAndSplitLine().Select(s => double.Parse(s, CultureInfo.InvariantCulture)).ToArray();
    }

    public static int[][] ReadIntMatrix(int numberOfRows)
    {
        int[][] matrix = new int[numberOfRows][];
        for (int i = 0; i < numberOfRows; i++)
            matrix[i] = ReadIntArray();
        return matrix;
    }

    public static string[] ReadLines(int quantity)
    {
        string[] lines = new string[quantity];
        for (int i = 0; i < quantity; i++)
            lines[i] = reader.ReadLine().Trim();
        return lines;
    }

    public static void WriteArray<T>(IEnumerable<T> array)
    {
        writer.WriteLine(string.Join(" ", array));
    }

    #endregion
}