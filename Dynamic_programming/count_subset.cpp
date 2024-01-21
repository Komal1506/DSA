//count how many subset are possible of sum "w"
//this subset sum is possible or not chk
#include<iostream>
using namespace std;
int subset_count(int *,int ,int );
int main()
{
	
	int n,sum;
	int *set;
	cout<<"Enter Total Number of Elements in set: ";
	cin>>n;
	set = new int[n];
	cout<<" Enter "<<n<<" Elements : ";
	for(int i=0 ;i<n;i++)
	{
		cin>>set[i];
	}
	

	cout<<"enter sum of subset which you want to find : ";
	cin>>sum;
	int res;
	res = subset_count(set,n,sum);
	cout<<"Total subset available of sum "<<sum<<" = > "<<res;
	
}
int subset_count(int *weight,int n,int w)
{
	if(w==0)
	{
		return 1;
	}
	if(n==0)
	{
		return 0;
	}
	if(weight[n-1]<=w)
	{
		int res1,res2;
		res1 = subset_count(weight,n-1,w-weight[n-1]);
		res2 = subset_count(weight,n-1,w);
		return res1+res2;
	}
	else
	{
		return subset_count(weight,n-1,w);
	}
}
