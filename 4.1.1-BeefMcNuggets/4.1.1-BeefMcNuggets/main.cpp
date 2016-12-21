/*
 ID: fenx14
 PROB: nuggets
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> num(10);
vector<bool> f(65536);

int gcd(int i, int j){
    return(j == 0 ? i : gcd(j, i % j));
}

int main(){
    ifstream in ("nuggets.in");
    ofstream out ("nuggets.out");
    in >> N;
    for (int i = 0; i < N; i++){
        in >> num[i];
        if (num[i] == 1){
            out << 0 << endl;
            return 0;
        }
    }
    bool flag = true;
    int m = 0;
    for (int i = 0; i < N; i++){
        for (int j = i + 1; j < N; j++){
            m = max(m, num[i] * num[j]);
            if (gcd(num[i], num[j]) == 1){
                flag = false;
            }
        }
    }
    if (flag){
        out << 0 << endl;
        return 0;
    }
    f[0] = true;
    int ans = 0;
    for (int i = 1; i <= m; i++){
        for (int j = 0; j < N; j++){
            if (i - num[j] >= 0 && f[i - num[j]]){
                f[i] = true;
                break;
            }
        }
        if (!f[i]){
            ans = i;
        }
    }
    out << ans << endl;
    return 0;
}
