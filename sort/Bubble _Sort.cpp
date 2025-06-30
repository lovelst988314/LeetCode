#include<iostream>
#include<vector>

using namespace std;

// 冒泡排序（Bubble Sort）—— 它通过重复地遍历待排序的列表，比较相邻的元素并交换它们的位置来实现排序。
// 每次遍历将最大或者最小的元素放到数组的最后一个位置
void Bubble_Sort(vector<int> &nums) {
    for(int i = 0; i < nums.size(); i++) {
        for(int j = 1; j < nums.size()-i; j++) {
            if(nums[j] < nums[j-1]) {
                int temp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = temp;
            }
        }
    }
}

int main (int argv, char ** argc) {
    vector<vector<int>> test_cases = {
        {5, 3, 8, 4, 6},
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {2, 3, 2, 1, 4},
        {1, 1, 1, 1},
        {}
    };
    for (auto nums : test_cases) {
        Bubble_Sort(nums);
        for (auto num : nums) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}