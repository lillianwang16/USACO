/*
 ID: fenx14
 PROB: butter
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#define INF (10000)

using namespace std;
vector<vector<int> > map(801, vector<int> (801));
vector<int> cow(500);
int N, P, C;


int main(){
    ifstream in ("butter.in");
    ofstream out ("butter.out");
    in >> N >> P >> C;
    for (int i = 0; i < N; i++){
        in >> cow[i];
    }
    for (int i = 1; i <= P; i++){
        for (int j = 1; j <= P; j++){
            if (i  == j){
                map[i][j] = 0;
            }else{
                map[i][j] = INF;
            }
           
        }
    }
    for (int i = 0; i < C; i++){
        int temp1, temp2, temp3;
        in >> temp1 >> temp2 >> temp3;
        map[temp1][temp2] = map[temp2][temp1] = temp3;
    }
    for (int k = 1; k <= P; k++){
        for (int i = 1; i <= P; i++){
            for (int j = 1; j <= P; j++){
                if (map[i][k] + map[k][j] < map[i][j]){
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
    int min = 0x3fffffff;
    for (int i = 1; i <= P; i++){
        int temp = 0;
        for (int j = 0; j < N; j++){
            temp += map[i][cow[j]];
        }
        if (temp < min){
            min = temp;
        }
    }
    out << min << endl;
    
    return 0;
}
