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


int main(){
    ifstream in ("comehome.in");
    ofstream out ("comehome.out");
    in >> N;
    char p1, p2;
    int d, x, y;
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
        in >> p1 >> p2 >> d;
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
        if (map[x][y] > d){
            map[x][y] = d;
            map[y][x] = d;
        }
    }
    for (int k = 0; k < 52; k++){
        for (int i = 0; i < 52; i++){
            for (int j = 0; j < 52; j++){
                if (map[i][k] < INF && map[k][j] < INF && map[i][k] + map[k][j] < map[i][j]){
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
    int min = INF, p;
    for (int i = 0; i < 25; i++){
        if (map[25][i] < min){
            min = map[25][i];
            p = i;
        }
    }
    out << (char)(p + 'A')  << ' ' << min << endl;
    return 0;
}
