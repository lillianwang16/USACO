/*
 ID: fenx14
 PROB: spin
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

struct wedge{
    int s, e;
};
wedge a[5][30];
int num[5];
int v[5];
vector<int> cnt(360);

bool check(int times){
    fill_n(cnt.begin(), 360, 0);
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < num[i]; j++){
            if (times){
                a[i][j].s = (a[i][j].s + v[i]) % 360;
            }
            for (int k = 0; k <= a[i][j].e; k++){
                cnt[(a[i][j].s + k) % 360]++;
            }
        }
    }
    for (int i = 0; i < 360; i++){
        if (cnt[i] >= 5){
            return true;
        }
    }
    return false;
}

int main(){
    ifstream in ("spin.in");
    ofstream out ("spin.out");
    for (int i = 0; i < 5; i++){
        in >> v[i] >> num [i];
        for(int j = 0; j < num[i]; j++){
            in >> a[i][j].s >> a[i][j].e;
        }
    }
    for (int i = 0; i < 360; i++){
        if (check(i)){
            out << i << endl;
            return 0;
        }
    }
    out << "none" << endl;

    return 0;
}
