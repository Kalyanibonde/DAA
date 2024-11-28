#include <iostream>
#include <algorithm>
using namespace std;

// Structure to represent an item with a value and weight
struct Item
{
    int value, weight;

   	// Constructor to initialize value and weight of the item
    Item(int value, int weight)
    {
        this->value = value;
        this->weight = weight;
    }
};

// Comparator function to sort items by value-to-weight ratio in decreasing order
bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / (double)a.weight; 				            // Ratio of item a
    double r2 = (double)b.value / (double)b.weight;				                // Ratio of item b
    return r1 > r2;                             				                // Sort in descending order of ratio
}

// Function to calculate maximum value that can be obtained in fractional knapsack
double fractionalKnapsack(int W, struct Item arr[], int N)
{
    // Sort items based on value-to-weight ratio
    sort(arr, arr + N, cmp);

    double finalvalue = 0.0; 				                                    // Variable to store the final maximum value

   	// Loop through all items
    for (int i = 0; i < N; i++)
    {
       	// If the item can fit in the knapsack, take it fully
        if (arr[i].weight <= W)
        {
            W -= arr[i].weight;         					                    // Reduce the knapsack capacity
            finalvalue += arr[i].value; 					                    // Add the full item's value
        }
        else56
        {
            // If the item can't fully fit, take the fraction of it
            finalvalue += arr[i].value * ((double)W / (double)arr[i].weight); 	// Take fraction of value
            break;                                                           	// Knapsack is full, exit loop
        }
    }

    return finalvalue; 					                                        // Return the maximum value obtained
}   

int main()
{
    int W = 20;                                               			        // Total capacity of the knapsack
    Item arr[] = {{10, 3}, {20, 5}, {21, 5}, {30, 8}, {16, 4}}; 	            // Array of items (value, weight)
								
    int N = sizeof(arr) / sizeof(arr[0]);					                    // Calculate number of items

   	// Output the maximum value obtainable in the knapsack
    cout << "Maximum value we can obtain = " << fractionalKnapsack(W, arr, N) << endl;

    return 0;
}
