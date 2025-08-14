#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int largestSumAfterKNegations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int num = 0;
    int flag = 0;
    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] < 0) ++num;
        else if(nums[i] == 0) flag = 1;
        else break;
    }
    int result = 0;
    if(k <= num) {
    
        for(int i = 0; i < nums.size(); ++i) {
            if(k > 0) {
                result += -nums[i];
                --k;
            } else {
                result += nums[i];
            }
        }
    }
    if(k > num && flag == 1) {
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] < 0) nums[i] = -nums[i];
            result += nums[i];
        }
    }

    if(k > num && flag != 1) {
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] < 0) nums[i] = -nums[i];
        }
        sort(nums.begin(), nums.end());
        if((k-num) % 2 == 1) nums[0] = -nums[0];
        for(int i = 0; i < nums.size(); ++i) {
            result += nums[i];
        }
    }
    return result;
}

int main() {
    vector<int> nums = {-4,-6,9,-2,2};
    int k = 4;
    cout << largestSumAfterKNegations(nums, k) << endl;  // Output: 5
    return 0;
}