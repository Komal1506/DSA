#include<iostream>
using namespace std;
int knapsack_memo(int *,int *,int,int,int**);
int main()
{
		int n,w;
	int *weight,*profit,**t;
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
	t = new int*[n+1];
	for(int i=0;i<=n;i++)
	{
		t[i]= new int[w+1];
	}
	for(int i=0;i<=n;i++)
	{
		for(int j =0;j<=w;j++)
		{
			t[i][j]=-1;
		}
	}
	int max_profit;
	max_profit = knapsack_memo(weight,profit,n,w,t);
	cout<<"The maximum Profit is : "<<max_profit;
	
}


int knapsack_memo(int *weight,int *profit,int n,int w,int **t)
{
	if(n==0||w==0)
	{
		return 0;
	}
	if(t[n][w]!=-1)
	{
		return t[n][w];
	}
	if(weight[n-1]<=w)
	{
		int res1 ,res2;
		res1 = profit[n-1]+knapsack_memo(weight,profit,n-1,w-weight[n-1],t);
		res2 = knapsack_memo(weight,profit,n-1,w,t);
		t[n][w] = max(res1,res2);
		return t[n][w];
	}
	else
	{
		t[n][w]= knapsack_memo(weight,profit,n-1,w,t);
		return t[n][w];
	}
}
