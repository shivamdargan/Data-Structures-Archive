#include <bits/stdc++.h>
using namespace std;

int deno[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
int n = sizeof(deno) / sizeof(deno[0]);

void findMin(int V)
{
	 for (int i = 0; i < n ; i++)
        for (int j = 0; j < n-1; j++)
            if ((deno[j]) > (deno[j+1]))
                swap(deno[j], deno[j + 1]);

	// Initialize result
	int ans[10000];
    int count =0;

	// Traverse through all denomination
	for (int i = n - 1; i >= 0; i--) {

		// Find denominations
		while (V >= deno[i]) {
			V -= deno[i];
			ans[count] = deno[i];
            count++;
		}
	}

	for (int i = 0; i < count; i++)
		cout << ans[i] << " ";
}

int main()
{
	int n;
	cout<< "Enter the value of V: "<< endl;
	cin>> n;
	cout << "Following is minimal number of change for " << n << ": ";
	findMin(n);
	return 0;
}