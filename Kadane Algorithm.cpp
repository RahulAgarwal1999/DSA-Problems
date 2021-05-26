#include<iostream>
using namespace std;

int main()
{
	int a[]={4,-3,-2,2,3,1,-2,-3,4,2,-6,-3,-1,3,1,2};
	int n=15;
	int i;
	int max_so_far,max_ending_here,start,end,s;
	max_ending_here=0;
	max_so_far=a[0];
	start=end=s=0;
	
	for(i=0;i<=n;i++)
	{
		max_ending_here+=a[i];
		if(max_ending_here>max_so_far)
		{
			max_so_far=max_ending_here;
			start=s;
			end=i;
		}
		if(max_ending_here<0)
		{
			max_ending_here=0;
			s=i+1;
		}
	}
	
	cout<<"Max subarray sum is: "<<max_so_far<<endl;
	cout<<"It starts from index "<<start<<" to "<<end<<endl;
	return 0;
}
