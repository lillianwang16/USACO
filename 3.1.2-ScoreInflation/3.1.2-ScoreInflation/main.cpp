/*
 ID: fenx14
 PROB: inflate
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define INF 100001;

using namespace std;

int M, N;
vector<int> f(10001);
vector<int> weight(10001);
vector<int> value(10001);


int main(){
    ifstream in ("inflate.in");
    ofstream out ("inflate.out");
    in >> M >> N;
    for (int i = 1; i <= N; i++){
        in >> value[i] >> weight[i];
    }
    
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++ ){
            if (j >= weight[i]){
                f[j] = max(f[j], f[j - weight[i]] + value[i]);
            }
        }
    }
    out << f[M] << endl;
    return 0;
}
