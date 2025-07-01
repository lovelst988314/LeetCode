#include<iostream>
#include<string>

using namespace std;
int possibleStringCount(string word) {
    int nums[26] = {0};
    for(int i = 0; i < word.size(); i++) {
        if(i >= 1 && word[i] == word[i-1]) nums[word[i]-'a']++;
    }
    int result = 1;
    for(int i = 0; i < 26; i++) {
        result += nums[i];
    }
    return result;
}

int main() {
    string word  = "abacaba"; // Example input
    cout << possibleStringCount(word);
    return 0;
}
