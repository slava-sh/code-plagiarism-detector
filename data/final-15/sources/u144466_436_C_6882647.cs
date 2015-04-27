// Submitted by Silithus @ Macau
using System;
using System.IO;
using System.Collections.Generic;
using CCF_XOI;

namespace CodeForces
{
	class CF436_ZeptoCodeRush_C
	{
		int N, M, K;
		int[] father;
		string[,] level;
		bool[,] used;
		List<one_road> Road;
		XOI xoi;

		struct one_road
		{
			public int u, v, d;
			public static int CompareByD(one_road x, one_road y)
			{
				return x.d.CompareTo(y.d);
			}
		}

		int compare(int x, int y)
		{
			int i, j, cnt = 0;

			for (i = 0; i < N; i++)
				for (j = 0; j < M; j++)
					if (level[x, i][j] != level[y, i][j])
						cnt++;

			return cnt;
		}

		int find_father(int u)
		{
			if (father[u] != u)
				father[u] = find_father(father[u]);
			return father[u];
		}

		void DFS(int u, int father)
		{
			xoi.o.WriteLine("{0} {1}", u, father);

			for (int v = 1; v <= K; v++)
			{
				if (v != father && used[u, v])
					DFS(v, u);
			}
		}

		public void Solve(XOI _xoi)
		{
			int NM, W, i, j, d;

			this.xoi = _xoi;
			N = xoi.ReadInt();
			M = xoi.ReadInt();
			K = xoi.ReadInt();
			W = xoi.ReadInt();
			NM = N * M;
			Road = new List<one_road>();
			father = new int[K + 1];
			used = new bool[K + 1, K + 1];
			level = new string[K + 1, N];

			for (i = 1; i <= K; i++)
			{
				father[i] = i;
				for (j = 0; j < N; j++)
					level[i, j] = xoi.ReadString();

				for (j = i - 1; j >= 1; j--)
				{
					d = compare(i, j) * W;
					if (d < NM)
						Road.Add(new one_road { u = j, v = i, d = d });
				}
			}
			Road.Sort(one_road.CompareByD);

			int fu, fv, ans = 0;
			foreach (one_road r in Road)
			{
				fu = find_father(r.u);
				fv = find_father(r.v);

				if (fu != fv)
				{
					father[fv] = fu;
					ans += r.d;
					used[r.u, r.v] = used[r.v, r.u] = true;
				}
			}
			for (i = 1; i <= K; i++)
				if (find_father(i) == i)
					ans += NM;

			xoi.o.AutoFlush = false;
			xoi.o.WriteLine(ans);
			for (i = 1; i <= K; i++)
				if (father[i] == i)
					DFS(i, 0);
			xoi.o.Flush();
		}
	}

	class CodeForcesMain
	{
		static void Main(string[] args)
		{
			(new CF436_ZeptoCodeRush_C()).Solve(new XOI());
		}
	}
}

namespace CCF_XOI
{	// version 2014.02.07
	class XOI
	{
		protected StreamReader sr;
		public StreamWriter o;
		protected Queue<string> buf = new Queue<string>();
		public bool EOF = false;

		public XOI()
		{
			this.sr = new StreamReader(Console.OpenStandardInput());
			this.o = new StreamWriter(Console.OpenStandardOutput());
			this.o.AutoFlush = true;
		}

		public XOI(string in_path, string out_path)
		{
			this.sr = new StreamReader(in_path);
			this.o = new StreamWriter(out_path);
			this.o.AutoFlush = true;
		}

		public int ReadInt()
		{
			string s = this.GetNext();
			if (s == null) return -1;
			else return Int32.Parse(s);
		}

		public long ReadLong()
		{
			string s = this.GetNext();
			if (s == null) return -1;
			else return Int64.Parse(s);
		}

		public double ReadDouble()
		{
			string s = this.GetNext();
			if (s == null) return -1;
			else return Double.Parse(s);
		}

		public string ReadString()
		{
			string s = this.GetNext();
			return (s == null ? null : s);
		}

		public string ReadLine()
		{	// I will ignore current buffer and read a new line
			string s = "";
			while (s == "" && !this.EOF)
			{
				s = sr.ReadLine();
				this.EOF = (s == null);
			}
			return (this.EOF ? null : s);
		}

		protected string GetNext()
		{
			if (buf.Count == 0)
			{
				while (buf.Count == 0 && !this.EOF)
				{
					string s = sr.ReadLine();
					if (s == null)
						this.EOF = true;
					else
						foreach (string ss in s.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries))
							buf.Enqueue(ss);
				}
			}

			return (this.EOF ? null : buf.Dequeue());
		}
	}
}
