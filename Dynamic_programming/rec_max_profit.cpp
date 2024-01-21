#include<iostream>
using namespace std;
int knapsack_rec(int *,int *,int,int);
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
	max_profit = knapsack_rec(weight,profit,n,w);
	cout<<"The maximum Profit is : "<<max_profit;
}
int knapsack_rec(int *weight,int *profit,int n,int w)
{
	if(n==0||w==0)
	{
		return 0;
	}
	if(weight[n-1]<=w)
	{
		int res1,res2;
		res1 = profit[n-1]+knapsack_rec(weight,profit,n-1,w-weight[n-1]);
		res2 = knapsack_rec(weight,profit,n-1,w);
		return max(res1,res2);
	}
	else
	{
		return knapsack_rec(weight,profit,n-1,w);
	}
}
