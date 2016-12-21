/*
 ID: fenx14
 PROB: fact4
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int temp = 1;

int main(){
    ifstream in ("fact4.in");
    ofstream out ("fact4.out");
    in >> N;
    for(int i = 2; i <= N; i++ ){
        temp *= i;
        while(temp % 10 == 0){
            temp = temp / 10;
        }
        temp %= 1000;
    }
    out << temp % 10 << endl;

    return 0;
}
