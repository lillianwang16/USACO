/*
 ID: fenx14
 PROB: ttwo
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;
int Cx, Cy, Fx, Fy, dir_C = 0, dir_F = 0, cnt = 0;
vector<vector<int> > map(10, vector<int>(10));
bool visited[10][10][4][10][10][4];
int Move[4][2] =
    {-1, 0,
    0, 1,
    1, 0,
    0, -1};


int main(){
    ifstream in ("ttwo.in");
    ofstream out ("ttwo.out");
    char temp;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            in >> temp;
            switch (temp){
                case '.': map[i][j] = 0;break;
                case '*': map[i][j] = 1;break;
                case 'C': Cx = i; Cy = j; break;
                case 'F': Fx = i; Fy = j; break;
            }
        }
    }

    while(true){
        if (visited[Cx][Cy][dir_C % 4][Fx][Fy][dir_F % 4]){
                out << 0 << endl;
                return 0;
        }
        visited[Cx][Cy][dir_C % 4][Fx][Fy][dir_F % 4] = true;
        
        if (Cx + Move[dir_C % 4][0] < 0 || Cx + Move[dir_C % 4][0] >= 10 || Cy + Move[dir_C % 4][1] < 0 || Cy + Move[dir_C % 4][1] >= 10 || map[Cx + Move[dir_C % 4][0]][Cy + Move[dir_C % 4][1]] ){
            dir_C++;
        }else{
            Cx += Move[dir_C % 4][0];
            Cy += Move[dir_C % 4][1];
        }
        if (Fx + Move[dir_F % 4][0] < 0 || Fx + Move[dir_F % 4][0] >= 10 || Fy + Move[dir_F % 4][1] < 0 || Fy + Move[dir_F % 4][1] >= 10 || map[Fx + Move[dir_F % 4][0]][Fy + Move[dir_F % 4][1]]){
            dir_F++;
        }else{
            Fx += Move[dir_F % 4][0];
            Fy += Move[dir_F % 4][1];
        }
        cnt++;
        if (Cx == Fx && Cy == Fy){
            out << cnt << endl;
            return 0;
        }
    }
    
    
    return 0;
}

/*
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;
int Cx, Cy, Fx, Fy, dir_C = 0, dir_F = 0, cnt = 0;
vector<vector<int> > map(10, vector<int>(10));
vector<vector<int> > map_visited_C(10, vector<int>(10));
vector<vector<int> > map_visited_F(10, vector<int>(10));
vector<int> dir_visited_C, dir_visited_F;
int Move[4][2] = {-1, 0,
                  0, 1,
                  1, 0,
                  0, -1};


int main(){
    ifstream in ("ttwo.in");
    ofstream out ("ttwo.out");
    char temp;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            in >> temp;
            switch (temp){
                case '.': map[i][j] = 0;break;
                case '*': map[i][j] = 1;break;
                case 'C': Cx = i; Cy = j; break;
                case 'F': Fx = i; Fy = j; break;
            }
        }
    }
    int flag1 = false, flag2 = false;
    while(true){
        if (map_visited_C[Cx][Cy] && map_visited_F[Fx][Fy] && map_visited_C[Cx][Cy] == map_visited_F[Fx][Fy] && dir_visited_C[map_visited_C[Cx][Cy]] == dir_visited_F[map_visited_F[Fx][Fy]]){
            if (flag1 == true && flag2 == true){
                out << 0 << endl;
                return 0;
            }else if (flag1 == false){
                flag1 = true;
            }else if (flag2 == false){
                flag2 = true;
            }
        }
        map_visited_C[Cx][Cy] = cnt;
        map_visited_F[Fx][Fy] = cnt;
        dir_visited_C.push_back(dir_C % 4);
        dir_visited_F.push_back(dir_F % 4);
        
        if (Cx + Move[dir_C % 4][0] < 0 || Cx + Move[dir_C % 4][0] >= 10 || Cy + Move[dir_C % 4][1] < 0 || Cy + Move[dir_C % 4][1] >= 10 || map[Cx + Move[dir_C % 4][0]][Cy + Move[dir_C % 4][1]] ){
            dir_C++;
        }else{
            Cx += Move[dir_C % 4][0];
            Cy += Move[dir_C % 4][1];
        }
        if (Fx + Move[dir_F % 4][0] < 0 || Fx + Move[dir_F % 4][0] >= 10 || Fy + Move[dir_F % 4][1] < 0 || Fy + Move[dir_F % 4][1] >= 10 || map[Fx + Move[dir_F % 4][0]][Fy + Move[dir_F % 4][1]]){
            dir_F++;
        }else{
            Fx += Move[dir_F % 4][0];
            Fy += Move[dir_F % 4][1];
        }
        cnt++;
        if (Cx == Fx && Cy == Fy){
            out << cnt << endl;
            return 0;
        }
    }
    
    
    return 0;
}
*/
