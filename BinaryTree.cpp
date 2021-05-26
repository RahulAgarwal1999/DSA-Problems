#include<iostream>
#include<stdio.h>
#include<queue>
#include<stack>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
}*root=NULL;

Node* newnode(int x)
{
//	if(x==0)
//		return NULL;
	Node *p=new Node;
	p->data=x;
	p->left=p->right=NULL;
	return p;
}

queue<Node*> q;

void generate(int x)
{
	Node *p=newnode(x);
	if(root==NULL)
		root=p;
	else if(q.front()->left==NULL)
		q.front()->left=p;
	else
	{
		q.front()->right=p;
		q.pop();
	}
	if(p->data!=0)
		q.push(p);	
}


void create(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		generate(arr[i]);
	}
}

void preorder(Node *tra)
{
	Node *p=tra;
	stack<Node*>st;
	while(p || !st.empty())
	{
		if(p!=NULL)
		{
			
			cout<<p->data<<"-";
			st.push(p);
			p=p->left;
		}
		else{
			p=st.top();
			st.pop();
			p=p->right;
		}
	}
}


void inorder(Node *tra)
{
	Node *p=tra;
	stack<Node*>st;
	while(p || !st.empty())
	{
		if(p!=NULL)
		{
			st.push(p);
			p=p->left;
		}
		else{
			p=st.top();
			st.pop();
			cout<<p->data<<"-";
			p=p->right;
		}
	}
}

void levelorder(Node *root)
{
	queue<Node*>q;
	Node *p=root;
	q.push(p);
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		cout<<p->data<<" ";
		if(p->left)
		{
//			cout<<p->left->data<<" ";
			q.push(p->left);
		}
		if(p->right)
		{
//			cout<<p->right->data<<" ";
			q.push(p->right);
		}
	}
}


int Count(Node* p)
{
	int x,y;
	if(p)
	{
		x=Count(p->left);
		y= Count(p->right);
		return x+y+1;
	}
	return 0;
}


int Count2Deg(Node* p)
{
	int x,y;
	if(p)
	{
		x=Count2Deg(p->left);
		y= Count2Deg(p->right);
		if(p->left && p->right)
			return x+y+1;
		else
			return x+y;
	}
	return 0;
}


int Sum(Node* p)
{
	int x,y;
	if(p)
	{
		x=Sum(p->left);
		y= Sum(p->right);
		return x+y+p->data;
	}
	return 0;
}

int Height(Node* p)
{
	int x,y;
	if(p)
	{
		x=Height(p->left);
		y= Height(p->right);
		if(x>y)
			return x+1;
		else
			return y+1;
	}
	return 0;
}

int main()
{
	int arr[]={1,2,3,0,9,10,8};
	create(arr,7);
	cout<<"Preorder : ";
	preorder(root);
	cout<<endl;
	cout<<"Inorder : ";
	inorder(root);
	cout<<endl;
	cout<<"LevelOrder : ";
	levelorder(root);
	cout<<endl;
	cout<<"Number of Nodes: "<<Count(root)<<endl;
	cout<<"Number of Nodes with Degree 2: "<<Count2Deg(root)<<endl;
	cout<<endl;
	cout<<"Sum of all nodes: "<<Sum(root)<<endl;
	cout<<"Heigt of Tree: "<<Height(root)<<endl;
	return 0;
}
