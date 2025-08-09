#include<iostream>
#include<vector>

using namespace std;

void heapify(vector<int>& nums, int i, int len) {
    int lagest = i;
    int lson = 2*i+1;
    int rson = 2*i+2;
    if(lson < len && nums[lson] > nums[lagest]) lagest = lson;
    if(rson < len && nums[rson] > nums[lagest]) lagest = rson;
    if(lagest != i) {
        swap(nums[i], nums[lagest]);
        heapify(nums, lagest, len);
    }
}

void buildheap(vector<int>& nums) {
    for(int i = nums.size()/2-1; i >= 0; --i) {
        heapify(nums, i, nums.size());
    }
}

int findKthLargest(vector<int>& nums, int k) {
    buildheap(nums);
    int len = nums.size();
    for(int i = len-1; i > len-1-k; --i) {
        swap(nums[0], nums[i]);
        heapify(nums, 0, i);
    }
    return nums[nums.size()-k];
}

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << findKthLargest(nums, k) << endl;
    return 0;
}