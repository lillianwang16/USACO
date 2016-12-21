/*
 ID: fenx14
 PROB: comehome
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#define INF (200000)

using namespace std;

int N;
vector<vector<int> > map(52, vector<int>(52));
vector<int> d(52);
vector<bool> visited(52);

void Dijkstra(int s){
    for (int i = 0; i < 52; i++){
        d[i] = map[i][s];
    }
    d[s] = 0;
    visited[s] = true;
    int pre;
    for (int i = 0; i < 52; i++){
        int min = INF;
        for (int j = 0; j < 52; j++){
            if (!visited[j] && d[j] < min){
                min = d[j];
                pre = j;
            }
        }
        visited[pre] = true;
        for (int j = 0; j < 52; j++){
            if (!visited[j] && d[pre] + map[pre][j] < d[j]){
                d[j] = d[pre] + map[pre][j];
            }
        }
    }
}

int main(){
    ifstream in ("comehome.in");
    ofstream out ("comehome.out");
    in >> N;
    char p1, p2;
    int dist, x, y;
    for (int i = 0; i < 52; i++){
        for (int j = 0; j < 52; j++ ){
            if (i == j){
                map[i][j] = 0;
            }else{
                map[i][j] = INF;
            }
        }
    }
    for (int i = 0; i < N; i++){
        in >> p1 >> p2 >> dist;
        if (p1 >= 'A' && p1 <= 'Z'){
            x = p1 - 'A';
        }else{
            x = p1 - 'a' + 26;
        }
        if (p2 >= 'A' && p2 <= 'Z'){
            y = p2 - 'A';
        }else{
            y = p2 - 'a' + 26;
        }
        if (map[x][y] > dist){
            map[x][y] = dist;
            map[y][x] = dist;
        }
    }
    Dijkstra(25);
    int min = INF, p;
    for (int i = 0; i < 26; i++){
        if (i != 25 && min > d[i]){
            min = d[i];
            p = i;
        }
    }
    out << (char)(p + 'A')  << ' ' << min << endl;

    return 0;
}
