/*
 ID: fenx14
 PROB: shopping
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

/*
struct Node{
    int num[6];
    int price;
};

Node offers[100];
int dp[6][6][6][6][6] = {0};
int buy[6] = {0};
int price[6] = {0};
int code_id[1000] = {0};
int s, b, id = 0;

void Init(){
    for(int i1 = 0; i1 <= buy[1]; i1++){
        for(int i2 = 0; i2 <= buy[2]; i2++){
            for(int i3 = 0; i3 <= buy[3]; i3++){
                for(int i4 = 0; i4 <= buy[4]; i4++){
                    for(int i5 = 0; i5 <= buy[5]; i5++){
                        dp[i1][i2][i3][i4][i5] = i1 * price[1]+ i2 * price[2] + i3 * price[3] + i4 * price[4] + i5 * price[5];
                    }
                }
            }
        }
    }
}

void DP(){
    for (int i = 0; i < s; i++){
        int a1, a2, a3, a4, a5;
        a1 = offers[i].num[1];
        a2 = offers[i].num[2];
        a3 = offers[i].num[3];
        a4 = offers[i].num[4];
        a5 = offers[i].num[5];
        for (int i1 = a1; i1 <= buy[1]; i1++){
            for (int i2 = a2; i2 <= buy[2]; i2++){
                for (int i3 = a3; i3 <= buy[3]; i3++){
                    for (int i4 = a4; i4 <= buy[4]; i4++){
                        for (int i5 = a5; i5 <= buy[5]; i5++){
                            dp[i1][i2][i3][i4][i5] = min(dp[i1][i2][i3][i4][i5], dp[i1 - a1][i2 - a2][i3 - a3][i4 - a4][i5 - a5] + offers[i].price);
                        }
                    }
                }
            }
        }
    }
}


int main(){
    ifstream in ("shopping.in");
    ofstream out ("shopping.out");
    in >> s;
    for (int i = 0; i < s; i++){
        int n;
        in >> n;
        for (int j = 0; j < n; j++){
            int c;
            in >> c;
            if (code_id[c] == 0) {
                code_id[c] = ++id;
            }
            in >> offers[i].num[code_id[c]];
        }
        in >> offers[i].price;
    }
    in >> b;
    for (int i = 0; i < b; i++){
        int c;
        in >> c;
        if (code_id[c] == 0) {
            code_id[c] = ++id;
        }
        in >> buy[code_id[c]] >> price[code_id[c]];
        
    }
    Init();
    DP();
    out << dp[buy[1]][buy[2]][buy[3]][buy[4]][buy[5]] <<  endl;
    return 0;
}
*/


struct Node{
    int num[6];
    int price;
};

Node offers[100];
int dp[6][6][6][6][6] = {0};
int buy[6] = {0};
int price[6] = {0};
int code_id[1000] = {0};
int s, b, id = 0;

int DP(int a1, int a2, int a3, int a4, int a5){
    if (dp[a1][a2][a3][a4][a5] != -1){
        return dp[a1][a2][a3][a4][a5];
    }
    int min_price = 0x7fffffff;
    for (int i = 0; i < s + b; i++){
        int i1 = a1 - offers[i].num[1];
        int i2 = a2 - offers[i].num[2];
        int i3 = a3 - offers[i].num[3];
        int i4 = a4 - offers[i].num[4];
        int i5 = a5 - offers[i].num[5];
        if (i1 >= 0 && i2 >= 0 && i3 >= 0 && i4 >= 0 && i5 >= 0){
            dp[i1][i2][i3][i4][i5] = DP(i1, i2, i3, i4, i5);
            min_price = min(min_price, dp[i1][i2][i3][i4][i5] + offers[i].price);
        }
    }
    return min_price;
}

int main(){
    ifstream in ("shopping.in");
    ofstream out ("shopping.out");
    in >> s;
    for (int i = 0; i < s; i++){
        int n;
        in >> n;
        for (int j = 0; j < n; j++){
            int c;
            in >> c;
            if (code_id[c] == 0) {
                code_id[c] = ++id;
            }
            in >> offers[i].num[code_id[c]];
        }
        in >> offers[i].price;
    }
    in >> b;
    for (int i = 0; i < b; i++){
        int c;
        in >> c;
        if (code_id[c] == 0) {
            code_id[c] = ++id;
        }
        in >> buy[code_id[c]] >> price[code_id[c]];
        offers[s + i].num[code_id[c]] = 1;
        offers[s + i].price = price[code_id[c]];
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0][0][0][0] = 0;
    out << DP(buy[1], buy[2], buy[3], buy[4], buy[5]) <<  endl;
    return 0;
}
