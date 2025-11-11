#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double FracKnap(vector<int> p, vector<int> w, int c, int n)
{
    vector<pair<double, pair<int, int>>> items;
    for (int i = 0; i < n; i++)
    {
        double ratio = (double)p[i] / w[i];
        items.push_back({ratio, {p[i], w[i]}});
    }

    // Sort items by ratio (profit/weight) in descending order
    sort(items.rbegin(), items.rend());

    double totalP = 0.0;
    int rem_cap = c;

    for (int i = 0; i < n; i++)
    {
        int price = items[i].second.first;
        int weight = items[i].second.second;

        if (weight <= rem_cap)
        {
            totalP += price;
            rem_cap -= weight;
        }
        else
        {
            totalP += rem_cap * items[i].first;
            break;
        }
    }
    return totalP;
}

int main()
{
    vector<int> p;
    vector<int> w;
    int c, n;

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the price of each item:\n";
    for (int i = 0; i < n; i++)
    {
        int price;
        cin >> price;
        p.push_back(price);
    }

    cout << "Enter the weight of each item:\n";
    for (int i = 0; i < n; i++)
    {
        int weight;
        cin >> weight;
        w.push_back(weight);
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> c;

    double maxProfit = FracKnap(p, w, c, n);

    cout << "\nMaximum profit (Fractional Knapsack) = " << maxProfit << endl;

    return 0;
}
