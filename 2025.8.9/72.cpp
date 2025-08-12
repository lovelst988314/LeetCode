#include<iostream>
#include<vector>
#include<string>

using namespace std;
int minDistance(string word1, string word2) {
    int len1 = word1.size();
    int len2 = word2.size();
    vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
    for(int i = 1; i < dp.size(); ++i) {
        dp[i][0] = i;
    }
    for(int i = 1; i < dp[0].size(); ++i) {
        dp[0][i] = i;
    }
    for(int i = 1; i < dp.size(); ++i) {
        for(int j = 1; j < dp[0].size(); ++j) {
            if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]),dp[i-1][j-1])+1;
        }
    }
    return dp[len1][len2];
}

int main() {
    string word1 = "horse", word2 = "ros";
    cout << minDistance(word1, word2) << endl;  // Output: 3
    return 0;
}