#include <bits/stdc++.h>

using namespace std; 

// Structure represents an activity having start time and finish time. 
struct Activity 
{ 
    int start, finish; 
}; 


void print_Max_Activities(Activity arr[], int n) 
{ 
    // Sort activities according to finish time 
	 for (int i = 0; i < n ; i++)
        for (int j = 0; j < n-1; j++)
            if ((arr[j].finish) > (arr[j+1].finish))
                swap(arr[j], arr[j + 1]);

	cout<< "Following activities are selected With \n"; 

    // Select the first activity
    int i = 0; 
    cout<<"Start Time, Finish Time"<<endl;
	cout<< "(" <<arr[i].start<< ", " <<arr[i].finish << ")\n"; 

    // Consider the remaining activities from 1 to n-1 
    for (int j = 1; j < n; j++) 
    { 
    	// Select this activity if it has start time greater than or equal
    	// to the finish time of previously selected activity
      	if (arr[j].start>= arr[i].finish) 
      	{	 
			cout<< "(" <<arr[j].start<< ", "<<arr[j].finish << ") \n"; 
			i = j; 
      	} 
    } 
} 

// Driver program 
int main() 
{ 
    int n;
    cout<<"Enter The Number Of Activities" <<endl;
    cin>>n;
    Activity arr[n];
	for(int i=0; i<=n-1; i++)
	{
		cout<<"Enter the start and end time of "<<i+1<<" activity \n";
		cin>>arr[i].start>>arr[i].finish;
    }

	print_Max_Activities(arr, n); 
    return 0; 
}