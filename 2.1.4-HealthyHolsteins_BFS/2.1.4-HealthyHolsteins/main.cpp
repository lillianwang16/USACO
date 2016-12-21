/*
 ID: fenx14
 PROB: holstein
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int V, G, num[15][25], aim[25];

bool check(vector<int> a){
    for (int j = 0; j < V; j++){
        int sum = 0;
        for (int i = 0; i < a.size(); i++){
            sum += num[a[i]][j];
        }
        if (sum < aim[j]) return false;
    }
    return true;
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
        for (int j = 0; j < V; j++){
            in >> num[i][j];
        }
    }
    vector<int> combine;
    queue<vector<int> > myqueue;
    
    for (int i = 0; i < G; i++){
        combine.push_back(i);
        myqueue.push(combine);
        combine.pop_back();
    }
    while (!myqueue.empty()){
        combine = myqueue.front();
        myqueue.pop();
        if (check(combine)){
            out << combine.size();
            for (int i = 0; i < combine.size(); i++ ) out << ' ' << combine[i] + 1;
            out << endl;
            break;
        }
        for (int i = combine[combine.size() - 1] + 1; i < G; i++){
            combine.push_back(i);
            myqueue.push(combine);
            combine.pop_back();
            
        }
        
    }
    
    return 0;
}
