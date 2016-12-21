/*
 ID: fenx14
 PROB: fence6
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
#include <set>
#define INF 10000;

using namespace std;

ifstream in ("fence6.in");
ofstream out ("fence6.out");
vector<vector<int> > d(100, vector<int>(100));
vector<vector<int> > m(100, vector<int>(100));
map<set<int>, int> ver;
int N = 0, ver_num = 0;

int vertex(set<int> &s){
    if (ver.find(s) == ver.end()){
        ver[s] = ver_num;
        return ver_num++;
    }
    return ver[s];
}
struct Edge{
    int vl, vr;
};
vector<Edge>edge(100);

void Build_map(){
    in >> N;
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            d[i][j] = INF;
            m[i][j] = INF;
        }
    }
    for (int i = 0; i < N; i++){
        int num = 0, len = 0, n1s = 0, n2s = 0;
        in  >> num >> len >> n1s >> n2s;
        set<int> s;
        s.insert(num);
        for (int j = 0; j < n1s; j++){
            int temp = 0;
            in >> temp;
            s.insert(temp);
        }
        int vl = vertex(s);
        s.clear();
        s.insert(num);
        for (int j = 0; j < n2s; j++){
            int temp = 0;
            in >> temp;
            s.insert(temp);
        }
        int vr = vertex(s);
        m[vl][vr] = m[vr][vl] = len;
        d[vl][vr] = d[vr][vl] = len;
        edge[i].vl = vl;
        edge[i].vr = vr;
    }
}

int floyd(){
    int min_loop = INT_MAX;
    for (int k = 0; k < ver_num; k++){
        for (int i = 0; i < k; i++){
            for(int j = i + 1; j < k; j++){
                if (min_loop > d[i][j] + m[i][k] + m[k][j]){
                    min_loop = d[i][j] + m[i][k] + m[k][j];
                    
                }
            }
        }
        for (int i = 0; i < ver_num; i++){
            for(int j = 0; j < ver_num; j++){
                if (d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    return min_loop;
}

int main(){
    Build_map();
    out << floyd() << endl;
    return 0;
}
