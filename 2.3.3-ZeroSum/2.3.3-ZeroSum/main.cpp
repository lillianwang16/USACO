/*
 ID: fenx14
 PROB: zerosum
 LANG: C++
 */

/*

#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;
int N;
int cnt;
string result[100];
char r[10];

void dfs(int number, int sum, int operand, int dig){
    if (number == 1){
        sum += operand;
        if (sum == 0){
            for (int j = 2; j <= N; j++ ){
                result[cnt] += r[j];
            }
            cnt++;
        }
        return;
    }
    for(int i = 0; i < 3; i++){
        if (i == 0){
            r[number] = '+';
            sum += operand;
            dfs(number - 1, sum, number - 1, 0);
            sum -= operand;
        }
        if (i == 1){
            r[number] = '-';
            sum -= operand;
            dfs(number - 1, sum, number - 1, 0);
            sum += operand;

        }
        if (i == 2){
            r[number] = ' ';
            dfs(number - 1, sum, operand + (number - 1) * pow (10, dig + 1), dig + 1);
        }
    }
}

int main() {
    ifstream in ("zerosum.in");
    ofstream out ("zerosum.out");
    in >> N;
    cnt = 0;
    dfs(N, 0, N, 0);
    sort(result, result + cnt);
    for (int i = 0; i < cnt; i++){
        out << 1;
        for (int j = 2; j <= N; j++){
            out << result[i][j - 2] << j;
        }
        out << endl;
    }
    
    return 0;
}
 */

#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
int N;
ofstream out("zerosum.out");

void dfs(int sum, int step, int operand, string print){
    if (step == N){
        if ((sum += operand) == 0){
            out << print << endl;
        }
        return;
    }
    if (operand < 0){
        dfs(sum, step + 1, operand * 10 - step - 1, print + ' ' + char(step + 1 +'0'));
    }else{
        dfs(sum, step + 1, operand * 10 + step + 1, print + ' ' + char(step + 1 +'0'));
    }
    dfs(sum + operand, step + 1, step + 1, print + '+' + char(step + 1 +'0'));
    dfs(sum + operand, step + 1, -step - 1, print + '-' + char(step + 1 +'0'));
}

int main(){
    ifstream in("zerosum.in");
    in >> N;
    dfs(0, 1, 1, "1");
    return 0;
}
