#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ����������������λ��
int MaxBit(vector<int> input){
    int maxVal = *max_element(input.begin(), input.end());
    int p = 0;
    while(maxVal){
        p++;
        maxVal /= 10;
    }
    return p;
}

// ȡ���������ֵĵ�dλ����
int GetNum(int num, int d){
    int p = 1;
    while(d - 1 > 0){
        p *= 10;
        d -= 1;
    }
    return num / p % 10;
}

vector<int> radixsort(vector<int> input, int length){
    vector<int> bucket(length);   // ������ʱ�����������е�����
    vector<int> count(10);   // ������λ�����ļ�������

    for(int d = 1; d <= MaxBit(input); d++){
        // ����������
        for(int i = 0; i < 10; i++){
            count[i] = 0;
        }

        // ͳ�Ƹ���Ͱ�еĸ���
        for(int i = 0; i < length; i++){
            count[GetNum(input[i], d)]++;
        }

        // �õ�ÿ����Ӧ�÷���bucket�е�λ��
        for(int i = 1; i < 10; i++){
            count[i] += count[i - 1];
        }

        // ���õ������������Ϊ�˲��������źõ�˳��
        for(int i = length - 1; i >= 0; i--){
            int k = GetNum(input[i], d);
            bucket[count[k] - 1] = input[i];
            count[k]--;
        }

        // ��ʱ���鸴�Ƶ�input��
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