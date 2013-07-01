//********************************************************************************************************
//  author: honpey
//  data: 2013.06.24
//  动态规划 之 0-1背包问题
//
//  问题描述：小明去旅游需要带上一些物品，有五种物品供选择，每种物品的体积、重量、数量、价值如下表所示：
//  ----------------------------------------------------
//  | 物品编号 | 体积/cm^3 | 重量/kg |数量/个 | 价值/元|
//  |     1    |    30     |   3     |   10   |   4    |
//  |     2    |    50     |   8     |   10   |   5    |
//  |     3    |    10     |   2     |   10   |   2    |
//  |     4    |    23     |   5     |   8    |   3    |
//  |     5    |    130    |   20    |   5    |   11   |
//  ----------------------------------------------------
//  现在限制总的体积最多为 500 cm^3,总的重量最多为100kg,请问小明能带上的物品的最大的价值是多少？
//  状态转移方程：f(n,x,y)=maxi{f(n-1,x-i*v[n],y-i*w[n])+i*t[n]}
//
//*********************************************************************************************************
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int A[6][6];
int f[6][501][101];
ifstream inf("input");
ofstream ouf("output");
int path[6];
int dealpackage(int n,int vo,int we)
{
	//处理第n个包中的情况
	if(f[n][vo][we]>0)
		return f[n][vo][we];
	if(vo<0 || we <0 )
	{
		return -1;
	}              
	else if(n==0)
	{
		return 0;
	}
	else
	{
		int Nofn=A[n][3];//第n件物品的件数
		int i;
		int max=0;
		int cur;
		if(Nofn>(vo/A[n][1])) Nofn=vo/A[n][1];
		if(Nofn>(we/A[n][2])) Nofn=we/A[n][2];
		for(i=0;i<=Nofn;i++)
		{
			path[n]=i;
			cur=dealpackage(n-1,vo-i*A[n][1],we-i*A[n][2]);
			if(-1!=cur)
			{
				cur+=i*A[n][4];//递归处理第n-1件物品
				if(cur>max)
				{
					max=cur;
				}
			}
			if(-1==cur)
			{
				break;
			}
		}
		ouf<<path[1]<<" "<<path[2]<<" "<<path[3]<<" "<<path[4]<<" "<<path[5]<<" "<<"state: f("<<n<<","<<vo<<","<<we<<") "<<"---"<<max<<endl;
		f[n][vo][we]=max;
		return max;
	}
}

int main()
{
	cout<<"0-1背包问题"<<endl;
	int m,n;
	inf>>m;//几种物品 行数
	inf>>n;//物品各种指标 列数
	cout<<m<<" "<<n<<endl;
	int i,j;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			inf>>A[i][j];
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"hello world"<<endl;
	ouf<<"A B C D E"<<endl;
	dealpackage(5,500,100);
	cout<<"come here"<<endl;
	cout<<f[5][500][100]<<endl;
	return 1;
	
	
}
