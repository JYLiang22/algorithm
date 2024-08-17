#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 求出数组中最大数的位数
int MaxBit(vector<int> input){
    int maxVal = *max_element(input.begin(), input.end());
    int p = 0;
    while(maxVal){
        p++;
        maxVal /= 10;
    }
    return p;
}

// 取出所给数字的第d位数字
int GetNum(int num, int d){
    int p = 1;
    while(d - 1 > 0){
        p *= 10;
        d -= 1;
    }
    return num / p % 10;
}

vector<int> radixsort(vector<int> input, int length){
    vector<int> bucket(length);   // 创建临时存放排序过程中的数据
    vector<int> count(10);   // 创建按位计数的计数容器

    for(int d = 1; d <= MaxBit(input); d++){
        // 计数器清零
        for(int i = 0; i < 10; i++){
            count[i] = 0;
        }

        // 统计各个桶中的个数
        for(int i = 0; i < length; i++){
            count[GetNum(input[i], d)]++;
        }

        // 得到每个数应该放入bucket中的位置
        for(int i = 1; i < 10; i++){
            count[i] += count[i - 1];
        }

        // 采用倒序进行排序是为了不打乱已排好的顺序
        for(int i = length - 1; i >= 0; i--){
            int k = GetNum(input[i], d);
            bucket[count[k] - 1] = input[i];
            count[k]--;
        }

        // 临时数组复制到input中
        for(int j = 0; j < length; j++){
            input[j] = bucket[j];
        }

        cout << d << " round of radix sort: " << endl;
        for_each(input.begin(), input.end(), [](const int a){ cout << a << " "; });
        cout << endl;
    }
    return input;
}

int main(){

    vector<int> res = {50, 123, 543, 187, 49, 30, 0, 2, 11, 100};

    cout << "before sort: " << endl;
    for_each(res.begin(), res.end(), [](const int a){ cout << a << " "; });
    cout << endl;

    res = radixsort(res, res.size());

    cout << "after sort: " << endl;
    for_each(res.begin(), res.end(), [](const int a){ cout << a << " "; });
    cout << endl;

    return 0;
}