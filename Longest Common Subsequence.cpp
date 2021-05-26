#include<iostream>
#include<string>
using namespace std;

void LCS(string s1,string s2,int x,int y)
{
	int L[x+1][y+1];
	int i,j;
	
	for(i=0;i<=x;i++)
	{
		for(j=0;j<=y;j++)
		{
			if(i==0 || j==0)
				L[i][j]=0;
			else if(s1[i-1]==s2[j-1])
				L[i][j]=L[i-1][j-1]+1;
			else
				L[i][j]=max(L[i-1][j],L[i][j-1]);
		}
	}
	int size=L[x][y];
	int index=L[x][y];
	
	//Printing
	char l[index+1];
	l[index]='\0';
	
	i=x;
	j=y;
	while(i>0 && j>0)
	{
		if(s1[i-1]==s2[j-1])
		{
			l[index-1]=s1[i-1];
			i--;j--;index--;
		}
		else if(L[i-1][j]>L[i][j-1])
			i--;
		else
			j--;
	}
	
	cout<<"The LCS is: "<<l<<endl;
	cout<<"The length of LCS is: "<<size<<endl;
}


int main()
{
	string s1="longest";
	string s2="stone";
	int x=s1.length();
	int y=s2.length();
	LCS(s1,s2,x,y);
	return 0;
 } 
