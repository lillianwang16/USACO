/*
 ID: fenx14
 PROB: hamming
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int N, B, D;
int path[64];
bool flag = true;


bool check(int depth, int a){
    int diff;
    for (int i = 0; i < depth; i++ ){
        diff = path[i] ^ a;
        int count_bit = 0;
        while(diff > 0){
            count_bit += diff % 2;
            diff /= 2;
        }
        if (count_bit < D) return false;
    }
    return true;
}


int main(){
    ifstream in("hamming.in");
    ofstream out("hamming.out");

    in >> N >> B >> D;
    path[0] = 0;
    for(int i = 1, count = 1; i < (1 << B) &&  count < N; i++){
        if(check (count, i)){
            path[count] = i;
            count++;
        }
    }
    for (int i = 0; i < N; i++){
        if (i == N - 1) out << path[i];
        else{
            if (i > 0 && (( i + 1 ) % 10) == 0){
                out << path[i] << endl;
            }else
                out << path[i] << ' ';
        }
    }
    out << endl;
    return 0;
}
