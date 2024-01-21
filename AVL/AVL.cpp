//Q_01  AVL 
#include<iostream>
using namespace std;
class Node
{
	public:
		
	int data;
	Node *left;
	Node *right;
	Node()
	{
		data=0;
		left=NULL;
		right=NULL;
	}
	Node(int a)
	{
		data=a;
		left=NULL;
		right=NULL;
	}
};
class AVL
{
	Node *root;
	public:
	AVL()
	{
		root=NULL;
	}
	void create()
	{
		cout<<" keep intering data ";
		int x;
		while(1)
		{
		cin>>x;
		if(x==0)
		{
			break;
		}
		root=insert_rec(root,x);
		}
	}
	Node * getroot()
	{
		return root;
	}
	Node * insert_rec(Node *,int );
	void inorder(Node *);
	int height(Node *t);
	int balfac(Node *t);
	Node * rotateright(Node *t);
	Node * rotateleft(Node *t);
	Node *leftright(Node *t);
	Node *rightleft(Node *t);
	Node * delete_rec(Node *t,int x);
	Node * findmin(Node *);
	
	void deletenode (int x)
	{
		root= delete_rec(root,x);
	}
};
Node * AVL::findmin(Node *t)
{
	if(t==NULL)
	{
		return NULL;
	}
	while(t->left!=NULL)
	{
		t=t->left;
	}
	return t;
}
Node *AVL::delete_rec(Node *t,int x)
{
	if(t==NULL)
	{
		cout<<"not found";
		return NULL;
	}
	if(x<t->data)
	{
		t->left= delete_rec(t->left,x);
		if(balfac(t)==-2)
		{
			if(balfac(t->right)<=0)
			{
				t= rotateleft(t);
			}
			else
			{
				t= rightleft(t);
			}
		}
		return t;
	}
	if(x>t->data)
	{
		t->right=delete_rec(t->right,x);
		if(balfac(t)==2)
		{
			if(balfac(t->left)>=0)
			{
				t=rotateright(t);
			}
			else
			{
				t=leftright(t);
			}
		}
		return t;
	}
	//data found 
	if(t->left==NULL&&t->right==NULL)
	{
		cout<<" successfully deleted ";
		delete t;
		return NULL;
	}
	if(t->left==NULL)
	{
			cout<<" successfully deleted ";
		Node *p=t->right;
		delete t;
		return p;
	}
	if(t->right==NULL)
	{
			cout<<" successfully deleted ";
		Node *p= t->left;
		delete t;
		return p;
	}
	//node having both children
	
	Node *min =findmin(t->right);
	t->data=min->data;
	t->right=delete_rec(t->right,min->data);
		if(balfac(t)==2)
		{
			if(balfac(t->left)>=0)
			{
				t=rotateright(t);
			}
			else
			{
				t=leftright(t);
			}
		}
	return t;
}
Node *AVL::rotateleft(Node *t)
{
	cout<<" rotate left rotation of "<<t->data<<endl;
	Node *p=t->right;
	t->right=p->left;
	p->left=t;
	return p;
}
Node * AVL::rotateright(Node *t)
{
	cout<<" rotate right rotation of "<<t->data<<endl;
	Node *p=t->left;
	t->left=p->right;
	p->right=t;
	return p;
}
Node * AVL::leftright(Node *t)
{
	cout<<" left right rotation of "<<t->data<<endl;
	
	t->left=rotateleft(t->left);
	t=rotateright(t);
	return t;
}
Node *AVL::rightleft(Node *t)
{
	cout<<" right left rotation of "<<t->data<<endl;
	t->right=rotateright(t->right);
	t=rotateleft(t);
	return t;
}
int AVL::balfac(Node *t)
{
	if(t==NULL)
	{
		return 0;
	}
	else
	{
		int hl=0,hr=0;
		hl= height(t->left);
		hr=height(t->right);
		return hl-hr;
	}
}
int AVL::height(Node  * t)
{
	if(t==NULL)
	{
		return 0;
	}
	else
	{
		return max(height(t->left),height(t->right))+1;
	}
}
void AVL::inorder(Node *t)
{
	if(t==NULL)
	{
		return ;
	}
	else
	{
		inorder(t->left);
		cout<<"  "<<t->data;
		cout<<"   bal fact of this node "<<balfac(t)<<endl;
		inorder(t->right);
	}
}


Node * AVL::insert_rec(Node * t,int x)
{
	if(t==NULL)
	{
		t= new Node(x);
		return t;
	}
	if(x<t->data)
	{
		t->left= insert_rec(t->left,x);
		if(balfac(t)==2)
		{
				cout<<" rebalancing of "<<t->data<<endl;
			if(x<t->left->data)
			{
				t=rotateright(t);
			}
			else
			{
				t=leftright(t);
			}
		}
		return t;
	}
	if(x>t->data)
	{
		t->right= insert_rec(t->right,x);
		
		if(balfac(t)==-2)
		{
			cout<<" rebalancing of "<<t->data<<endl;
			if(x>t->right->data)
			{
				t=rotateleft(t);
			}
			else
			{
				t= rightleft(t);
			}
		}
		return t;
	}
	cout<<" duplicate entry enter again ";
	return t;
}


int main()
{
	int x;
	AVL obj;
	obj.create();
	obj.inorder(obj.getroot());
	cout<<" enter which node you want to delete ";
	cin>>x;
	obj.deletenode(x);
	cout<<" after deletion "<<endl;
	obj.inorder(obj.getroot());
}
