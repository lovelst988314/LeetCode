#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> path;
vector<vector<int>> result;
int sum = 0;
void backtrack(vector<int>& candidates, int target, int start) {
    if(sum > target) return;
    if(sum == target) {
        result.push_back(path);
        return;
    }
    for(int i = start; i < candidates.size(); i++) {
        path.push_back(candidates[i]);
        sum += candidates[i];
        backtrack(candidates, target, i);
        sum -= candidates[i];
        path.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    backtrack(candidates, target, 0);
    return result;
}

int main() {
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> result = combinationSum(candidates, target);
    for(auto& r : result) {
        for(auto& n : r) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}