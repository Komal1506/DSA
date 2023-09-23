#include<iostream>
using namespace std;
void TowerofHanoi(int n,char S,char D,char I)
{
	if(n<=0)
	{
		return;
	}
	else
	{
		TowerofHanoi(n-1,S,I,D);//this function moves first n-1 disk to source to  intermediate using destination stack
		cout<<S<<"->"<<D<<endl;//moves one disk to source to destination
		TowerofHanoi(n-1,I,D,S);// and this function moves first n-1 disk to intermedite to destination using source stack
	}
}
int main()
{
	int disk;
	cout<<"enter how many disk you want to move ";
	cin>>disk;
	TowerofHanoi(disk,'S','D','I');
}
