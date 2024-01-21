#include<iostream>
using namespace std;

int partition(int *arr,int low ,int up)
{
	int pivot,p,q,temp;
	p= low+1;
	pivot = arr[low];
	q=up;
	while(true)
	{
		if(p<=up&&arr[p]<=pivot)
		{
			p++;
		}
		if(arr[q]>pivot)
		{
			q--;
		}
		if(p<q)
		{
			temp = arr[p];
			arr[p]= arr[q];
			arr[q]=temp;
		}
		else
		{
			break;
		}
	}
		temp = arr[q];
		arr[q]= arr[low];
		arr[low]=temp;
	
	return q;
}
void quicksort(int *arr,int low ,int up)
{
	if(low<up)
	{
		int k = partition(arr,low,up);
		quicksort(arr,low,k-1);
		quicksort(arr,k+1,up);
	}
}
void print(int *arr,int n)
{
	if(n==-1)
	{
		return;
	}
	else
	{
		print(arr,n-1);
		cout<<arr[n]<<"  ";
	}
}
int main()
{
	int *arr;
	int n;
	cout<<"enter num of ele";
	cin>>n;
	arr= new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>*(arr+i);
	}
	cout<<" Array before sorting : "<<endl;
	print(arr,n-1);
	quicksort(arr,0,n-1);
	cout<<endl<<"============================================================"<<endl;
	cout<<"Array after sorting "<<endl;
	print(arr,n-1);

}
