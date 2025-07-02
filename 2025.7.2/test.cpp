#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end());
    result.push_back(intervals[0]);
    for(int i = 1; i < intervals.size(); i++) {
        if(intervals[i][0] <= result.back()[1]) {
            result.back()[1] = max(result.back()[1],intervals[i][1]);
        } else {
            result.push_back(intervals[i]);
        }
    }
    return result;
}

int main() {
    vector<vector<int>> intervals = {{1,4},{0,2},{3,5}};
    vector<vector<int>> result = merge(intervals);
    for(auto i : result) {
        cout << i[0] << " " << i[1] << endl;
    }
    return 0;
}