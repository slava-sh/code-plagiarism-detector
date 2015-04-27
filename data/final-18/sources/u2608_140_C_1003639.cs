using System;
using System.Collections.Generic;


class Scanner
{
    string[] s;
    int i;

    char[] cs = new char[] { ' ' };

    public Scanner()
    {
        s = new string[0];
        i = 0;
    }

    public string next()
    {
        if (i < s.Length) return s[i++];
        s = Console.ReadLine().Split(cs, StringSplitOptions.RemoveEmptyEntries);
        i = 0;
        return s[i++];
    }

    public int nextInt()
    {
        return int.Parse(next());
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

}

class Myon
{
    Scanner cin;
    Myon() { }

    public static void Main()
    {
        new Myon().calc();
    }

    int h, w;
    string[] s;
    int[,] num;
    int[,] usedcount;
    int count;
    int prenum = 0;

    void calc()
    {
        Scanner cin = new Scanner();
        int n = cin.nextInt();
        int[] r = new int[n];
        int i, j;
        Dictionary<int, int> dic = new Dictionary<int, int>();
        for (i = 0; i < n; i++)
        {
            r[i] = cin.nextInt();
            if (!dic.ContainsKey(r[i])) dic[r[i]] = 0;
            dic[r[i]]++;
        }
        if (dic.Count < 3)
        {
            Console.WriteLine(0);
            return;
        }
        long MAX = (long)1e10;
        Heap h = new Heap(0);
        foreach (var item in dic)
        {
            h = meld(h, new Heap(MAX * item.Value + item.Key));
        }
        int[,] ret = new int[n, 3];
        int retnum = 0;
        for (j = 0; ; j++)
        {
            long[] num = new long[3];
            for (i = 0; i < 3; i++)
            {
                num[i] = h.val;
                h = meld(h.r, h.l);
            }
            if (num[2] < MAX) break;
            int[] nums = new int[3];
            for (i = 0; i < 3; i++)
            {
                nums[i] = (int)(num[i] % MAX);
                num[i] -= MAX;
            }
            for (i = 0; i < 3; i++)
            {
                h = meld(h, new Heap(num[i]));
            }
            Array.Sort(nums);
            Array.Reverse(nums);
            for (i = 0; i < 3; i++)
            {
                ret[j, i] = nums[i];
            }
            retnum++;
        }
        Console.WriteLine(retnum);
        for (i = 0; i < retnum; i++)
        {
            Console.WriteLine("{0} {1} {2}", ret[i, 0], ret[i, 1], ret[i, 2]);
        }
    }

    class Heap
    {
        public Heap l, r;
        public int s;
        public long val;

        public Heap(long a)
        {
            val = a;
        }
    }

    
    Heap meld(Heap a, Heap b)
    {
        if (a == null) return b;
        if (b == null) return a;
        if (a.val < b.val)
        {
            Heap temp = a;
            a = b;
            b = temp;
        }
        a.r = meld(a.r, b);
        if (a.l == null || a.l.s < a.r.s)
        {
            Heap temp = a.l;
            a.l = a.r;
            a.r = temp;
        }
        a.s = ((a.r == null) ? 0 : a.r.s) + 1;
        return a;
    }
     
}
