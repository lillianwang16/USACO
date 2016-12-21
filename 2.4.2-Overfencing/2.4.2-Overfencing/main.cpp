/*
 ID: fenx14
 PROB: maze1
 LANG: C++
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
vector<vector<bool> > walls(210, vector<bool>(80));
vector<vector<int> > result(100,vector<int>(40));
int W, H;
int dir[4][2]={-1, 0,
                1, 0,
                0, -1,
                0, 1};

int main(){
    ifstream in ("maze1.in");
    ofstream out ("maze1.out");
    string input;
    in >> W >> H;
    getline(in, input);
    queue<vector<int> > q;
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++ ){
            result[i][j] = -1;
        }
    }
    for (int i = 0; i < 2 * H + 1; i++){
        getline(in, input);
        for (int j = 0; j < 2 * W + 1; j++){
            if (input[j] == ' '){
                walls[i][j] = true;
                if (i == 0 || i == 2 * H || j == 0 || j == 2 * W ){
                    vector<int> temp(2);
                    temp[0] = ( i - 1 ) / 2;
                    temp[1] = ( j - 1 ) / 2;
                    q.push(temp);
                    result[temp[0]][temp[1]] = 1;
                }
            }
        }
    }

    while (!q.empty()){
        vector<int> temp(2);
        temp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++){
            vector<int> next(2), next_wall(2);
            for (int j = 0; j < 2; j++){
                next[j] = temp[j] + dir[i][j];
                next_wall[j] = 2 * temp[j] + 1 + dir[i][j];
            }
            if (next[0] >= 0 && next[0] < H && next[1] >= 0 && next[1] < W ){
                if (walls[next_wall[0]][next_wall[1]] == true){
//                  if ( result[next[0]][next[1]] == -1 || result[temp[0]][temp[1]] + 1 < result[next[0]][next[1]] ){
                    if (result[next[0]][next[1]] == -1){ //since BFS, first enter the room, shortest path
                        result[next[0]][next[1]] = result[temp[0]][temp[1]] + 1;
                        q.push(next);
                    }
                }
            }
        }
    }
    int m = 0;
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++ ){
            m = max(m, result[i][j]);
        }
    }
    out << m << endl;
    
    return 0;
}
