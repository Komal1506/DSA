#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<" enter number of elements ";
	cin>>n;
	int *weight;
	weight = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>weight[i];
	}
	int w;
	cout<<"enter the capacity : ";
	cin>>w;
	subset_count(weight,n,w);
	
	
}
