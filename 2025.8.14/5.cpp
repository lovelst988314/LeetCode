#include<iostream>
#include<string>
#include<vector>

using namespace std;

string longestPalindrome(string s) {
    string result;
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(),false));
    if(s.size() < 2) return result;

    int begin = 0, maxlen = 0;
    for(int i = s.size()-1; i >= 0; --i) {
        dp[i][i] = true;
        for(int j = i; j < s.size(); ++j) {
            if(i+1 < s.size() && j == i+1) {
                if(s[i] == s[j]) dp[i][j] = true;
                else dp[i][j] = false;
            }
            if(i+1 < s.size() && j-1 > i) {
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
                else dp[i][j] = false;
            }
            if(dp[i][j] == true) {
                if(maxlen < j-i+1) {
                    maxlen = j-i+1;
                    begin = i;
                }
            }

        }
    }
    return s.substr(begin, maxlen);
}

int main() {
    string s = "cbbd";
    cout << longestPalindrome(s) << endl;
    return 0;
}