using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

// (づ°ω°)づﾐ★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜
public class Solver
{
    public object Solve()
    {
        int n = ReadInt();
        int m = ReadInt();
        int mod = ReadInt();
        var a = ReadLines(m);

        var choose = new int[n + 1];
        for (int i = 2; i <= n; i++)
            choose[i] = i * (i - 1) / 2 % mod;

        var count = new int[n];
        foreach (string aa in a)
            for (int j = 0; j < n; j++)
                if (aa[j] == '1')
                    count[j]++;

        var dp = new long[n + 1,n + 1];
        int o = 0, z = 0;
        for (int j = 0; j < n; j++)
            if (count[j] == 1)
                o++;
            else if (count[j] == 0)
                z++;
        dp[z, o] = 1;
        
        for (int i = m; i < n; i++)
        {
            var ndp = new long[n + 1, n + 1];
            for (int zero = 0; zero <= n; zero++)
                for (int one = 0; one <= n; one++)
                    if (dp[zero, one] > 0)
                    {
                        if (zero > 1)
                            ndp[zero - 2, one + 2] = (ndp[zero - 2, one + 2] + choose[zero] * dp[zero, one]) % mod;
                        if (one > 1)
                            ndp[zero, one - 2] = (ndp[zero, one - 2] + choose[one] * dp[zero, one]) % mod;
                        if (zero > 0 && one > 0)
                            ndp[zero - 1, one] = (ndp[zero - 1, one] + zero * one * dp[zero, one]) % mod;
                    }
            dp = ndp;
        }

        return dp[0, 0];

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
        reader = new StreamReader(Console.OpenStandardInput());
        writer = new StreamWriter(Console.OpenStandardOutput());
        //reader = new StreamReader("instruction.in");
        //writer = new StreamWriter("instruction.out");
#endif
        try
        {
            object result = new Solver().Solve();
            if (result != null)
                writer.WriteLine(result);
        }
        catch (Exception ex)
        {
#if DEBUG
            Console.WriteLine(ex);
#else
            Console.WriteLine(ex);
            throw;
#endif
        }
        reader.Close();
        writer.Close();
    }

    #endregion

    #region Read / Write

    private static Queue<string> currentLineTokens = new Queue<string>();

    private static string[] ReadAndSplitLine()
    {
        return reader.ReadLine().Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
    }

    public static string ReadToken()
    {
        while (currentLineTokens.Count == 0)
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

    public static int[][] ReadAndTransposeIntMatrix(int numberOfRows)
    {
        int[][] matrix = ReadIntMatrix(numberOfRows);
        int[][] ret = new int[matrix[0].Length][];
        for (int i = 0; i < ret.Length; i++)
        {
            ret[i] = new int[numberOfRows];
            for (int j = 0; j < numberOfRows; j++)
                ret[i][j] = matrix[j][i];
        }
        return ret;
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

    public static void Write<T>(params T[] array)
    {
        WriteArray(array);
    }

    public static void WriteLines<T>(IEnumerable<T> array)
    {
        foreach (var a in array)
            writer.WriteLine(a);
    }

    #endregion
}