//1498. 满足条件的子序列数目
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    system("chcp 65001"); // 设置控制台编码为 UTF-8
    vector<int> numbers = {5, 2, 9, 1, 5, 6};
    cout << "原始数组: ";
    for (int num : numbers) {
        cout << num << " ";
    }

    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a < b; // 升序排序
    });

    cout << "排序后的数组: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;   

}

