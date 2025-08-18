#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool judgeis(string s, string t) {
    unordered_map<char, int> mp;
    for(int i = 0; i < t.size(); ++i) {
        mp[t[i]]++;
    }
    for(int i = 0; i < s.size(); ++i) {
         mp[s[i]]--;
    }
    for(auto& mp1 : mp) {
        if(mp1.second > 0) return false;
    }
    return true;
}

string minWindow(string s, string t) {
    int left = 0;
    string result = "";
    int minleft = 0, minright = 0;
    int len = INT_MAX;
    for(int right = 0; right < s.size(); ++right) {
        string temp = s.substr(left, right-left+1);
        if(!judgeis(temp, t)) {
            continue;
        } else {
            while(left <= right) {
                string curstring = s.substr(left, right-left+1);
                if(!judgeis(curstring, t)) break;
                if(right-left+1 < len) {
                    len = right-left+1;
                    minleft = left;
                    minright = right;
                }
                left++;
            }
        }
    }
    if(minright >= minleft) {
        result = s.substr(minleft, minright - minleft + 1);
    }
    return result;
}

int main() {
    string s = "a";
    string t = "aa";
    cout << minWindow(s, t) << endl;
    return 0;
}