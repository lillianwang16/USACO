/*
 ID: fenx14
 PROB: fence
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int> > map(501, vector<int> (501));
vector<int> degree(501);
vector<int> path;
int F;

void dfs(int node){
    for (int i = 0; i < 501; i++){
        if (map[node][i]){
            map[node][i]--;
            map[i][node]--;
            dfs(i);
        }
    }
    path.push_back(node);
}


int main(){
    ifstream in ("fence.in");
    ofstream out ("fence.out");
    in >> F;
    int st = 500;
    for (int i = 0; i < F; i++){
        int a, b;
        in >> a >> b;
        map[a][b]++;
        map[b][a]++;
        degree[a]++;
        degree[b]++;
        st = min(st, min(a, b));
    }
    for (int i = st; i < 501; i++){
        if (degree[i] % 2){
            st = i;
            break;
        }
    }
    dfs(st);
    for (int i = (int) path.size() - 1; i >= 0; i--){
        out << path[i] << endl;
    }
    return 0;
}
