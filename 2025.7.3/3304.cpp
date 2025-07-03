#include<iostream>
#include<string>

using namespace std;

char kthCharacter(int k) {
    string str = "a";
    while(str.size() < k) {
        string temp = str;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] != 'z') temp[i] = str[i]+1;
            else temp[i] = 'a';
        }
        str += temp;
    }
    return str[k-1];
}


int main() {
    int k = 10; 
    cout << kthCharacter(k) << endl;
    return 0;
}