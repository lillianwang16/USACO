/*
 ID: fenx14
 PROB: rockers
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
ifstream in ("rockers.in");
ofstream out ("rockers.out");
int N, T, M, ans = 0;
typedef vector<int> vi;
typedef vector<vi> vvi;
vector<vvi> dp(21, vvi(21, vi(21, 0)));
vector<int> songs(21);

int main(){
    in >> N >> T >> M;
    for (int i = 1; i <= N; i++){
        in >> songs[i];
    }
    for (int m = 1; m <= M; m++){
        for (int n = 1; n <= N; n++){
            for (int t = T; t >= 0; t--){
                if (t + songs[n] == T){
                    dp[m][n][t] = max(dp[m - 1][n - 1][0] + 1, dp[m][n - 1][t]);
                }else{
                    if (t + songs[n] < T){
                        dp[m][n][t] = max(dp[m][n - 1][t + songs[n]] + 1, max(dp[m][n - 1][t], dp[m][n][T - songs[n]]));
                    }else{
                        dp[m][n][t] = dp[m][n - 1][t];
                    }
                }
            }
        }
    }
    out << dp[M][N][0] << endl;
    return 0;
}
