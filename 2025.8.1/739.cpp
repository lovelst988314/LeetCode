#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> st;
    vector<int> result(temperatures.size(),0);
    for(int i = 0; i < temperatures.size(); i++) {
        if(st.empty()) {
            st.push(i);
            continue;
        }
        while(!st.empty() && temperatures[st.top()] < temperatures[i]) {
            result[st.top()] = i-st.top();
            st.pop();
        }
        st.push(i);
    }
    return result;
}

int main() {
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> result = dailyTemperatures(temperatures);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}