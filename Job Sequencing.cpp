#include<iostream> 
#include<algorithm> 
using namespace std; 
  
// A structure to represent a job 
struct Job 
{ 
   char id;     
   int dead;     
   int profit;   
}; 

bool compare(Job a,Job b)
{
	return a.profit>b.profit;
}

void printJobScheduling(Job arr[], int n)
{
	sort(arr,arr+n,compare);
	
	int result[n];
	bool slot[n]={false};
	
	for(int i=0;i<n;i++)
	{
		for(int j=min(n,arr[i].dead)-1;j>=0;j--)
		{
			if(slot[j]==false)
			{
				slot[j]=true;
				result[j]=i;
				break;	
			}	
		}	
	}
	
	for (int i=0; i<n; i++) 
     	if (slot[i])    //To not to overflow after the True as reult is initialized with 0
         cout << arr[result[i]].id << " "; 
}


int main() 
{ 
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, 
                   {'d', 1, 25}, {'e', 3, 15}}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Following is maximum profit sequence of job   "; 
    printJobScheduling(arr, n); 
    return 0; 
} 
