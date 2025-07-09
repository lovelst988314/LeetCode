#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>

using namespace std;


vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for(auto &str : strs) {
        string temp = str;
        sort(temp.begin(), temp.end());
        mp[temp].emplace_back(str);
    }

    vector<vector<string>> result;
    for(auto &mp1 : mp) {
        result.emplace_back(mp1.second);
    }
    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(strs);
    for(auto &vec : result) {
        for(auto &str : vec) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}