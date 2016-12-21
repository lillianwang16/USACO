/*
 ID: fenx14
 PROB: rockers
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
ifstream in ("rockers.in");
ofstream out ("rockers.out");
int N, T, M, ans = 0;
vector<int> songs(21);

void DFS(int remain, int i, int n, int m){
    if(m > M){
        ans = max(ans, n - 1);
        return;
    }
    if (i >= N){
        ans = max(ans, n);
        return;
    }
    DFS(remain, i + 1, n, m);
    if (remain >= songs[i + 1]){
        DFS(remain - songs[i + 1], i + 1, n + 1, m);
    }else{
        if (T >= songs[i + 1]){
            DFS(T - songs[i + 1], i + 1, n + 1, m + 1);
        }
    }
}

int main(){
    in >> N >> T >> M;
    for (int i = 1; i <= N; i++){
        in >> songs[i];
    }
    DFS(T, 0, 0, 1);
    out << ans << endl;
    return 0;
}
