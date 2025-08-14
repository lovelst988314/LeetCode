#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int result = 0;
    int gplace = 0, splace = 0;
    while(gplace < g.size() && splace < s.size()) {
        while(splace < s.size() && g[gplace] > s[splace]) ++splace;
        if(splace == s.size()) break;
        ++result;
        ++splace;
        ++gplace;
    }
    return result;
}

int main() {
    vector<int> g = {1,2,3};
    vector<int> s = {1,1};
    cout << findContentChildren(g, s) << endl;
    return 0;
}