/*
 ID: fenx14
 PROB: kimbits
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int N, L;
long long I;
vector<vector<long long> > f(33, vector<long long> (33));

int main(){
    ifstream in ("kimbits.in");
    ofstream out ("kimbits.out");
    in >> N >> L >> I;
    for (int i = 0; i <= N; i++){
        f[i][0] = f[0][i] = 1;
    }
    for (int i = 1; i <= L; i++){
        for (int j = 1; j <= N; j++){

            f[i][j] = f[i][j - 1] + f[i - 1][ j - 1];
        }
    }
    for (int i = N; i >= 1; i--){
        if (f[L][i - 1] < I){
            out << '1';
            I -= f[L][i - 1];
            L--;
        }else{
            out << '0';
        }
    }
    out  << endl;
    return 0;
}
