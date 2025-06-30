#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findLHS(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int l = 0, r = 0, result = 0;
    while(r < nums.size()) {
        if(nums[r] - nums[l] < 1) {
            r++;
        } else if(nums[r] - nums[l] == 1){
            result = max(result, r-l+1);
            r++;
        } else {
            l++;
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    cout << findLHS(nums) << endl;
    return 0;
}