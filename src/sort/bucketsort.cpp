#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;

#define bucketnum 5

void bucketsort(array<int, 10> &arr){
    int *minVal = min_element(arr.begin(), arr.end());
    int *maxVal = max_element(arr.begin(), arr.end());
    int dist = *maxVal - *minVal;

    // 初始化桶
    vector<vector<int>> vec(bucketnum);

    // 遍历原始数组，将元素放入桶中
    for(const int num : arr){
        int idx = (num - *minVal) * bucketnum / dist;
        if(idx == bucketnum)
            idx--;
        vec[idx].push_back(num);
    }

    cout << "the elements in each bucket: " << endl;
    for(vector<int> bucket : vec){
        for_each(bucket.begin(), bucket.end(), [](const int &num){ cout << num << " "; });
        cout << endl;
    }
    cout << endl;

    // 对每个桶进行排序，使用快排
    for(vector<int> &bucket : vec){
        sort(bucket.begin(), bucket.end());
    }

    cout << "the elements in each bucket after quicksort: " << endl;
    for(vector<int> bucket : vec){
        for_each(bucket.begin(), bucket.end(), [](const int &num){ cout << num << " "; });
        cout << endl;
    }
    cout << endl;

    int idx = 0;
    for(vector<int> bucket : vec){
        for(int num : bucket){
            arr[idx++] = num;
        }
    }
}

int main(){

    array<int, 10> arr{11, 38, 8, 34, 27, 19, 26, 13, 45, 79};
    cout << "before bucketsort: " << endl;
    for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
    cout << endl;

    bucketsort(arr);

    cout << "after bucketsort: " << endl;
    for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
    cout << endl;

    return 0;
}

