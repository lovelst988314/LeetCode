#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });
    int result = 0;
    for(int i = 0; i < points.size();) {
        int maxpalce = points[i][1];
        while(i < points.size() && points[i][0] <= maxpalce) {
            i++;
        }
        result++;
    }
    return result;
}

int main() {
    vector<vector<int>> points = {{10,16}, {2,8}, {1,6}, {7,12}};
    cout << findMinArrowShots(points) << endl; // Output: 2
    return 0;
}