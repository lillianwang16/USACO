/*
 ID: fenx14
 PROB: lamps
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


int N, C, C_mod, aim;
vector<int> on;
vector<int> off;
vector<int> change(4);
vector<int> result;
vector<bool> mark(4);

bool check(int state){
    for(int i = 0; i < on.size(); i++){
        if (!(state & 1 << (6 - on[i]))) return false;
    }
    for(int i = 0; i < off.size(); i++){
        if (!((~state) & 1 << (6 - off[i]))) return false;
    }
    return true;

}

void dfs(int max, int state, int cnt){
    if(cnt == max){
        if (check(state)){
            int flag = 1;
            for (int i = 0; i < result.size(); i++){
                if (result[i] == state) flag = 0;
            }
            if (flag) result.push_back(state);
        }
        return;
    }
    for ( int i = 0; i < 4; i++){
        if (!mark[i]){
            mark[i] = true;
            dfs(max, state, cnt);
            state ^= change[i];
            cnt++;
            dfs(max, state, cnt);
            mark[i] = false;
        }
        
    }
}



int main() {
    ifstream in ("lamps.in");
    ofstream out ("lamps.out");
    
    in >> N >> C;
    int temp;
    in >> temp;
    while (temp != -1){
        if (temp % 6 == 0) on.push_back(6);
        else on.push_back(temp % 6);
            in >> temp;
        }
    in >> temp;
    while (temp != -1){
        if (temp % 6 == 0) off.push_back(6);
        else off.push_back(temp % 6);
        in >> temp;
    }
    change[0] = 63;//0x3f
    change[1] = 42;
    change[2] = 21;
    change[3] = 36;
    
    for (int i = 0; i < on.size(); i++){
        for (int j = 0; j < off.size(); j++){
            if (on[i] == off[j]) {
                out << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    
    while(C >= 0){
        if ( C <= 4){
            for (int i = 0; i < 4; i++){
                mark[i] = false;
            }
            dfs(C, 63, 0);
        }
        C -= 2;
    }
    if (result.size() == 0){
        out << "IMPOSSIBLE" << endl;
        return 0;
    }
    sort(result.begin(), result.end());
    stack<int> s;
    queue<int> q;
    for(int i = 0; i < result.size(); i++){
        int temp = result[i];
        int j = 6;
        while(j > 0){
            s.push(temp % 2);
            temp /= 2;
            j--;
        }
        while(!s.empty()){
            int temp = s.top();
            s.pop();
            q.push(temp);
        }
        int NN = N;
        while (NN > 0){
            temp = q.front();
            q.pop();
            out << temp;
            q.push(temp);
            NN--;
        }
        while(!q.empty()){
            q.pop();
        }
        out << endl;
        
    }
    
    
    cout << check(63);
    return 0;
}
