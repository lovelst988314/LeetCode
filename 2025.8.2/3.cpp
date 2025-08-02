#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s) {
        unordered_set<char> cset;
        int result = 0;
        int l = 0, r;
        for(r = 0; r < s.size(); r++) {
            if(cset.find(s[r]) == cset.end()) {
                cset.insert(s[r]);
            } else {
                result = max(result, r-l);
                while(cset.find(s[r]) != cset.end()) {
                    cset.erase(s[l]);
                    l++;
                }
                cset.insert(s[r]);
            }
        }
        result = max(result, r-l+1);
        return result;
}

int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}