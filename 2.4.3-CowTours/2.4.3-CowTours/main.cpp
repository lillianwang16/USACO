/*
 ID: fenx14
 PROB: cowtour
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <iomanip>

#define INF (1e40)

using namespace std;
vector<int> px(160);
vector<int> py(160);
vector<vector<double> > d(160, vector<double> (160));
vector<double> d_max(160);
int N;

double dist(int i, int j){
    return(sqrt(double(px[i] - px[j]) * (px[i] - px[j]) + double(py[i] - py[j]) * (py[i] - py[j])));
}

void flyd(){
    for (int k = 0; k < N; k++){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (i != j && d[i][k] + d[k][j] < d[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}


int main(){
    ifstream in ("cowtour.in");
    ofstream out ("cowtour.out");
    in >> N;
    for (int i = 0; i < N; i++){
        in >> px[i] >> py[i];
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            char temp;
            in >> temp;
            if (temp == '1'){
                d[i][j] = dist(i, j);
            }else{
                d[i][j] = INF;
            }
        }
    }
    flyd();
    double i_max = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (d[i][j] < INF && d[i][j] > d_max[i]){
                d_max[i] = d[i][j];
            }
        }
        if (d_max[i] > i_max){
            i_max = d_max[i];
        }
    }
    double o_min = INF;
    for (int i = 0; i < N; i++){
        for (int j = i + 1; j < N; j++){
            if (d[i][j] == INF){
                double temp = d_max[i] + d_max[j] + dist(i, j);
                if (temp < o_min){
                    o_min = temp;
                }
            }
        }
    }
    out << setiosflags(ios :: fixed) << setprecision(6) << (i_max > o_min ? i_max : o_min) << endl;
    
    return 0;
}
