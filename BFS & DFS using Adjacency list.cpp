#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<map>
#include<stack> 

using namespace std;

stack<int> st;
queue<int> q;
map<int, list<int> > graph;


void Create(vector< vector<int> > edge)
{
	int i,j;
	for(i=0;i<edge.size();i++)
	{
		for(j=0;j<edge[i].size();j++)
		{
			graph[i].push_back(edge[i][j]);
		}
	}
}

void Show()
{
	map<int, list<int> >::iterator itr;
	list<int>:: iterator itr2;	
	for(itr=graph.begin();itr!=graph.end();itr++)
	{
		cout<<"Element connected to "<<itr->first<<":"<<endl;
		for(itr2=itr->second.begin();itr2!=itr->second.end();itr2++)
		{
			cout<<*itr2<<" ";
		}	
		cout<<endl;
	}
}




void BFS(int start)
{
	int size=graph.size();
	list<int>::iterator itr;
	int i=start,j;
	bool visited[size];
	for(j=0;j<size;j++)
		visited[j]=false;
		
	cout<<i<<" ";
	visited[i]=true;
	q.push(i);
	while(!q.empty())
	{
		i=q.front();
		q.pop();
		
		for(itr=graph[i].begin();itr!=graph[i].end();itr++)
			if(visited[*itr]==false)
			{
				cout<<*itr<<" ";
				visited[*itr]=true;
				q.push(*itr);
			}
		
	}
}

int size=graph.size();
bool visits[4]={false}; //Pass the arrayy size as parameter

void DFS(int start)
{
	int j;
	list<int>::iterator itr;
	if(visits[start]==false)
	{
		cout<<start<<" ";
		visits[start]=true;
		for(itr=graph[start].begin();itr!=graph[start].end();itr++)
		{
			if(visits[*itr]==false)
				DFS(*itr);
		}
	}
}


void ItrDFS(int start)
{
	int size=graph.size();
	bool visited[size];
	for(int i=0;i<size;i++)
		visited[i]=false;
	int x;
	st.push(start);
	list<int>::iterator itr;
	while(!st.empty())
	{
		x=st.top();
		st.pop();
		if(visited[x]==false)
			{
				cout<<x<<" ";
				visited[x]=true;
			}
		
		for(itr=graph[x].begin();itr!=graph[x].end();itr++)
		{
			if(visited[*itr]==false)
				st.push(*itr);
		}
	}
}

int main()
{
	//No. of vertices =6 and so dimension if 7 because we dont considered 0
	vector< vector<int> > edge{ {1,2}, {1,9} ,{2,1},{2,3},{2,8},{2,9},{3,2},{3,4},{3,6},{4,3},{4,5},{5,4},{6,3},{6,7},{7,6},{8,2},{8,9}, {9,1}, {9,8} };
	Create(edge);
	Show();
	
//	cout<<"BFS:"<<endl;		
//	BFS(2);  //Scond parameter is starting vertex
//	cout<<endl;
////	BFS(G,4,7);	
////	cout<<endl;
////	BFS(G,5,7);
////	cout<<endl;
////	
//	cout<<"DFS:"<<endl;
//	ItrDFS(2);
	
	return 0;
}
