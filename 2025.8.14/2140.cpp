#include<iostream>
#include<vector>

using namespace std;

long long mostPoints(vector<vector<int>>& questions) {
    vector<long long> dp(questions.size()+1, 0);
    dp[1] = questions[0][0];
    for(int i = 2; i < dp.size(); ++i) {
        long long num = 0;
        for(int j = i-2; j >= 0; --j) {
            if(questions[j][1] + j < i) {
                num = max(num, dp[j]);
            }
        }
        dp[i] = num + questions[i-1][0];
    }
    return dp[questions.size()];
}

int main() {
    vector<vector<int>> questions = {{3, 2}, {4, 3}, {4, 4}, {2, 5}};
    cout << mostPoints(questions) << endl;
    return 0;
}