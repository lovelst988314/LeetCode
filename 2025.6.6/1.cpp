#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string change(int num, int k) {
        string reslut;
        while(num > 0) {
            reslut.push_back(num%k+'0');
            num /= k;
        }
        reverse(reslut.begin(),reslut.end());
        return reslut;
    }

    bool isright (const string& str) {
        if(str.size() == 1) return true;
        int left = 0, right = str.size()-1;
        while(left <= right) {
            if(str[right] != str[left]) return false;
            right--;
            left++;
        }
        return true;
    }

    vector<long long> buildnum(int len) {
        int half = (len+1)/2;
        int start = pow(10,half-1);
        int end = pow(10,half);
        vector<long long> reslut;
        for(int i = start; i < end; i++) {
            string left = to_string(i);
            string right = left;
            if(len%2 == 1) right.pop_back();
            reverse(right.begin(),right.end());
            string str = left + right;
            reslut.push_back(stoll(str));
        }
        return reslut;
    }

    long long kMirror(int k, int n) {
        int num = 1;
        long long reslut = 0;
        int len = 1;
        while(n > 0) {
            vector<long long> nums = buildnum(len++);
            for(auto num : nums) {
                if(isright(change(num,k))) {
                    reslut +=  num;
                    cout << num << endl;
                    if(--n == 0) break;
                }
            }
        }
        return reslut;
    }
int main()
{
    int k = 5, n = 25;
    cout << kMirror(k,n) << endl;
    return 0;
}