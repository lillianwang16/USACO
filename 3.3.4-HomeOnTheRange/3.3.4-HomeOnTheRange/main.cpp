/*
 ID: fenx14
 PROB: range
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int> > map(250, vector<int>(250));
vector<int> result(251);
int N;
int main(){
    ifstream in ("range.in");
    ofstream out ("range.out");
    in >> N;
    string st;
    getline(in, st);
    for (int i = 0; i < N; i++){
        getline(in, st);
        for (int j = 0; j < N; j++){
            map[i][j] = st[j] - '0';
        }
    }
    
    for (int i = 1; i < N; i++){
        for (int j = 1; j < N; j++){
            if (map[i][j]){
                int min_area;
                min_area = min(map[i - 1][j], min(map[i][j - 1], map[i - 1][j - 1]));
                map[i][j] = min_area + 1;
            }
        }
    }
    for (int i = 1; i < N; i++){
        for (int j = 1; j < N; j++){
            int cnt = map[i][j];
            for (int k = 2; k <= cnt; k++){
                result[k]++;
            }
        }
    }
    for (int i = 2; i <= N; i++){
        if (result[i]){
            out << i << ' ' << result[i] << endl;
        }
    }

    return 0;
}




/*
using namespace std;
vector<vector<int> > map(250, vector<int>(250));
vector<int> result(251);
int N;

int map_cnt(int num){
    int cnt = 0;
    for (int spx = 0; spx <= N - num; spx++){
        for (int spy = 0; spy <= N - num; spy++){
            bool flag = true;
            for (int x = 0; flag && x < num; x++){
                for (int y = 0; flag && y < num; y++){
                    if (! map[spx + x][spy + y]){
                        flag = false;
                    }
                }
            }
            if (flag){
                cnt++;
            }
        }
    }
    return cnt;
}


int main(){
    ifstream in ("range.in");
    ofstream out ("range.out");
    in >> N;
    string a;
    getline(in, a);
    for (int i = 0; i < N; i++){
        getline(in, a);
        for (int j = 0; j < N; j++){
            map[i][j] = a[j] - '0';
        }
    }
    for (int i = 2; i <= N; i++){
        result[i] = map_cnt(i);
    }
    for (int i = 2; i <= N; i++){
        if (result[i]){
            out << i << ' ' << result[i] << endl;
        }
    }
    return 0;
}
*/
