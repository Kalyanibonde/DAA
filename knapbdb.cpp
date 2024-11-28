#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Helper function to find the maximum of two values
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Backtracking solution for 0/1 Knapsack
int knapsackBacktrack(vector<int>& weights, vector<int>& values, int W, int n) {
    if (n == 0 || W == 0) return 0; // Base case

    if (weights[n - 1] > W)
        return knapsackBacktrack(weights, values, W, n - 1); // Skip the current item

    // Consider including or excluding the current item
    return max(values[n - 1] + knapsackBacktrack(weights, values, W - weights[n - 1], n - 1),
               knapsackBacktrack(weights, values, W, n - 1));
}

// Dynamic Programming solution for 0/1 Knapsack
int knapsackDP(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

// Branch and Bound solution for 0/1 Knapsack
struct Node {
    int level, profit, weight, bound;
};

int bound(Node u, vector<int>& weights, vector<int>& values, int W) {
    if (u.weight >= W) return 0;

    int profit_bound = u.profit;
    int j = u.level + 1;
    int total_weight = u.weight;

    while (j < weights.size() && total_weight + weights[j] <= W) {
        total_weight += weights[j];
        profit_bound += values[j];
        j++;
    }

    if (j < weights.size())
        profit_bound += (W - total_weight) * values[j] / weights[j];

    return profit_bound;
}

int knapsackBranchBound(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();

    vector<pair<double, int>> items;
    for (int i = 0; i < n; ++i)
        items.push_back({(double)values[i] / weights[i], i});

    sort(items.rbegin(), items.rend()); // Sort by value/weight ratio

    vector<int> sortedWeights, sortedValues;
    for (auto& item : items) {
        sortedWeights.push_back(weights[item.second]);
        sortedValues.push_back(values[item.second]);
    }

    queue<Node> Q;
    Node u, v;
    u.level = -1; u.profit = u.weight = 0;
    Q.push(u);

    int maxProfit = 0;

    while (!Q.empty()) {
        u = Q.front();
        Q.pop();

        if (u.level == n - 1) continue;

        v.level = u.level + 1;
        v.weight = u.weight + sortedWeights[v.level];
        v.profit = u.profit + sortedValues[v.level];

        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        v.bound = bound(v, sortedWeights, sortedValues, W);
        if (v.bound > maxProfit)
            Q.push(v);

        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, sortedWeights, sortedValues, W);

        if (v.bound > maxProfit)
            Q.push(v);
    }
    return maxProfit;
}

// Main function
int main() {
    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};
    int W = 50;

    cout << "Using Backtracking: " << knapsackBacktrack(weights, values, W, weights.size()) << endl;
    cout << "Using Dynamic Programming: " << knapsackDP(weights, values, W) << endl;
    cout << "Using Branch and Bound: " << knapsackBranchBound(weights, values, W) << endl;

    return 0;
}
