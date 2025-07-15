#include<iostream>
#include<vector>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
    for(int i = 0; i < coins.size(); i++) {
        dp[i][0] = 0;
    }
    for(int i = 1; i <= amount; i++) {
        if(i < coins[0]) {
            dp[0][i] = -1;
        } else {
            if(dp[0][i-coins[0]] == -1) {
                dp[0][i] = -1;
            } else {
                dp[0][i] = dp[0][i-coins[0]]+1;
            }
        }
    }
    for(int i = 1; i < coins.size(); i++) {
        for(int j = 1; j <= amount; j++) {
            if(j < coins[i]) {
                dp[i][j] = dp[i-1][j];
            } else {
                if(dp[i-1][j] == -1 && dp[i][j-coins[i]] == -1) {
                    dp[i][j] = -1;
                }
                if(dp[i-1][j] == -1 && dp[i][j-coins[i]] != -1) {
                    dp[i][j] = dp[i][j-coins[i]]+1;
                }
                if(dp[i-1][j] != -1 && dp[i][j-coins[i]] == -1) {
                    dp[i][j] = dp[i-1][j];
                }
                if(dp[i-1][j] != -1 && dp[i][j-coins[i]] != -1) {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i]]+1);
                }
            }
        }
    }
    return dp[coins.size()-1][amount];
}

int main() {
    vector<int> coins = {1,2,5};
    int amount = 11;
    cout << coinChange(coins, amount) << endl;
    return 0;
}