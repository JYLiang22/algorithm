#include<iostream>
#include<algorithm>
#include<array>
using namespace std;

void selectsort(array<int, 6> &arr){
    int size = arr.size();
    for(int i = 0; i < size - 1; i++){
        int minIdx = i;
        for(int j = i + 1; j < size; j++){
            minIdx = (arr[minIdx] > arr[j] ? j : minIdx);
        }
        if(i != minIdx){
            swap(arr[i], arr[minIdx]);
        }
        cout << i + 1 << " round sort: " << endl;
        for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
        cout << endl;
    }
}

int main(){

    array<int, 6> arr{1, 5, 4, 2, 6, 3};
    cout << "before selectsort" << endl;
    for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
    cout << endl;

    selectsort(arr);

    cout << "after selectsort" << endl;
    for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
    cout << endl;

    return 0;
}