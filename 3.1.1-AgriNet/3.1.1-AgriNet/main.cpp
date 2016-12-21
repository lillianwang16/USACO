/*
 ID: fenx14
 PROB: agrinet
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#define INF 100001;

using namespace std;


int N;
vector<int> visited(100);
vector<vector<int> > dist(100, vector<int>(100));
vector<int> min_d(100);


int main(){
    ifstream in ("agrinet.in");
    ofstream out ("agrinet.out");
    in >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            in >> dist[i][j];
        }
    }
    for (int i = 0; i < N; i++){
        min_d[i] = INF;
    }
    min_d[0] = 0;
    int result = 0;
    for (int i = 0; i < N; i++){
        int p = -1, min = INF;
        for (int j = 0; j < N; j++){
            if (visited[j] != 1 && min_d[j] < min){
                min = min_d[j];
                p = j;
            }
        }
        visited[p] = 1;
        result += min;
        for (int j = 0; j < N; j++){
            if (j != p && dist[p][j] < min_d[j]){
                min_d[j] = dist[p][j];
            }
        }
    }
    out << result << endl;
    return 0;
}
