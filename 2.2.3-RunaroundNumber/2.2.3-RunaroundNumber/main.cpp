/*
 ID: fenx14
 PROB: runround
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>

using namespace std;


unsigned long int M;

bool RN(int nums[], int marks[], int bit){
    for (int i = 0; i < bit; i++){
        for (int j = i + 1; j < bit; j++){
            if (nums[i] == nums[j]) return false;
        }
    }
    int index = 0, bit_sum = 0;
    bool flag = false;
    while(bit_sum <= bit){
        if(bit_sum == bit && index == 0)    flag = true;
        if(bit_sum < bit && marks[index] == 1) break;
        
        marks[index] = 1;
        bit_sum++;
        index = (index + nums[index]) % bit;
    }
    return flag;
}



bool check(unsigned long int a){
    int bit = 0;
    unsigned long int a_copy = a;
    while(a_copy > 0){
        a_copy /= 10;
        bit++;
    }
    int nums[10] = {0};
    int marks[10] = {0};
    
    for (int i = bit - 1; i >= 0; i--){
        nums[i] = a % 10;
        a /= 10;
    }
    bool flag = RN(nums, marks, bit);
    
    return (flag);
}


int main() {
    
    ifstream in ("runround.in");
    ofstream out ("runround.out");
    
    in >> M;
    
    unsigned long int num = M + 1;
    while(1){
        if (check(num)){
            out << num << endl;
            break;
        }
        num++;
    }

    return 0;
}

/*

unsigned long int M;

int nums[10];
int marks[10];

bool RN(int nums[], int marks[], int bit){
    for (int i = 0; i < bit; i++){
        for (int j = i + 1; j < bit; j++){
            if (nums[i] == nums[j]) return false;
        }
    }
    int index = 0, bit_sum = 0;
    bool flag = false;
    while(bit_sum <= bit){
        if(bit_sum == bit && index == 0)    flag = true;
        if(bit_sum < bit && marks[index] == 1) break;
        
        marks[index] = 1;
        bit_sum++;
        index = (index + nums[index]) % bit;
    }
    return flag;
}



bool check(unsigned long int a){
    int bit = 0;
    unsigned long int a_copy = a;
    while(a_copy > 0){
        a_copy /= 10;
        bit++;
    }
    memset(nums, 0, sizeof(nums));
    memset(marks, 0, sizeof(marks));
    
    for (int i = bit - 1; i >= 0; i--){
        nums[i] = a % 10;
        a /= 10;
    }
    bool flag = RN(nums, marks, bit);
    
    return (flag);
}






int main() {
    
    ifstream in ("runround.in");
    ofstream out ("runround.out");
    
    in >> M;
    
    unsigned long int num = M + 1;
    while(1){
        if (check(num)){
            out << num << endl;
            break;
        }
        num++;
    }
    
    return 0;
}
*/
