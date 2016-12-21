/*
 ID: fenx14
 PROB: humble
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
#define INF 0x7fffffff;

int K, N;
vector<int> kk(100);
vector<int> flag(100);
vector<long long> result(100001);


int main(){
    ifstream in ("humble.in");
    ofstream out ("humble.out");
    in >> K >> N;
    for (int i = 0; i < K; i++){
        in >> kk[i];
    }
    result[0] = 1;
    for (int i = 1; i <= N; i++){
        long long temp = INF;
        for (int j = 0; j < K; j++){
            while(kk[j] * result[flag[j]] <= result[i - 1]){
                flag[j]++;
            }
            if (kk[j] * result[flag[j]] < temp){
                temp = kk[j] * result[flag[j]];
            }
        }
        result[i] = temp;
    }
    out << result[N] << endl;
    return 0;
}
