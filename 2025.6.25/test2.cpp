#include<iostream>
#include<vector>

using namespace std;

int search (vector<int>& nums, int k) {
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
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "Hello World!" << endl;
    int k = 3;
    int result = search(nums, k);
    cout << result << endl;
    return 0;
}