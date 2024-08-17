#include<iostream>
#include<algorithm>
#include<array>
using namespace std;

int partition(array<int, 8> &arr, int startIdx, int endIdx){
    // 选择第一个元素作为基准位置
    int pivot = arr[startIdx];
    int left = startIdx, right = endIdx, idx = startIdx;

    // 外循环在左右指针重合或者交错的时候结束
    while(right > left){
        // right指针从右向左进行比较
        while(right > left){
            if(arr[right] < pivot){
                arr[left] = arr[right];
                idx = right;
                left++;
                break;
            }
            right--;
        }
        // left指针从左向右进行比较
        while(right > left){
            if(arr[left] > pivot){
                arr[right] = arr[left];
                idx = right;
                right--;
                break;
            }
            left++;
        }
    }
    arr[idx] = pivot;
    cout << "quicksort: " << endl;
    for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
    cout << endl;
    return idx;
}

void quicksort(array<int, 8> &arr, int startIdx, int endIdx){
    // 递归终止条件
    if(startIdx >= endIdx){
        return;
    }
    // 得到基准元素位置
    int idx = partition(arr, startIdx, endIdx);
    quicksort(arr, startIdx, idx - 1);
    quicksort(arr, idx + 1, endIdx);
}

int main(){

    array<int, 8> arr{4, 5, 8, 1, 7, 2, 6, 3};
    cout << "before quicksort" << endl;
    for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
    cout << endl;

    int size = arr.size() - 1;
    quicksort(arr, 0, size);

    cout << "after quicksort" << endl;
    for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
    cout << endl;

    return 0;
}