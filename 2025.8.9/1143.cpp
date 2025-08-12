#include<iostream>
#include<vector>
#include<string>

using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int size1 = text1.size();
    int size2 = text2.size();
    vector<vector<int>> dp(size1+1, vector<int>(size2+1, 0));
    for(int i = 1; i <= size1; ++i) {
        for(int j = 1; j <= size2; ++j) {
            if(text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[size1][size2];
}

int main() {
    string text1 = "abc", text2 = "def";
    cout << longestCommonSubsequence(text1, text2) << endl;  // Output: 3
    return 0;
}