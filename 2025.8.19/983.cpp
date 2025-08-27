#include<iostream>
#include <vector>
#include <unordered_set>

using namespace std;


int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> dp(366, 0);
    unordered_set<int> mset;
    int day3[3] = {1, 7, 30};
    for(int i = 0; i < days.size(); ++i) {
        mset.insert(days[i]);
    }
    for(int i = 365; i >= 1; --i) {
        if(mset.count(i)) {
            int minCost = INT_MAX;
            // 1天通行证：覆盖当天，费用为costs[0]
            minCost = min(minCost, costs[0] + (i+1 <= 365 ? dp[i+1] : 0));
            // 7天通行证：覆盖接下来7天，费用为costs[1]
            minCost = min(minCost, costs[1] + (i+7 <= 365 ? dp[i+7] : 0));
            // 30天通行证：覆盖接下来30天，费用为costs[2]
            minCost = min(minCost, costs[2] + (i+30 <= 365 ? dp[i+30] : 0));
            dp[i] = minCost;
        } else {
            dp[i] = (i + 1 <= 365) ? dp[i + 1] : 0;
        }
    }  
    return dp[1]; 
}

int main() {
    vector<int> days = {1, 4, 6, 7, 8, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
    vector<int> costs = {2, 7, 15};
    cout << mincostTickets(days, costs) << endl;
}