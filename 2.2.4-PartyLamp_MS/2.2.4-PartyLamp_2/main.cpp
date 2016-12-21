/*
 ID: fenx14
 PROB: lamps
 LANG: C++
 */


//Memory search



#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;


int N, C, on, off;
vector<int> onoff(6);
vector<vector<int> > map(5, vector<int> (0x3f + 1));
vector<int> result(6);
vector<bool> mark(4);
vector<int> change(4);

bool dfs(int C, int state){
    if (map[C][state] != -1){
        return map[C][state];
    }
    if (state == 0x3f){
        if (C % 2 == 0){
            return true;
        }
    }else if (C == 0) {
        return false;
    }
    int flag = 0;
    for (int i = 0; i < 4; i++){
        int next_state;
        next_state = state ^ change[i];
        flag = dfs (C - 1, next_state);
        if (flag == 1) break;
    }
    map[C][state] = flag;
    return flag;

}
bool check(int state){
    if ((state & on) != on) return false;
    if ((state | off) != off) return false;
    return true;
}


int main() {
    ifstream in ("lamps.in");
    ofstream out ("lamps.out");
    
    change[0] = 0x3f;
    change[1] = 0x2A;
    change[2] = 0x15;
    change[3] = 0x24;
    
    
    in >> N >> C;
    for (int i = 0; i < 6; i++){
        onoff[i] = -1;
    }
    
    int temp, flag = 1;
    in >> temp;
    while(flag >= 0){
        if (temp == -1){
            flag--;
            in >> temp;
            continue;
        }
        if (onoff[temp % 6] != -1 && onoff[temp % 6] != flag ){
            out << "IMPOSSIBLE" << endl;
            return 0;
        }
        onoff[temp % 6] = flag;
        in >> temp;
    }
    if (onoff[0] == 1) on = 1;
    if (onoff[0] == -1) off = 1;
    for (int i = 1; i < 6; i++){
        if ( onoff[i] == 1 ) on += (1 << (6 - i));
        if ( onoff[i] == 1 || onoff[i] == -1) off += (1 << (6 - i));
    }
    while (C > 4) {
        C -= 2;
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 0x3f + 1; j++){
            map[i][j] = -1;
        }
    }
    flag = 0;
    for (int state = 0; state <= 0x3f; state++){
        if (check(state) && dfs(C, state)){
            flag = 1;
            int temp = state;
            for (int i = 5; i >= 0; i--){
                result[i] = temp % 2;
                temp /= 2;
            }
            for(int i = 0; i < N; i++){
                out << result[i % 6];
            }
            out << endl;
        }
    }
    if (flag == 0) out <<"IMPOSSIBLE" << endl;
    return 0;
}
