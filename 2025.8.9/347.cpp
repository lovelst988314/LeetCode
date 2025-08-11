#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); ++i) {
        mp[nums[i]]++;
    }
    auto mycom = [](std::pair<int, int> a, std::pair<int, int> b) {return a.second > b.second;};
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(mycom)> que(mycom);

    for(auto& m : mp) {
        que.push(m);
        if(que.size() > k) {
            que.pop();
        }
    }

    std::vector<int> result;
    while(que.size()) {
        result.push_back(que.top().first);
        que.pop();
    }
    return result;
}

int main() {
    std::vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    std::vector<int> result = topKFrequent(nums, k);
    for(auto& r : result) {
        std::cout << r << " ";
    }
    std::cout << std::endl;
    return 0;
}