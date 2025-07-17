#include<iostream>
#include<vector>

using namespace std;

int maximumLength(vector<int>& nums, int k) {
    int ans = 0;
    vector f(k, vector<int>(k));
    for (int x : nums) {
        x %= k;
        for (int y = 0; y < k; y++) {
            f[y][x] = f[x][y] + 1;
            ans = max(ans, f[y][x]);
        }
    }
    return ans;
}

int main() {
    vector<int> nums = { 1,4,2,3,1,4 };
    int k = 3;
    cout << maximumLength(nums, k);
    return 0;
}

