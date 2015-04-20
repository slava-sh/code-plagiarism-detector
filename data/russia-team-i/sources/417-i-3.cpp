#include <fstream>
using namespace std;

int main()
	{
		int n, d, r;
		ifstream inf("sochi.in");
		inf >> n >> d;
		if(n==1)
			{
				inf >> r;
				inf.close();
				ofstream ouf("sochi.out");
				ouf << r;
				ouf.close();
			}
		if(n==2)
			{
				int t1, t2;
				inf >> t1 >> t2;
				inf.close();
				ofstream ouf("sochi.out");
				ouf << max(max(t1, t2), t1+t2-2*d);
				ouf.close();
			}
		if(n>2)
			{
				int t1=0, t2=0, sum=0, m=0;
				for(int i=0;i<n;i++)
					{
						inf >> r;
						if(m<r)
							m=r;
						if(r>=3*d)
							{
								if(sum==0)
									sum=r;
								else
									sum=sum+r-2*d;
							}
						if(r<3*d && r>=2*d)
							{
								if(r>t1)
									t1=r;
								else
									{
										if(r>t2)
											t2=r;
									}
							}
					}
				ofstream ouf("sochi.out");
				if(sum==0 && t2!=0)
					ouf << t2+t1-2*d;
				if(sum==0 && t2==0 && t1!=0)
					ouf << t1;
				if(sum==0 && t1==0 && t2==0)
					ouf << m;
				if(sum!=0 && t2!=0)
					ouf << sum+t1+t2-4*d;
				if(sum!=0 && t1!=0 && t2==0)
					ouf << sum+t1-2*d;
				if(sum!=0 && t1==0)
					ouf << sum;
				ouf.close();
			}
		return 0;
	}
