//WAP to implement Stack using linkedList.
#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node *next;
		
		Node()
		{
			data=0;
			next=NULL;
		}
		Node(int a)
		{
			data=a;
			next=NULL;
		}
		~Node()
		{
			cout<<"node deleted";
		}
};
class Stack
{
	Node *top;
	public:
		Stack()
		{
			top=NULL;
		}
		void push(int x);
		int pop();
};
int main()
{
	Stack obj;
	obj.push(23);
	obj.push(34);
	obj.push(50);
	cout<<"\npopped data = "<<obj.pop();
}
void Stack::push(int x)
{
	Node *p=new Node(x);
	if(top==NULL)
	{
		top=p;
	}
	else
	{
		p->next=top;
		top=p;
	}
}

int Stack::pop()
{
	if(top==NULL)
	{
		cout<<"empty stack can't pop";
	}
	else
	{
		int x;
		Node *p=top;
		x=p->data;
		top=top->next;
		delete p;
		return x;
	}
}
