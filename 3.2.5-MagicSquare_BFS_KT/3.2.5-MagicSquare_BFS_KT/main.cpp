/*
 ID: fenx14
 PROB: msquare
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

struct Node{
    int val;
    int cnt;
    int pre;
    char T;
}Q[50000];
vector<int> visited(50000);
int fac[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int Target, Qnum, p;

ifstream in ("msquare.in");
ofstream out ("msquare.out");

int KT(int s[]){
    int i, j, t, sum = 0;
    for (i = 0; i < 8; i++){
        t = 0;
        for (j = i + 1; j < 8 ; j++){
            if (s[j] < s[i]){
                t++;
            }
        }
        sum += t * fac[7 - i];
    }
    return sum + 1;
}

void reKT(int sum, int s[]){
    int i, j, t, vst[9] = {0};
    sum--;
    for (i = 0; i < 8; i++){
        t = sum / fac[7 - i];
        for (j = 1; j <= 8; j++){
            if (!vst[j]){
                if (t == 0){
                    break;
                }
                t--;
            }
        }
        s[i] = j;
        vst[j] = 1;
        sum %= fac[7 - i];
    }
}

void print_path(){
    int k = Qnum - 1;
    char ans[50000];
    out << Q[k].cnt << endl;
    int num = Q[k].cnt;
    while(Q[k].cnt){
        ans[Q[k].cnt] = Q[k].T;
        k = Q[k].pre;
    }
    for (int i = 1; i <= num; i++){
        if (i != 1 && i % 60 == 1){
            out << endl;
        }
        out << ans[i];
    }
    out << endl;
    exit(0);
}

void QPush(int val, char T){

    if (!visited[val]){
        Q[Qnum].val = val;
        Q[Qnum].cnt = Q[p].cnt + 1;
        Q[Qnum].pre = p;
        Q[Qnum].T = T;
        Qnum++;
        visited[val] = 1;
    }
    if (val == Target){
        print_path();
    }
}

void Trans(int s[]){
    int ss[8];
    for (int i = 0; i < 8; i++){
        ss[i] = s[7 - i];
    }
    QPush(KT(ss), 'A');
    ss[0] = s[3];
    ss[7] = s[4];
    for (int i = 0; i < 3; i++){
        ss[i + 1] = s[i];
    }
    for (int i = 5; i < 8; i++){
        ss[i - 1] = s[i];
    }
    QPush(KT(ss), 'B');
    for (int i = 0; i < 8; i++){
        ss[i] = s[i];
    }
    ss[1] = s[6];
    ss[2] = s[1];
    ss[6] = s[5];
    ss[5] = s[2];
    QPush(KT(ss), 'C');
}

void BFS(){
    int s[8];
    p = 0;
    while(p < Qnum){
        reKT(Q[p].val, s);
        Trans(s);
        p++;
    }
}

int main(){
    int tar[8];
    for (int i = 0; i < 8; i++){
        in >> tar[i];
    }
    int start[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    Target = KT(tar);
    int st = KT(start);
    if (Target == st){
        out << 0 << endl << endl;
        return 0;
    }
    Q[0].val = st;
    Q[0].cnt = 0;
    Qnum = 1;
    visited[st] = 1;
    BFS();
    return 0;
}
