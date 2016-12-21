/*
 ID: fenx14
 PROB: stamps
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
int K, N;
vector<int> stamps;
//vector<int> f;
//int f[2000000];
vector<int> f(2000000);
#define MAX 201;



int main(){
    ifstream in ("stamps.in");
    ofstream out ("stamps.out");
    in >> K >> N;
    int temp;
    for (int i = 0; i < N; i++){
        in >> temp;
        stamps.push_back(temp);
    }
    f[0] = 0;
    //f.push_back(0);
    for (int i = 1; i < 2000000; i++){
        int min = MAX;
        for (int j = 0; j < N; j++){
            if (stamps[j] <= i){
                if (f[i - stamps[j]] + 1 < min){
                    min = f[i- stamps[j]] + 1;
                }
            }
        }
        f[i] = min;
        //f.push_back(min);
        if (min > K){
            out << i - 1 << endl;
            return 0;
        }
    }
    

    return 0;
}
