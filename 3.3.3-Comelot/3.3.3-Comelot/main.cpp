/*
 ID: fenx14
 PROB: camelot
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
int dist[31][27][31][27];
int Knight_d[8][2] =
{
    {-2,1},{-1,2},{1,2},{2,1},
    {2,-1},{1,-2},{-2,-1},{-1,-2},
};
int R, C;
int ori[1000][2] = {0};


void BFS(int x0, int y0){
    vector<int> temp(2);
    temp[0] = x0;
    temp[1] = y0;
    queue<vector<int> > q;
    q.push(temp);
    dist[x0][y0][x0][y0] = 0;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        int step = dist[x0][y0][temp[0]][temp[1]];
        for (int i = 0 ; i < 8; i++){
            int x = temp[0] + Knight_d[i][0];
            int y = temp[1] + Knight_d[i][1];
            if (x > 0 && y > 0 && x <= R && y <= C && dist[x0][y0][x][y] == -1){
                vector<int> next(2);
                next[0] = x;
                next[1] = y;
                q.push(next);
                dist[x0][y0][x][y] = step + 1;
            }
        }
    }
}
int main(){
    ifstream in ("camelot.in");
    ofstream out ("camelot.out");
    in >> R >> C;
    int r0, c0, n = 0;
    char cc0;
    while (in >> cc0 >> r0){
        c0 = cc0 - 'A' + 1;
        ori[n][0] = r0;
        ori[n][1] = c0;
        n++;
    }
    n--;
    if (n == 0) {
        out << 0 << endl;
        return 0;
    }
    memset(dist, -1, sizeof(dist));
    for (int i = 1; i <= R; i++){
        for (int j = 1; j <= C; j++){
            BFS(i, j);
        }
    }
    int total = 0x7fffffff;
    for (int i = 1; i <= R; i++){
        for (int j = 1; j <= C; j++){
            int sum = 0, flag = true;
            for (int k = 1; k <= n; k++){
                int x0 = ori[k][0];
                int y0 = ori[k][1];
                if (dist[x0][y0][i][j] == -1){
                    flag = false;
                    break;
                }else{
                    sum += dist[x0][y0][i][j];
                }
            }
            if (!flag){
                continue;
            }
            total = min(total, sum + max(abs(ori[0][0] - i), abs(ori[0][1] - j)));
            
            for (int k = 1; k <= n; k++){
                int x0 = ori[k][0];
                int y0 = ori[k][1];
                int ssum = sum - dist[x0][y0][i][j];
                if (ssum < total && ssum >= 0){
                    for (int xk = 1; xk <= R; xk++){
                        for (int yk = 1; yk <= C; yk++){
                            if (dist[x0][y0][xk][yk] != -1 && dist[xk][yk][i][j] != -1){
                                int sssum = ssum + dist[x0][y0][xk][yk] + dist[xk][yk][i][j] + max(abs(ori[0][0] - xk),  abs(ori[0][1] - yk));
                                total = min(total, sssum);
                            }
                        }
                    }
                }
            }
        }
    }

    out << total << endl;
    
    return 0;

}
