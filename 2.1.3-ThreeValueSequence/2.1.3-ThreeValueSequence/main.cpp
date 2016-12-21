/*
 ID: fenx14
 PROB: sort3
 LANG: C++
 */

#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;

int N, c32 = 0, c31 = 0, c21 = 0, c23 = 0, c12 = 0, c13 = 0, num3 = 0, num2 = 0, num1 = 0;
int num[1001];
int result;
int tri32, tri21, tri13;

int main(){
    
    ifstream in ("sort3.in");
    ofstream out ("sort3.out");
    
    in >> N;
    
    for( int i = 0 ; i < N; i++ ){
        int a;
        in >> a;
        num[i] = a;
        switch(a){
            case(1): num1++;break;
            case(2): num2++;break;
            case(3): num3++;break;
        }
    }
    
    for( int i = 0 ; i < N; i++ ){
        if (i < num1){
            if (num[i] == 2) c12++;
            else if(num[i] == 3) c13++;
        }
        if ( i >= num1 && i < num1 + num2){
            if (num[i] == 1) c21++;
            else if(num[i] == 3) c23++;
        }
        if ( i >= num1 + num2 ){
            if (num[i] == 2) c32++;
            else if(num[i] == 1) c31++;
        }
    }
    
    result += min(c32, c23);
    result += min(c21, c12);
    result += min(c13, c31);
    result += (abs(c32 - c23) + abs(c21 - c12) + abs(c31- c13)) / 3 * 2;
    
    out << result << endl;
    
    return 0;
    
}
