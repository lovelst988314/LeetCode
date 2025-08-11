#include<iostream>
#include<vector>

std::vector<int> path;
std::vector<std::vector<int>> result;
void backtrack(std::vector<int>& nums, int startindex) {
    result.push_back(path);
    for(int i = startindex; i < nums.size(); i++) {
        path.push_back(nums[i]);
        backtrack(nums, i+1);
        path.pop_back();
    }
}
std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    backtrack(nums, 0);
    return result;
}

int main() {
    std::vector<int> nums = {1,2,3};
    std::vector<std::vector<int>> result = subsets(nums);
    for(auto& r : result) {
        for(auto& n : r) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}