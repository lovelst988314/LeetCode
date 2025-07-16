#include <iostream>
#include <vector>

using namespace std;

// 求组合数（不考虑顺序）
int combinationSum(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < coins.size(); ++i) {         // 外层遍历物品
        for (int j = coins[i]; j <= amount; ++j) {   // 内层遍历背包
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[amount];
}

// 求排列数（考虑顺序）
int permutationSum(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int j = 1; j <= amount; ++j) {              // 外层遍历背包
        for (int i = 0; i < coins.size(); ++i) {     // 内层遍历物品
            if (j >= coins[i]) {
                dp[j] += dp[j - coins[i]];
            }
        }
    }

    return dp[amount];
}

int main() {
    system("chcp 65001");
    vector<int> coins = {1, 2};
    int amount = 3;

    int combinations = combinationSum(coins, amount);
    int permutations = permutationSum(coins, amount);

    cout << "组合数（不考虑顺序）: " << combinations << endl; // 输出 2
    cout << "排列数（考虑顺序）: " << permutations << endl;     // 输出 3

    return 0;
}