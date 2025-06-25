#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bin_search (vector<int>& nums, int k) {
    int l = 0, r = nums.size() - 1;
    while(l <= r) {
        int mid = (r-l)/2+l;
        if(nums[mid] >= k+1) {
            r = mid-1;
        } else{
            l = mid+1;
        }
    }
    return l-1; 
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> nums(matrix.size(),0);
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = matrix[i][0];
        }
        int index1 = bin_search(nums, target);
        if(index1 == -1) return false;
        if(matrix[index1][0] == target ) return true;
        int index2 = bin_search(matrix[index1], target);
        if(index2 == -1) return false;
        if(matrix[index1][index2] == target) return true;
        if(index2 == matrix[index1].size() - 1) return false;
        return false;
    }
int main()
{
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    if(searchMatrix(matrix, target)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}