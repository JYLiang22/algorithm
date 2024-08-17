#include<iostream>
#include<algorithm>
#include<array>
using namespace std;

void merge(array<int, 8> &arr, int startIdx, int midIdx, int endIdx){
    // �½�һ��������
    int temparr[endIdx - startIdx + 1];
    int p1 = startIdx, p2 = midIdx + 1, p = 0;

    // �Ƚ���������С�����Ԫ�أ����η����������
    while(p1 <= midIdx && p2 <= endIdx){
        if(arr[p1] <= arr[p2]){
            temparr[p++] = arr[p1++];
        }
        else{
            temparr[p++] = arr[p2++];
        }
    }

    while(p1 <= midIdx){
        temparr[p++] = arr[p1++];
    }

    while(p2 <= endIdx){
        temparr[p++] = arr[p2++];
    }

    cout << "mergesort: " << endl;
    for(int i = 0; i < endIdx - startIdx + 1; i++){
        arr[i + startIdx] = temparr[i];
        cout << arr[i + startIdx] << " ";
    }
    cout << endl;
}

void mergesort(array<int, 8> &arr, int startIdx, int endIdx){
    // �ݹ��������
    if(startIdx >= endIdx){
        return;
    }
    // �۰�ݹ�
    int midIdx = (startIdx + endIdx) / 2;
    mergesort(arr, startIdx, midIdx);
    mergesort(arr, midIdx + 1, endIdx);
    merge(arr, startIdx, midIdx, endIdx);
}

int main(){

    array<int, 8> arr{4, 5, 8, 1, 7, 2, 6, 3};
    cout << "before mergesort" << endl;
    for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
    cout << endl;

    int size = arr.size() - 1;
    mergesort(arr, 0, size);

    cout << "after mergesort" << endl;
    for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
    cout << endl;

    return 0;
}