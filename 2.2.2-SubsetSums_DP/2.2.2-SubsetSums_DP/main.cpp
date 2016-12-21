/*
 ID: fenx14
 PROB: subset
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string.h>

//Simplified work
/*
using namespace std;
int N, sum;
long long f[2000];
int main(){
    
    ifstream in ("subset.in");
    ofstream out ("subset.out");

    in >> N;
    sum = (N * (N + 1)) / 2;
    if((sum & 1) == 1){
        out << 0 << endl;
        return 0;
    }
    sum /= 2;
    f[0] = 1;
    for (int i = 1; i <= N; i++){
        for (int j = sum; j >= i; j--){
            f[j] = f[j] + f[j - i];
        }
    }
    out << f[sum] / 2 << endl;
    return 0;

}
*/


//my dfs dp work

using namespace std;
int N, sum;
long long f[40][2000];

long long dfs_dp(int i, int j){
    if (f[i][j] != -1 )
        return f[i][j];
    if (j == 0)
        return 1;
    if (i == 0)
        return 0;
    if (i > j){
        f[i][j] = dfs_dp(i - 1, j);
    }else{
        f[i][j] = dfs_dp(i - 1, j) + dfs_dp(i - 1, j - i);
    }
    return f[i][j];
}

int main() {
    ifstream in ("subset.in");
    ofstream out ("subset.out");
    
    in >> N;
    int sum = 0;
    sum = (N + 1) * N / 2;
    if(sum % 2 != 0) {
        out <<  0 << endl;
        return 0;
    }
    
    memset(f, -1, sizeof(f));
    
    out << dfs_dp(N, sum / 2) / 2 << endl;
    
    return 0;
}



//my first work
/*
using namespace std;
int N;
long long result = 0;

 

long long zero_one(int c){
    vector<vector<long long> > m(N + 1, vector<long long>(c + 1));
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= c; j++){
            if (j == i){
                m[i][j] = m[i - 1][j] + 1;
            }
            if (j < i){
                m[i][j] = m[i - 1][j];
            }
            if (j > i){
                m[i][j] = m[i - 1][j] + m[i - 1][j - i];
            }
        }
    }
    return m[N][c];
}


int main() {
    ifstream in ("subset.in");
    ofstream out ("subset.out");
    
    in >> N;
    int sum = 0;
    for (int i = 1; i <= N; i++){
        sum += i;
    }
    if(sum % 2 == 0){
        result = zero_one(sum / 2);
    }else result = 0;
    
    out << result / 2 << endl;
    
    return 0;
}
*/



