#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool lemonadeChange(vector<int>& bills) {
    unordered_map<int, int> mp;
    for(int i = 0; i < bills.size(); ++i) {
        if(bills[i] == 5) mp[5]++;
        if(bills[i] == 10) {
            if(mp[5] >= 1) {
                mp[5]--;
                mp[10]++;
            } else return false;
            
        }
        if(bills[i] == 20) {
            if(mp[5] >=1 && mp[10] >= 1) {
                mp[5]--;
                mp[10]--;
                mp[20]++;
            } else if(mp[5] >= 3) {
                mp[5] -= 3;
                mp[20]++;
            } else {
            return false;
            }
        }
    }
    return true;
}

int main() {
    vector<int> bills = {5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5};
    cout << lemonadeChange(bills) << endl;
    return 0;
}