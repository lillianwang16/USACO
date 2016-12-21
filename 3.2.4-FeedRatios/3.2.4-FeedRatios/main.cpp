/*
 ID: fenx14
 PROB: ratios
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int> > feed(5, vector<int>(4));


using namespace std;
int main(){
    ifstream in ("ratios.in");
    ofstream out ("ratios.out");
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 3; j++){
            in >> feed[i][j];
        }
    }
    vector<int> temp(3), ratio(3);
    int i , j , k;
    for (i = 0; i < 100; i++){
        for (j = 0; j < 100; j++){
            for (k = 0; k < 100; k++){
                for (int l = 0; l < 3; l++){
                    temp[l] = feed[1][l] * i + feed[2][l] * j + feed[3][l] * k;
                    if (feed[0][l] != 0 ){
                        if (temp[l] % feed[0][l] == 0){
                            ratio[l] = temp[l] / feed[0][l];
                        }else{
                            ratio[l] = 0;
                        }
                    }else{
                        if (temp[l] == 0){
                            ratio[l] = -1;
                        }
                    }
                                    }
                bool flag = true;
                for (int l = 1; l < 3; l++){
                    if (ratio[l] != ratio[l - 1] && ratio[l] != -1 && ratio[l - 1] != -1){
                        flag = false;
                    }
                }
                if (flag && ratio[0] != 0){
                    out << i << ' ' << j << ' ' << k << ' ' << ratio[0] << endl;
                    return 0;
                }
            }
        }
    }
    out << "NONE" << endl;
}
