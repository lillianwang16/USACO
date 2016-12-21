/*
 ID: fenx14
 PROB: money
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;
/*
int V, N;
vector<int> s(25);
vector<vector<long long> > f(26, vector<long long>(10001));


int main() {
    ifstream in ("money.in");
    ofstream out ("money.out");
    in >> V >> N;
    for (int i = 0; i < V; i++){
        in >> s[i];
        f[i + 1][0] = 1;
    }
    for (int i = 1; i <= V; i++){
        for (int j = 1; j <= N; j++)
            if (j >= s[i - 1]){
                f[i][j] = f[i - 1][j] + f[i][j - s[i - 1]];
            }else{
                f[i][j] = f[i - 1][j];
            }
    }
    out << f[V][N] << endl;
    return 0;
}
 */


int main(){
    ifstream in ("money.in");
    ofstream out ("money.out");
    int V, N;
    vector<long long> f(10001);
    in >> V >> N;
    f[0] = 1;
    int temp;
    for (int i = 0; i < V; i++){
        in >> temp;
        for (int j = temp; j <= N; j++){
            f[j] += f[j - temp];
        }
    }
    out << f[N] << endl;
    return 0;
}
