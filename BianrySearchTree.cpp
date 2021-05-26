#include<iostream>
#include<stdio.h>
#include<queue>
#include<stack>
#include<vector>
#include<map>
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

//void generate(int x)
//{
//	Node *p=newnode(x);
//	if(root==NULL)
//		root=p;
//	else if(q.front()->left==NULL)
//		q.front()->left=p;
//	else
//	{
//		q.front()->right=p;
//		q.pop();
//	}
//	q.push(p);	
//}
//
//
//void create(int arr[],int n)
//{
//	for(int i=0;i<n;i++)
//	{
//		generate(arr[i]);
//	}
//}


void generate(Node *t,int x)
{
	Node *r;
	Node* p=newnode(x);
	if(root==NULL)
	{
		root=p;
		return;
	}
	
	while(t!=NULL)
	{
		r=t;
		if(x==t->data)
			return ;
		else if(x<t->data)
		{
			t=t->left;	
		}
		else
			t=t->right;
	}
	
	if(x<r->data)
		r->left=p;
	else
		r->right=p;
	
}

void Create(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		generate(root,a[i]);
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
	cout<<p->data<<" ";
	q.push(p);
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		if(p->left)
		{
			cout<<p->left->data<<" ";
			q.push(p->left);
		}
		if(p->right)
		{
			cout<<p->right->data<<" ";
			q.push(p->right);
		}
	}
}


void zigzag(Node *p)
{
	Node *t;
	stack<Node*> s1,s2;
	s1.push(p);
	while(!s1.empty() || !s2.empty())
	{
		while(!s1.empty())
		{
			t=s1.top();
			s1.pop();
			cout<<t->data<<"->";
			if(t->right)
				s2.push(t->right);
			if(t->left)
				s2.push(t->left);
		}
		
		while(!s2.empty())
		{
			t=s2.top();
			s2.pop();
			cout<<t->data<<"->";
			if(t->left)
				s1.push(t->left);
			if(t->right)
				s1.push(t->right);
		}
	}
}


//Vertical Traversal
void generateVertical(Node *p,int hd,map<int, vector<int> > &m)
{
	if(p==NULL)
		return;
	m[hd].push_back(p->data);
	generateVertical(p->left,hd-1,m);
	generateVertical(p->right,hd+1,m);
}

void Vertical(Node *p)
{
	int hd=0;
	map<int, vector<int> > m;
	generateVertical(p,hd,m);
	map<int, vector<int> >::iterator itr;
	for(itr=m.begin();itr!=m.end();itr++)
	{
		for(int i=0;i<itr->second.size();i++)
			cout<<itr->second[i]<<" ";
		cout<<endl;
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


Node *RSearch(Node *p,int x)
{
	if(p!=NULL)
	{
		if(p->data==x)
			return p;
		else if(x<p->data)
			return RSearch(p->left,x);
		else
			return RSearch(p->right,x);
	}
	return NULL;
}


Node *Search(Node *p,int x)
{
	while(p)
	{
		if(x==p->data)
			return p;
		else if(x<p->data)
			p=p->left;
		else
			p=p->right;
	}
	return NULL;
}

void Insert(Node *p,int x)
{
	Node *t,*r;
	if(p==NULL)
	{
		t=newnode(x);
		t->left=t->right=NULL;
		p=t;
		return ;
	}
	while(p)
	{
		r=p;
		if(x==p->data)
			return ;
		else if(x<p->data)
			p=p->left;
		else
			p=p->right;
	}
	
	t=newnode(x);
	if(x<r->data)
		r->left=t;
	else
		r->right=t;
			
}


Node *RInsert(Node *p,int x)
{
	Node *t;
	if(p==NULL)
	{
		t=newnode(x);
		p=t;

	}
	
	if(x<p->data)
		p->left=RInsert(p->left,x);

	else if(x>p->data)
		p->right=RInsert(p->right,x);	
		
	return p;
	
}




int main()
{
	int arr[]={5,3,7,1,4,6,0,9};
	int x;
	Node *p;
	Create(arr,8);
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
	
	
//	cout<<"Recursive Search"<<endl;
//	cout<<"Enter Number to Search: "<<endl;
//	cin>>x;
//	p=RSearch(root,x);
//	if(p)
//		cout<<p->data<<" is found"<<endl;
//	else
//		cout<<"Element not found";
//		
		
//	cout<<"Iterative Search"<<endl;
//	cout<<"Enter Number to Search: "<<endl;
//	cin>>x;
//	p=Search(root,x);
//	if(p)
//		cout<<p->data<<" is found"<<endl;
//	else
//		cout<<"Element not found";


//	//Iterative Inserting in a BST
//	cout<<"Wanna Insert Something, Insert The key: "<<endl;
//	cin>>x;
//	Insert(root,x);
//	cout<<"LevelOrder : ";
//	levelorder(root);
//	cout<<endl;


//	//Recursive Inserting in a BST
//	cout<<"Wanna Insert Something, Insert The key: "<<endl;
//	cin>>x;
//	RInsert(root,x);
//	cout<<"LevelOrder : ";
//	levelorder(root);
//	cout<<endl;	
	
	
	
	//Zigzag traversal of Tree
	cout<<"Zig Zag tree traversal: "<< endl;
	zigzag(root);
	cout<<endl;


	//Vertical traversal of Tree
	cout<<"Vertical tree traversal: "<< endl;
	Vertical(root);	
	
	return 0;
}
