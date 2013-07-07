/*
 * ===================================================================================
 *       Filename:  birge.cpp
 *
 *    Description:  

 *        Version:  1.0
 *        Created:  2013年07月07日 17时21分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *  算法过程中应该保证：尽量不分组，这也是Maxweight的用武之地。
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

double A[100][3];//第i辆车的重量[0]和最大的速度[1]
double state[100][100];//从i到j的最小时间
double maxweight;
double len;
double getMinTime(int x,int y)
{
	if(state[x][y]!=0)
		return state[x][y];
	
	int i;
	double sum=0;
	double sum1,sum2;
	double max=0;
	//首先计算该队列是否需要分裂如果需要分裂
	int pos=x;
	while(pos!=y+1)
	{
		sum+=A[pos][0];
		if(A[pos][2]>max)
			max=A[pos][2];
		pos++;
	}
	if(sum<=maxweight)
	{
		state[x][y]=max;
		printf("state<%d,%d>: %lf\n",x,y,max);
		return max;
	}
	double min;
	min=100000;
	for(i=x;i<y;i++)
	{
		sum1=getMinTime(x,i);
		sum2=getMinTime(i+1,y);
		sum=sum1+sum2;
		if(sum<min)
			min=sum;
	}
	state[x][y]=min;
	printf("state<%d,%d>: %lf\n",x,y,max);
	return min;
}
int main()
{
	FILE *file;
	file=fopen(".//input3","r");
	int n;
	fscanf(file,"%lf %lf %d",&maxweight,&len,&n);
	int i,j;
	for(i=0;i<n;i++)
	{
		fscanf(file,"%lf",&A[i][0]);
		fscanf(file,"%lf",&A[i][1]);
		A[i][2]=len/A[i][1];
	}
	//初始化状态转化矩阵
	for(i=0;i<n;i++)
	{
		state[i][i]=A[i][2];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%lf ",state[i][j]);
		}
		printf("\n");
	}

    printf("min is %lf\n",getMinTime(0,n-1)*60);
	return 0;
}
