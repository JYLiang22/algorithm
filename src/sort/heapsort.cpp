#include<iostream>
#include<algorithm>
#include<array>
using namespace std;

// 最大堆下沉调整
void downAdjust(array<int, 10> &arr, int parentIdx, int len){
    // 缓存父节点的值，用于最后的赋值，而不需要每一步进行交换
    int temp = arr[parentIdx];
    // 计算左孩子节点下标
    int childIdx = 2 * parentIdx + 1;

    while(childIdx < len){
        // 如果存在右孩子节点而且右孩子节点的值大于左孩子节点的值，记录其下标
        if(childIdx + 1 < len && arr[childIdx + 1] > arr[childIdx]){
            childIdx += 1;
        }

        // 如果父节点的值比孩子节点的大，调整结束
        if(temp >= arr[childIdx]){
            break;
        }

        // 交换节点并下沉调整
        arr[parentIdx] = arr[childIdx];
        parentIdx = childIdx;
        childIdx = 2 * parentIdx + 1;
    }
    arr[parentIdx] = temp;
}

// 排序
void heapsort(array<int, 10> &arr){
    // 把无序数组构造成二叉堆
    for(int i = arr.size() / 2 - 1; i >= 0; i--){
        downAdjust(arr, i, arr.size());
    }

    cout << "make heap: " << endl;
    for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
    cout << endl;

    // 循环删除堆顶元素，移到集合尾部，调节堆产生新的堆顶
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