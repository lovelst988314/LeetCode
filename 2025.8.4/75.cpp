#include<iostream>
#include<vector>

using namespace std;
void sortColors(vector<int>& nums) {
    
}

int main() {
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}