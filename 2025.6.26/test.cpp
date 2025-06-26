#include <iostream>
#include <string>

using namespace std;
int longestSubsequence(string s, int k) {
        int len = 0;
        int result = 0, sum = 0;
        int num = k;
        while(num > 0) {
            len++;
            num /= 2;
        }
        for(int i = s.size()-1; i >= 0; i--) {
            if(s[i] == '0') result++;
            if(s[i] == '1') {
                if(s.size()-i <= len && sum + (1<<(s.size()-i-1)) <= k) {
                    sum += (1<<(s.size()-i-1));
                    result++;
                }
            }
        }
        return result;
    }

int main()
{
    string s = "00101001";
    int k = 1;
    cout << longestSubsequence(s, k);
    return 0;
}

