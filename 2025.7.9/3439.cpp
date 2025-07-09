#include<iostream>
#include<vector>

using namespace std;


int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    int len = startTime.size();
    int reslut = 0, time = 0, left = 0, right = 0;
    for(int i = 0; i < len; i++) {
        int lefttime = left == 0 ? 0 : endTime[left-1];
        int righttime = right == len-1 ? eventTime : startTime[right+1];
        if(right-left < k-1) {
            time += endTime[i]  - startTime[i];
        } else {
            time += endTime[i]-startTime[i];
            reslut = max(reslut,righttime-lefttime-time);
            time -= endTime[left]-startTime[left];
            left++;
        }
        right++;
    }
    return reslut;
}

int main() {
    int eventTime = 21;
    int k = 2;
    vector<int> startTime = {18,20};
    vector<int> endTime = {20,21};
    cout << maxFreeTime(eventTime, k, startTime, endTime) << endl;
    return 0;
}