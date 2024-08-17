#include<iostream>
#include<algorithm>
#include<array>
using namespace std;

void shellsort(array<int, 8> &arr){
    // 希尔排序的增量
    int d = arr.size();
    while(d > 1){
        // 每次折半
        d /= 2;
        for(int i = 0; i < d; i++){
            for(int j = i + d; j < arr.size(); j += d){
                int temp = arr[j];
                int k = j - d;
                for(; k >= 0 && arr[k] > temp; k -= d){
                    arr[k + d] = arr[k];
                }
                arr[k + d] = temp;
            }
        }
        cout << "d = " << d << endl;
        for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
        cout << endl;
    }
}

int main(){

    array<int, 8> arr{1, 5, 8, 4, 7, 2, 6, 3};
    cout << "before shellsort" << endl;
    for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
    cout << endl;

    shellsort(arr);

    cout << "after shellsort" << endl;
    for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
    cout << endl;

    return 0;
}