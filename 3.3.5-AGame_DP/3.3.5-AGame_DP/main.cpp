/*
 ID: fenx14
 PROB: game1
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int> > s(102, vector<int> (102));
vector<vector<int> > dp(102, vector<int> (102));
vector<int> num(102);

int N;
int main(){
    ifstream in ("game1.in");
    ofstream out ("game1.out");
    in >> N;
    for (int i = 1; i <= N; i++){
        in >> num[i];
    }
    for (int i = 1; i <= N; i++){
        for (int j = i; j <= N; j++){
            s[i][j] = s[i][j - 1] + num[j];
        }
    }
    for (int i = N; i >= 1; i--){
        for (int j = i; j <= N; j++){
            int temp1 = num[i] + s[i + 1][j] - dp[i + 1][j];
            int temp2 = num[j] + s[i][j - 1] - dp[i][j - 1];
            dp[i][j] = max(temp1, temp2);
        }
    }
    out << dp[1][N] << ' ' << s[1][N] - dp[1][N] << endl;
    
    return 0;
}
