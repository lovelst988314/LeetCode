#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = i; j < matrix[0].size(); j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(auto& nums : matrix) {
        reverse(nums.begin(), nums.end());
    }
}

int main () { 
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(matrix);
    for(auto nums : matrix) {
        for(auto num : nums) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}