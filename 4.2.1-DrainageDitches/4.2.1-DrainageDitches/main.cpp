/*
ID: fenx14
PROB: ditch
LANG: C++
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <cstring>

#define INF 100000000;

using namespace std;

ifstream in ("ditch.in");
ofstream out ("ditch.out");
vector<vector<int> > map(201, vector<int>(201));
vector<int> father(201);

int M, N, ans = 0;;

void EK(){
    while(true){
        vector<int> val(201, 0);
        val[1] = INF;
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int k = q.front();
            q.pop();
            if (k == M){
                break;
            }
            for (int i = 1; i <= M; i++){
                if (!val[i]  && map[k][i] > 0){
                    q.push(i);
                    father[i] = k;
                    val[i] = min(val[k], map[k][i]);
                }
            }
        }
        if (val[M] == 0){
            break;
        }
        for (int i = M; i != 1; i = father[i]){
            map[father[i]][i] -= val[M];
            map[i][father[i]] += val[M];
        }
        ans += val[M];
    }
}

int main(){
    in >> N >> M;
    for (int i = 0; i < N; i++){
        int a, b, c;
        in >> a >> b >> c;
        map[a][b] += c;
    }
    EK();
    out << ans << endl;
    return 0;
}
