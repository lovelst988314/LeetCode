#include<iostream>
#include<string>

using namespace std;
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

int main() {
    string str = "100";
    cout << stringtoint(str) << endl;
    return 0;
}