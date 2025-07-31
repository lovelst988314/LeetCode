#include<iostream>
#include<vector>

using namespace std;

int onetime(vector<int> &v, int left, int right) {
    int num = v[left];
    int temp = left;
    while(left <= right) {
        while(left <= right && v[left] <= num) ++left;
        while(left <= right && v[right] > num) --right;
        if(right >= left) {
            swap(v[left], v[right]);
        }
    }
    swap(v[temp],v[right]);
    return right;
}

void quicksort(vector<int> &v, int left, int right) {
    if(left < right) {
        int nums = onetime(v,left,right);
        onetime(v,left,nums-1);
        onetime(v,nums+1,right);
    }
}


int main()
{
    vector<int> v = {32,34,543,243,423,4,1,23};
    quicksort(v,0,v.size()-1);
    for(auto i:v) {
        cout<<i<<" ";
    }
    cout << endl;
    return 0;
}