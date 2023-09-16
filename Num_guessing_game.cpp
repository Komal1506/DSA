#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;
int getguess( int x)
{
	int guess ,c=0;
	cin>>guess;
	if(guess==x)
	{
		return c+1;
	}
	else
	{
		if(guess<x)
		{
			cout<<"To Low ...";
			c=getguess(x);
		}
		else
		{
			cout<<"To High...";
			c=getguess(x);
		}
		return c+1;
	}
}
int main()
{
	int c=0;
	srand(time(NULL));
	int x=	rand()/1000;
	int guess;
	cout<<"enter guess ";
	cout<<" you do it in "<<getguess(x) <<"  attempts";
}
