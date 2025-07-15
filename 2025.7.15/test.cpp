#include <vector>
#include <iostream>


using namespace std;



vector<vector<int>> generate(int numRows) {
    vector<vector<int>> dp;
    for(int i = 0; i < numRows; i++) {
        vector<int> temp(i+1);
        temp[0] = temp[i] = 1;
        dp.push_back(temp);
    }

    for(int i = 2; i < numRows; i++) {
        for(int j = 1; j < dp[i].size()-1; j++) {
            if(i-1 >= 0 && j-1 >= 0) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }
    }
    return dp;
}


int main () {
    int numRows = 5;
    vector<vector<int>> res = generate(numRows);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}