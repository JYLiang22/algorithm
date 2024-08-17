#include<iostream>
#include<algorithm>
#include<array>
using namespace std;

void insertsort(array<int, 6> &arr){
    int size = arr.size();
    for(int i = 1; i < size; i++){
        int insertVal = arr[i];
        int j = i - 1;
        for(; j >= 0 && insertVal < arr[j]; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = insertVal;
        cout << i << " round sort: " << endl;
        for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
        cout << endl;
    }
}

int main(){

    array<int, 6> arr{1, 5, 4, 2, 6, 3};
    cout << "before insertsort" << endl;
    for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
    cout << endl;

    insertsort(arr);

    cout << "after insertsort" << endl;
    for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
    cout << endl;

    return 0;
}