#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums, int left, int mid, int right) {
    vector<int> temp(right-left+1);
    int i = left, j = mid+1, index = 0;
    while(i <= mid && j <= right) {
        if(nums[i] <= nums[j]) temp[index++] = nums[i++];
        else temp[index++] = nums[j++];
    }
    while(i <= mid) temp[index++] = nums[i++];
    while(j <= right) temp[index++] = nums[j++];
    for(int i = 0; i < temp.size(); i++) {
        nums[left+i] = temp[i];
    }
}

void merge_sort(vector<int>& nums, int low, int high) {
    if(low < high) {
        int mid = (high-low)/2+low;
        merge_sort(nums, low, mid);
        merge_sort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
}

int main() {
    std::vector<int> arr = {5, 2, 9, 1, 10, 6};
    merge_sort(arr, 0, arr.size() - 1);
    for(const auto& num : arr) {
        cout << num << " ";
    }
    return 0;
}