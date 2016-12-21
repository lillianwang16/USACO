/*
 ID: fenx14
 PROB: humble
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int K, N;
vector<int> kk(100);
set<long long> result;
set<long long>:: iterator it;


int main(){
    ifstream in ("humble.in");
    ofstream out ("humble.out");
    in >> K >> N;
    for (int i = 0; i < K; i++){
        in >> kk[i];
        result.insert(kk[i]);
        
    }
    for (int i = 0; i < K; i++){
        it = result.begin();
        while(1){
            long long temp = (*it) * kk[i];
            if (temp < 0){
                break;
            }
            if (result.size() > N){
                result.erase(--result.end());
                if (temp > *(--result.end())){
                    break;
                }
            }
            result.insert(temp);
            it++;
        }
    }
    
    out << *(--result.end()) << endl;
    
    return 0;
}
