#include<iostream>
#include<vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    bool Zerorow = false;   // 第一行是否有0
    bool Zeroline = false;  // 表示第一列是否有0

    for(int i = 0; i < matrix.size(); i++) {
        if(matrix[i][0] == 0) {
            Zeroline = true;
            break;
        }
    }
    for(int i = 0; i < matrix[0].size(); i++) {
        if(matrix[0][i] == 0) {
            Zerorow = true;
            break;
        }
    }
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            if(matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    for(int i = 1; i < matrix.size(); i++) {
        if(matrix[i][0] == 0) {
            for(int j = 1; j < matrix[0].size(); j++) matrix[i][j] = 0;
        }
    }
    for(int i = 1; i < matrix[0].size(); i++) {
        if(matrix[0][i] == 0) {
            for(int j = 1; j < matrix.size(); j++) matrix[j][i] = 0;
        }
    }
    if(Zerorow) {
        for(int i = 0; i < matrix[0].size(); i++) {
            matrix[0][i] = 0;
        }
    }
    if(Zeroline) {
        for(int i = 0; i < matrix.size(); i++) {
            matrix[i][0] = 0;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(matrix);
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
    }
}