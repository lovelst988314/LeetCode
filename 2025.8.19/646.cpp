#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    });
    vector<int> dp(pairs.size(), 1);
    for(int i = 1; i < dp.size(); ++i) {
        if(pairs[i][0] > pairs[i-1][1]) dp[i] = dp[i-1]+1;
        else {
            int num = i-2;
            while(num >= 0) {
                if(pairs[i][0] > pairs[num][1]) {
                    dp[i] = dp[num]+1;
                    break;
                }
                num--;
            }
            if(num < 0) dp[i] = 1;
        }
    }
    return dp[dp.size()-1];
}

int main() {
    vector<vector<int>> pairs = {{1,2}, {2,3}, {3,4}};
    cout << findLongestChain(pairs) << endl; // 输出 2
    return 0;
}