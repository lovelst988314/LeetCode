#include<iostream>
#include<vector>

using namespace std;

int binsearch(vector<int> nums, int target) {
    int l = 0, r = nums.size()-1;
    while(l <= r) {
        int mid = (r-l)/2+l;
        if(nums[mid] > target) {
            r = mid-1;
        } else if(nums[mid] < target) {
            l = mid+1;
        } else {
            return mid;
        }
    }
    return l-1;  // 返回是-1 或者nums的长度查找失败 如果找到了 nums[mid] = target true; 否则对l-1 的这一行进行搜索
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    vector<int> rowsearch;
    for(int i = 0; i < matrix.size(); i++) {
        rowsearch.push_back(matrix[i][0]);
    }
    int label = binsearch(rowsearch, target);
    if(label == -1) return false;
    while(label >= 0) {
        if(label == rowsearch.size()) {
            --label;
            continue;
        }
        if(rowsearch[label] == target) return true;
        int num = binsearch(matrix[label], target);
        if(matrix[label][num] == target) return true;
        --label;
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    cout << searchMatrix(matrix, 5) << endl;
}