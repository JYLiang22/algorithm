#include<iostream>
#include<algorithm>
#include<array>
using namespace std;

void bubblesort(array<int, 6> &arr){
    int size = arr.size();
    // 记录无序数组的边界，每次比较只需要比较到这里即可
    int lastExchangeIdx = 0;
    int sortBorder = size - 1;
    for(int i = 0; i < size - 1; i++){
        // flag判断当前数组是否有序，已经有序，不需要继续交换
        bool flag = true;
        for(int j = 0; j < sortBorder; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                flag = false;
                lastExchangeIdx = j;
            }
        }
        cout << i + 1 << " round sort: " << endl;
        for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
        cout << endl;
        sortBorder = lastExchangeIdx;
        if(flag){
            break;
        }
    }
}

int main(){

    array<int, 6> arr{1, 5, 4, 2, 6, 3};
    cout << "before bubblesort" << endl;
    for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
    cout << endl;

    bubblesort(arr);

    cout << "after bubblesort" << endl;
    for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
    cout << endl;

    return 0;
}