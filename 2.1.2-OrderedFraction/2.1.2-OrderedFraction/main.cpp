/*
 ID: fenx14
 PROB: frac1
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
int N;
int s[160 * 160];

struct Fraction{
    int num; // numerator
    int den; // denominator
};

Fraction Fra[160 * 160];

int gcd(int a, int b){
    return (b == 0 ? a: gcd(b, a%b));
}


bool cmp(int a, int b){
    return ((Fra[a].num * Fra[b].den) < (Fra[b].num * Fra[a].den));
}

int main(){

    ifstream in ("frac1.in");
    ofstream out ("frac1.out");
    
    in >> N;
    int cnt = 0;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j < i; j++){
            if (gcd(i,j) == 1){
                Fra[cnt].num = j;
                Fra[cnt].den = i;
                cnt++;
            }
        }
    }
    for (int i = 0; i < cnt; i++){
        s[i] = i;
    }

    sort( s, s + cnt, cmp );
    
    out << "0/1" << endl;
    for (int i = 0; i < cnt; i++ ){
        out << Fra[s[i]].num << '/' << Fra[s[i]].den << endl;
    }
    out << 1 << '/' << 1 << endl;
    
    return 0;
}

