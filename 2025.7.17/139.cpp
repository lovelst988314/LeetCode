#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size()+1);
    unordered_set<string> wordset(wordDict.begin(), wordDict.end());
    dp[0] = true;
    for(int i = 1; i <= s.size(); i++) {
        for(int j = 0; j < i; j++) {
            string temp = s.substr(j,i-j);
            if(dp[j] && wordset.find(temp) != wordset.end()) dp[i] = true;
        }
    }
    return dp[s.size()];
}


int  main() {
        string s = "leetcode";
        vector<string> wordDict = {"leet", "code"};
        cout << wordBreak(s, wordDict) << endl;
    }