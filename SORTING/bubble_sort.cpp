#include<iostream>
using namespace std;
void bubblesort(int *num,int n)
{
	int temp;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			if(num[j]>num[j+1])
			{
				temp = num[j];
				num[j]=num[j+1];
				num[j+1]=temp;	
			}
		}
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
	int *num;
	int n;
	cout<<"number of elemeents";
	cin>>n;
	num = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	
	
	cout<<" Array before sorting : "<<endl;
	print(num,n-1);
	bubblesort(num,n);
	cout<<endl<<"============================================================"<<endl;
	cout<<"Array after sorting "<<endl;
	print(num,n-1);

}
