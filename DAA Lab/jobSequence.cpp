#include <algorithm>
#include <iostream>
using namespace std;

struct Job {

	string id; // Job Id
	int dead; // Deadline of job
	int profit; // Profit if job is over before or on
				
};


void printJobScheduling(Job arr[], int n)
{
	
	 for (int i = 0; i < n ; i++)
        for (int j = 0; j < n-1; j++)
            if ((double)(arr[j].profit) < (double)(arr[j+1].profit))
                swap(arr[j], arr[j + 1]);

	int result[n];
	bool slot[n]; 

	for (int i = 0; i < n; i++)
		slot[i] = false;

	for (int i = 0; i < n; i++) {

		for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
			
			if (slot[j] == false) {
				result[j] = i; 
				slot[j] = true; 
				break;
			}
		}
	}
    int resultantProfit = 0;
	// Print the result
	for (int i = 0; i < n; i++)
    {
		if (slot[i])
        {
            cout<< arr[result[i]].id << " "<< "\t Profit: " <<arr[result[i]].profit<<endl;
            resultantProfit += arr[result[i]].profit;
        }
	 }	
     cout<<"Total Profit: " << resultantProfit<<endl;	
}

// Driver's code
int main()
{
	Job arr[] = { 
                    { "Job 1", 2, 100 },
                    { "Job 2", 1, 19 },
                    { "Job 3", 2, 27 },
                    { "Job 4", 1, 25 },
                    { "Job 5", 3, 15 } 
                };

	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Following is maximum profit sequence of jobs "
			"\n";

	printJobScheduling(arr, n);
	return 0;
}
