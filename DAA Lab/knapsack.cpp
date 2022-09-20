#include <bits/stdc++.h>
using namespace std;

struct Item {
	int value, weight;

	Item(int value, int weight)
	{
		this->value = value;
		this->weight = weight;
	}
};

double fractionalKnapsack(int W, struct Item arr[], int N)
{
    for (int i = 0; i < N ; i++)
        for (int j = 0; j < N-1; j++)
            if ((double)(arr[j].value/arr[j].weight) < (double)(arr[j+1].value/arr[j+1].weight))
                swap(arr[j], arr[j + 1]);

	double finalvalue = 0.0;

	for (int i = 0; i < N; i++) {
		
		if (arr[i].weight <= W) {
			W -= arr[i].weight;
			finalvalue += arr[i].value;
		}

		else {
			finalvalue += arr[i].value * ((double)W / (double)arr[i].weight);
			break;
		}
	}

	return finalvalue;
}

int main()
{
	int W = 50; 
	Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };

	int N = sizeof(arr) / sizeof(arr[0]);

	cout << "Maximum value we can obtain = "
		<< fractionalKnapsack(W, arr, N);
	return 0;
}