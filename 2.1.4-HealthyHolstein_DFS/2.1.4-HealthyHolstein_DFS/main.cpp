/*
 ID: fenx14
 PROB: holstein
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int V, G, num[15][25], aim[25];
vector<int> best;

bool check(vector<int> sum){
    for (int i = 0; i < V; i++){
        if (sum[i] < aim [i]) return false;
    }
    return true;
}

void DFS(vector<int> sum, vector<int> combine){

    if (check(sum) && combine.size() < best.size()){
        best = combine;
        return;
    }
    int flag = 0;
    if (combine.size() != 0){
        flag = combine[combine.size() - 1] + 1;
    }
    
    for(int i = flag; i < G; i++){
        combine.push_back(i);
        for (int j = 0; j < V; j++){
            sum[j] += num[i][j];
        }
        DFS(sum, combine);
        combine.pop_back();
        for (int j = 0; j < V; j++){
            sum[j] -= num[i][j];
        }
    }
}

int main() {
    
    ifstream in("holstein.in");
    ofstream out("holstein.out");
    
    in >> V;
    for (int i = 0; i < V; i++){
        in >> aim[i];
    }
    in >> G;
    for (int i = 0; i < G; i++){
        for(int j = 0; j < V; j++){
            in >> num[i][j];
        }
    }

    for (int i = 0; i < G; i++) best.push_back(i);
    
    vector<int> sum(V);
    vector<int> combine;
    DFS(sum, combine);
    
    out << best.size();
    for(int i = 0; i < best.size(); i++){
        out << ' ' << best[i] + 1;
    }
    out << endl;
    return 0;
}
