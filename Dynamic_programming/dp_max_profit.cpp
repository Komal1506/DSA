#include<iostream>
using namespace std;
int knapsack_dp(int *,int *,int,int);
int main()
{
		int n,w;
	int *weight,*profit;
	cout<<"Enter Total Number of Elements : ";
	cin>>n;
	weight = new int[n];
	profit = new int[n];
	cout<<" Enter "<<n<<" Weights : ";
	for(int i=0 ;i<n;i++)
	{
		cin>>weight[i];
	}
	cout<<"enter "<<n<<" Profits : ";
	for(int i=0;i<n;i++)
	{
		cin>>profit[i];
	}
	cout<<"enter capacity of knapsack : ";
	cin>>w;
	int max_profit;
	max_profit = knapsack_dp(weight,profit,n,w);
	cout<<"The maximum Profit is : "<<max_profit;
	
}


int knapsack_dp(int *weight,int *profit,int n,int w)
{
	int **t;
	t = new int*[n+1];
	for(int i=0;i<=n;i++)
	{
		t[i]= new int[w+1];
	}
	for(int i=0;i<=w;i++)
	{
		t[0][i]=0;
	}
	for(int i=0;i<=n;i++)
	{
		t[i][0]=1;
	}
	int res1,res2;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(weight[i-1]<=j)
			{
				res1 = profit[i-1]+t[i-1][j-weight[i-1]];
				res2 = t[i-1][j];
				t[i][j]=max(res1,res2);
			}
			else
			{
				t[i][j]=t[i-1][j];
			}
		}
	}
	return t[n][w];
}
