#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Item {
    int profit;
    int weight;
};
bool compare(Item a, Item b) {
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;
}
int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;
    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter profit and weight of item " << i + 1 << ": ";
        cin >> items[i].profit >> items[i].weight;
    }
    cout << "Enter knapsack capacity: ";
    cin >> capacity;
    sort(items.begin(), items.end(), compare);
    double totalProfit = 0.0;
    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        } else {
            totalProfit += items[i].profit * 
                          ((double)capacity / items[i].weight);
            capacity = 0;
        }
    }
    cout << "Maximum profit: " << totalProfit << endl;
    return 0;
}

