#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    vector<int> left(heights.size(),-1);  // 左边第一个小于该位置元素的下标
    vector<int> right(heights.size(),heights.size()); // 右边第一个小于该位置元素的下标
    stack<int> st;
    for(int i = 0; i < heights.size(); i++) {
        if(st.empty()) {
            st.push(i);
            continue;
        }
        while(!st.empty() && heights[st.top()] > heights[i]) {
            right[st.top()] = i;
            st.pop();
        }
        if(!st.empty()) {
            left[i] = st.top();
        }
        st.push(i);
    }
    int result = 0;
    for(int i = 0; i < heights.size(); i++) {
        result = max(result, heights[i]*(right[i]-left[i]-1));
    }
    return result;
}

int main () {
    vector<int> heights = {2,1,5,6,2,3};
    cout << largestRectangleArea(heights) << endl;
    return 0;
}