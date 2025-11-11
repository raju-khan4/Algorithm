 #include <iostream>
#include <vector>
using namespace std;
 
// Function to solve 0/1 Knapsack and print chosen items
int knapsack(int W, vector<int>& wt, vector<int>& val, int n, vector<int>& chosen)
{
    vector<vector<int > > dp(n + 1, vector<int>(W + 1, 0));
 
    // Build DP table
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];  
        }
    }
 
    // Backtrack to find which items were chosen
    int w = W;
    for (int i = n; i > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])   // Item i was included
        {
            chosen.push_back(i); // store item number (1-based)
            w -= wt[i - 1]; // reduce remaining capacity
        }
    }
 
    return dp[n][W];
}
 
int main()
{
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
 
    vector<int> val(n), wt(n);
    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
 
    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
 
    cout << "Enter maximum capacity of knapsack: ";
    cin >> W;
 
    vector<int> chosen;
    int maxValue = knapsack(W, wt, val, n, chosen);
 
    cout << "\nMaximum value in knapsack = " << maxValue << endl;
    cout << "Items picked (1-based index): ";
    for (int i = chosen.size() - 1; i >= 0; i--)  // print in correct order
    {
        cout << chosen[i] << " ";
        cout << endl;
    }
 
    return 0;
}