#include<iostream>
#include<vector>

using namespace std;

int onetime(vector<int>& nums, int left, int right) {
    int i = left+1, j = right;
    while(i <= j) {
      while(i <= j && nums[i] <= nums[left]) ++i;
      while(i <= j && nums[j] > nums[left]) --j;
      if(i <= j) swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[i-1]);
    return i-1;
}

void fast_sort(vector<int>& nums, int left, int right) {
    if(left >= right) return;
    int mid = onetime(nums, left, right);
    fast_sort(nums, left, mid-1);
    fast_sort(nums, mid+1, right);
}


int main () {
    std::vector<int> arr = {5, 2, 9, 1, 10, 6};
    fast_sort(arr, 0, arr.size() - 1);
    for(const auto& num : arr) {
        cout << num << " ";
    }
    return 0;
}