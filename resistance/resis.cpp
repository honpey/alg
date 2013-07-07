//-------------------------------------------
//对于给定的n个自然数和另外的b个自然数
//n用这b个数中若干个（可以重复）的和表示，
//求表示方法的总数
//输入：
//第1行整数b
//第2行b个整数，以空格分开
//第3行至第3+n行，每一行表示一个待表示的数字
//-------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#define N 20
int A[N];
int b;
double state[100000][20];
int path[N];
int getNO(int n,int s)
{
	int i;
	if(state[n][s]!=0)
		return state[n][s];
	if(n<=0)
		return 1;
	if(s<=0)
	{

		if(n%A[s]==0)
		{
			path[s]=n/A[s];
			
			printf("state<Num: %d,Step: %d> : ",n,s);	
			printf(" [ 1 ] ");
			printf("\n");
			return 1;

		}
		else{

			return 0;
		}
	}
	else
	{
		int max=n/(A[s]);
		int sum=0;
		for(i=0;i<=max;i++)
		{
			sum+=getNO(n-i*A[s],s-1);//保证ｎ>=0
            path[n]=i;//第n个决策选择的数量----
		}
		state[n][s]=sum;
		
		printf("state<Num: %d,Step: %d> : ",n,s);

		printf(" [ %d ] ",sum);
		printf("\n");
		return sum;
	}
}
int main()
{
	FILE *file;
	int n;
	file=fopen(".//input","r");
	fscanf(file,"%d",&b);
	int i;
	for(i=0;i<b;i++)
	{
		fscanf(file,"%d",&A[i]);
		printf("%d ",A[i]);
	}
	printf("\n");
	//边界条件初始化：
	int j;
	for(i=0;i<20;i++)
	{
		state[0][i]=1;
	}
	for(i=0;i<100000;i++)
	{
		//if(state[i][0]%A[0]==0)
			state[i][0]=1;
		//else
		//	state[i][0]=0;

	}
	while(fscanf(file,"%d",&n)>0)
	{
		printf("%d is processing\n",n);
	
		printf("%d's NO is %d\n",n,getNO(n,b-1));
	}
	return 0;
}
