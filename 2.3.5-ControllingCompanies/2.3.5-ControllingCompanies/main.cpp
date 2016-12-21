/*
 ID: fenx14
 PROB: concom
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;


int main(){
    vector<vector<int> > perc(101, vector<int>(101));
    queue<vector<int> > q;
    ifstream in ("concom.in");
    ofstream out ("concom.out");
    int n, m = 0;
    in >> n;
    for (int cnt = 0; cnt < n; cnt++){
        int i, j;
        in >> i >> j;
        m = max(m, max(i, j));
        in >> perc[i][j];
    }
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= m; j++){
            if (perc[i][j] > 50){
                vector<int> a(2);
                a[0] = i;
                a[1] = j;
                q.push(a);
            }
        }
    }//find company B control company C
    while (!q.empty()){
        vector<int> temp = q.front();
        q.pop();
        /*for (int i = 1; i <= m; i++){
            if (perc[i][temp[0]] > 50){
                if (perc[i][temp[1]] <= 50){
                    perc[i][temp[1]] += perc[temp[0]][temp[1]];
                    if (perc[i][temp[1]] > 50 ){
                        vector<int> a(2);
                        a[0] = i;
                        a[1] = temp[1];
                        q.push(a);
                    }
                }
            }
        }// update companies A which control B
         */
        for (int j = 1; j <= m; j++){
            if (perc[temp[0]][j] <= 50){
                perc[temp[0]][j] += perc[temp[1]][j];
                if (perc[temp[0]][j] > 50){
                    vector<int> a(2);
                    a[0] = temp[0];
                    a[1] = j;
                    q.push(a);
                }
            }
            
        }// update whether companies B control the companies C controls
    }
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= m; j++){
            if (perc[i][j] > 50 && i != j){
                out << i << ' ' << j << endl;
            }
        }
    }
    
    return 0;
}
