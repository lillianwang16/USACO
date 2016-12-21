/*
 ID: fenx14
 PROB: fracdec
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;


int N, D;
vector<int> check(100000);
vector<int> result;

int main(){
    
    ifstream in ("fracdec.in");
    ofstream out ("fracdec.out");
    in >> N >> D;
    int a0, b0, a, b, cnt = 1;
    a0 = N / D;
    a = a0;
    b0 = N % D;
    b = b0;
    result.push_back(a);
    bool flag = false;
    while (b != 0){
        check[b] = cnt;
        b *= 10;
        a = b / D;
        b = b % D;
        cnt++;
        result.push_back(a);
        if ( check[b] != 0){
            flag = true;
            break;
        }
    }
    out << result[0] << '.';
    if (b0 == 0){
        out << 0;
    }else if (flag == false){
        int p = 2;
        while(a0 >= 10){
            a0 /= 10;
            p++;
        }
        for (int i = 1; i < result.size(); i++){
            if (p == 76){
                out << endl;
                p = 0;
            }
            out << result[i];
            p++;
        }
    }else{
        int p = 2;
        while(a0 >= 10){
            a0 /= 10;
            p++;
        }
        for(int i = 1; i < result.size(); i++){
            if (p == 76){
                out << endl;
                p = 0;
            }
            if (i == check[b]){
                out << '(';
                p++;
            }
            out << result[i];
            if (i == result.size() - 1){
                out << ')';
                p++;
            }
            p++;
        }
    }
    out << endl;
    return 0;
}
