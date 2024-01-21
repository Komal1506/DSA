//selection sort 
#include<iostream>
using namespace std;
void print(int *arr,int n)
{
	if(n==-1)
	{
		return;
	}
	else
	{
		print(arr,n-1);
		cout<<"  "<<*(arr+n);
	}
}
void swap( int *p,int t1,int t2 )
{
	int temp;
	temp = p[t1];
	p[t1]=p[t2];
	p[t2]= temp;
}
void selectionsort(int *arr,int n)
{
	int min;
	for(int i = 0;i<n;i++)
	{
		min =i;
		for(int j=i+1;j<=n;j++)
		{
			if(*(arr+min)>arr[j])
			{
				min =j;
			}
		}
		if(min !=i)
		{
			swap(arr,min,i);
		}
	}
}
int main()
{
	int *arr,n;
	cout<<"enter num of elements in array ";
	cin>>n;
	arr= new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>*(arr+i);
	}
	print(arr,n-1);
	selectionsort(arr,n-1);
	print(arr,n-1);
}
