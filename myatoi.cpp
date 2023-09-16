#include<iostream>
#include<cstring>
//#include<string>
using namespace std;
int main()
{
	
	/*
	THIS IS FOR CONVERSION OF STRING TO CHAR TYPE ARRAY 
	string st1="454";
	char ch[20];
	strcpy(ch,st1.c_str());
	*/
	
	char str[10]="123";
	int x;
	char c;
	long res=0;

	for(int i=0;str[i]!='\0';i++)
	{
		c=str[i];
		x= c-'0';//ascii value of any character - 47
		if(x>=0&&x<=9)
		{
			res=res*10+x;
		}
		else
		{
			cout<<"invalid input ";
			break;
		}
	}
	
	cout<<" myatoi = "<<res;

	

}
