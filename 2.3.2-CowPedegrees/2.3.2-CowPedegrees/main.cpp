/*
 ID: fenx14
 PROB: nocows
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

vector<vector<int> > f(101, vector<int>(201));


int main() {
    ifstream in ("nocows.in");
    ofstream out ("nocows.out");
    int N, K;
    in >> N >> K;
    for (int i = 1; i <= K; i++){
        f[i][1] = 1;
    }
    for (int i = 1; i <= K; i++){
        for (int j = 3; j <= N; j += 2 ){
            for (int left = 1; left <= j - 2; left += 2 ){
                f[i][j] += (f[i - 1][left] * f[i - 1][j - 1 - left]) % 9901;
                f[i][j] %= 9901;
            }
        }
    }
    out << ((f[K][N]+9901) - f[K - 1][N]) % 9901 << endl;
    
    return 0;
}
