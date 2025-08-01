#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

string  copynstr(string s, int k) {
    string str;
    for(int i = 0; i < k; i++) {
        str += s;
    }
    return str;
} 
int stringtoint(string str) {
    int result = 0;
    for(int i = 0; i < str.size(); i++) {
        int temp = str[i]-'0';
        for(int j = 0; j < i; j++) {
            temp *= 10;
        }
        result += temp;
    }
    return result;
}
string decodeString(string s) {
    stack<char> st;
    for(int i = 0; i < s.size(); i++) {
        switch(s[i]) {
            case ']': {
            string str = "";
            while(st.top() != '[') {
                str += st.top();
                st.pop();
            }
            reverse(str.begin(), str.end());
            st.pop();
            string temp = "";
            while(!st.empty() && (st.top()-'0' >= 0 && st.top() <= '9')) {
                temp += st.top();
                st.pop();
            }
            int num = stringtoint(temp);
            str = copynstr(str,num);
            for(int i = 0; i < str.size(); i++) {
                st.push(str[i]);
            }
            break; }
            default: 
                st.push(s[i]);
        }
    }
    string result;
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string s = "100[leetcode]";
    cout << decodeString(s) << endl;
    return 0;
}