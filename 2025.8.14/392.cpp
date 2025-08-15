#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isSubsequence(string s, string t) {
    bool result;
    vector<vector<bool>> dp(s.size()+1, vector<bool>(t.size()+1, false));
    for(int i = 0; i < dp[0].size(); ++i) {
        dp[0][i] = true;
    }
    for(int i = 1; i < dp.size(); ++i) {
        for(int j = 1; j < dp[0].size(); ++j) {
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = dp[i][j-1];
        }
    }
    return dp[s.size()][t.size()];
}

int main() {
    string s = "abc";
    string t = "ahbgdc";
    cout << isSubsequence(s, t) << endl;
    return 0;
}