#include<iostream>
#include<algorithm>
#include<array>
using namespace std;

// �����³�����
void downAdjust(array<int, 10> &arr, int parentIdx, int len){
    // ���游�ڵ��ֵ���������ĸ�ֵ��������Ҫÿһ�����н���
    int temp = arr[parentIdx];
    // �������ӽڵ��±�
    int childIdx = 2 * parentIdx + 1;

    while(childIdx < len){
        // ��������Һ��ӽڵ�����Һ��ӽڵ��ֵ�������ӽڵ��ֵ����¼���±�
        if(childIdx + 1 < len && arr[childIdx + 1] > arr[childIdx]){
            childIdx += 1;
        }

        // ������ڵ��ֵ�Ⱥ��ӽڵ�Ĵ󣬵�������
        if(temp >= arr[childIdx]){
            break;
        }

        // �����ڵ㲢�³�����
        arr[parentIdx] = arr[childIdx];
        parentIdx = childIdx;
        childIdx = 2 * parentIdx + 1;
    }
    arr[parentIdx] = temp;
}

// ����
void heapsort(array<int, 10> &arr){
    // ���������鹹��ɶ����
    for(int i = arr.size() / 2 - 1; i >= 0; i--){
        downAdjust(arr, i, arr.size());
    }

    cout << "make heap: " << endl;
    for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
    cout << endl;

    // ѭ��ɾ���Ѷ�Ԫ�أ��Ƶ�����β�������ڶѲ����µĶѶ�
    for(int i = arr.size() - 1; i >= 0; i--){
        swap(arr[0], arr[i]);
        downAdjust(arr, 0, i);
        cout << "heapsort: " << endl;
        for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
        cout << endl;
    }
}

int main(){

    array<int, 10> arr = {10, 9, 8, 5, 6, 7, 1, 4, 2, 3};
    cout << "before heapsort: " << endl;
    for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
    cout << endl;

    heapsort(arr);

    cout << "after heapsort: " << endl;
    for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
    cout << endl;

    return 0;
}