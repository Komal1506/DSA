//this subset sum is possible or not chk
#include<iostream>
using namespace std;
int subset_sum_rec(int *weight,int n,int w);
int main()
{
	
	int n,w;
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
	cin>>w;
	int res;
	res = subset_sum_rec(set,n,w);
	if(res==1)
	{
		cout<<"Subset is Possible ";
	}
	else
	{
		cout<<"This subset is not possible";
	}
	
}
int subset_sum_rec(int *weight,int n,int w)
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
		res1 = subset_sum_rec(weight,n-1,w-weight[n-1]);
		res2 = subset_sum_rec(weight,n-1,w);
		return res1|res2;
	}
	else
	{
		return subset_sum_rec(weight,n-1,w);
	}
}
