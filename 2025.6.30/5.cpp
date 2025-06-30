#include<iostream>
#include<string>

using namespace std;

pair<int,int> expandAroundCenter(const string& s, int l, int r) {
    int left = 0, right = 0;
    while(l >= 0 && r < s.size()) {
        if(s[l] == s[r]) {
            left = l; 
            right = r;
            l--;
            r++;
        } else {
            break;
        }
    }
    return {left,right};

}
string longestPalindrome(string s) {
    int l = 0, maxlen = -1;
    for(int i = 0; i < s.size(); i++) {
        auto pair1 = expandAroundCenter(s,i,i);
        auto pair2 = expandAroundCenter(s,i,i+1);
        if(pair1.second - pair1.first > maxlen) {
            maxlen = pair1.second - pair1.first+1;
            l = pair1.first;
        }
        if(pair2.second - pair2.first > maxlen) {
            maxlen = pair2.second - pair2.first+1;
            l = pair2.first;
        }
    }
    return s.substr(l,maxlen);
}

int main(int argv, char ** argc) {
    string str = "cbbd";
    cout << longestPalindrome(str) << endl;
    return 0;
}