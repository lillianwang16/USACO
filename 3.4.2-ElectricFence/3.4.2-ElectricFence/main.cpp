/*
 ID: fenx14
 PROB: fence9
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
ifstream in ("fence9.in");
ofstream out ("fence9.out");
int n, m, p;
int ans = 0;

int tri(int y, int x){
    int cnt = 0;
    for (int i = 1; i < x; i++){
        double temp = i * (1.0 * y) / x;
        cnt += (int)temp - 1;
        if (temp - (int)(temp) > 0){
            cnt++;
        }
    }
    return cnt;
}


int main(){
    in >> n >> m >> p;
    if (n == 0){
        ans = tri(m, p);
        out << ans << endl;
        return 0;
    }
    if (p > n){
        ans = tri(m, n) + tri(m, p - n) + m - 1;
        out << ans << endl;
        return 0;
    }
    if (p < n){
        ans = tri(m, n) - tri(m, n - p);
        for (int i = 1; i < n - p; i++){
            double temp = i * (1.0 * m) / (n - p);
            if (temp - (int)(temp) == 0){
                ans--;
            }
        }
        out << ans << endl;
        return 0;
    }
    if (p == n){
        ans = tri(m, n);
        out << ans << endl;
        return 0;
    }
}
