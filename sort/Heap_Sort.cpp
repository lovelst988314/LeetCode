#include<iostream>
#include<vector>

using namespace std;

void heapify(vector<int>& nums, int num, int rightend) {
    if(num > rightend) return;
    int left = num*2+1, right = num*2+2;
    int maxnum = num;
    if(left <= rightend && nums[left] > nums[maxnum]) maxnum = left;
    if(right <= rightend && nums[right] > nums[maxnum]) maxnum = right;
    if(maxnum != num) {
        swap(nums[num], nums[maxnum]);
        heapify(nums, maxnum, rightend);
    }
}

void buildheap(vector<int>& nums) {
    for(int i = nums.size()/2-1; i >= 0; --i) {
        heapify(nums, i, nums.size()-1);
    }
}

void heap_sort(vector<int>& nums) {
    buildheap(nums);
    for(int i = nums.size()-1; i > 0; --i) {
        swap(nums[0], nums[i]);
        heapify(nums, 0, i-1);
    }
}


int main () {
    std::vector<int> arr = {5, 2, 9, 1, 10, 6};
    heap_sort(arr);
    for(const auto& num : arr) {
        cout << num << " ";
    }
    return 0;
}