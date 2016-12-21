/*
ID: fenx14
PROB: spin
LANG: C++
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

struct wedge{
    int s, e;
};
wedge a[5][30];
wedge a0[5][30];
int num[5];
int v[5];

void cha(queue<wedge> &cover, wedge c, wedge temp){
     if (c.e < temp.s || temp.e < c.s){
        return;
    }
    wedge next;
    next.s = max(c.s, temp.s);
    next.e = min(c.e, temp.e);
    cover.push(next);
    return;
}

bool check(int time){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < num[i]; j++){
            a[i][j].s = (a0[i][j].s + v[i] * time) % 360;
            a[i][j].e = (a[i][j].s + a0[i][j].e) % 360;
        }
    }

    queue<wedge> cover;
    for (int j = 0; j < num[0]; j++){
        if (a[0][j].e < a[0][j].s){
            wedge temp1 = a[0][j];
            temp1.e = 359;
            wedge temp2 = a[0][j];
            temp2.s = 0;
            cover.push(temp1);
            cover.push(temp2);
        }else{
            cover.push(a[0][j]);
        }
        
    }

    for (int i = 1; i < 5; i++){
        if (cover.size() == 0){
            break;
        }
        int k_size = cover.size();
        for (int k = 0; k < k_size; k++){
            wedge c = cover.front();
            cover.pop();
            for (int j = 0; j < num[i]; j++){
                wedge temp = a[i][j];
                if (temp.e < temp.s){
                    wedge temp1 = a[i][j];
                    temp1.e = 359;
                    wedge temp2 = a[i][j];
                    temp2.s = 0;
                    cha(cover, c, temp1);
                    cha(cover, c, temp2);
                }else{
                    cha(cover, c, temp);
                }
            }
        }
    }
    if (cover.size() > 0){
        return true;
    }else {
        return false;
    }
}

int main(){
    ifstream in ("spin.in");
    ofstream out ("spin.out");
    for (int i = 0; i < 5; i++){
        in >> v[i] >> num [i];
        for(int j = 0; j < num[i]; j++){
            in >> a0[i][j].s >> a0[i][j].e;
        }
    }

    for (int time = 0; time < 360; time++){
        if (check(time)){
            out << time << endl;
            return 0;
        }
    }
    out << "none" << endl;
    
    return 0;
}


