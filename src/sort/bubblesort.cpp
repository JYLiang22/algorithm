#include<iostream>
#include<algorithm>
#include<array>
using namespace std;

void bubblesort(array<int, 6> &arr){
    int size = arr.size();
    // ��¼��������ı߽磬ÿ�αȽ�ֻ��Ҫ�Ƚϵ����Ｔ��
    int lastExchangeIdx = 0;
    int sortBorder = size - 1;
    for(int i = 0; i < size - 1; i++){
        // flag�жϵ�ǰ�����Ƿ������Ѿ����򣬲���Ҫ��������
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