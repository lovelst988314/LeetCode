#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isright(string s) {
    if(s.size() > 2) return false;
    if(s.size() == 1 && s[0] >= '1' && s[0] <= '9') return true; 
    if(s.size() == 2) {
        if(s[0] == '0') return false; // 不能以0开头
        int num = 0;
        num = (s[0]-'0')*10 + (s[1]-'0');
        if(num >= 1 && num <= 26) return true;
    }
    return false;
}
int numDecodings(string s) {
    int result = 0;
    vector<int> dp(s.size()+1, 0);
    dp[0] = 1;
    for(int i = 1; i < dp.size(); ++i) {
        if(isright(s.substr(i-1, 1))) {
            if(i-2 >= 0 && isright(s.substr(i-2, 2))) {
                dp[i] = dp[i-1] + (i-2 >= 0 ? dp[i-2] : 0);
            } else {
                dp[i] = dp[i-1];
            }
        } else if(i-2 >= 0 && isright(s.substr(i-2, 2))) {
            dp[i] = (i-2 >= 0 ? dp[i-2] : 0);
        }
    }
    return dp[dp.size()-1];
}

int main() {
    string s = "10";
    cout << numDecodings(s) << endl;
    return 0;
}