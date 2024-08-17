#include<iostream>
#include<array>
#include<map>
#include<algorithm>
using namespace std;

void countingsort(array<int, 10> &arr){
    // // 寻找数列的最大最小值
    // int maxVal = *max_element(arr.begin(), arr.end());
    // int minVal = *min_element(arr.begin(), arr.end());
    map<int, int> cnt;
    for(int num : arr){
        if(cnt.find(num) == cnt.end()){
            cnt[num] = 1;
        }
        else{
            cnt[num] += 1;
        }
    }
    int idx = 0;
    for(map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
        while(it->second--)
            arr[idx++] = it->first;
    }
}

int main(){

    array<int, 10> arr = {1, 7, 4, 9, 0, 5, 2, 4, 7, 3};
    cout << "before countingsort: " << endl;
    for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
    cout << endl;

    countingsort(arr);

    cout << "after countingsort: " << endl;
    for_each(arr.begin(), arr.end(), [](const int &a){ cout << a << " "; });
    cout << endl;

    return 0;
}