/*
 ID: fenx14
 PROB: prefix
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
vector<string> list;
vector<bool> f(200000);
string str = "";


int main() {

    ifstream in ("prefix.in");
    ofstream out ("prefix.out");
    string temp;
    while(in >> temp && temp != "."){
        list.push_back(temp);
    }
    int cnt = 0;
    char a;
    f[0] = 1;
    while(in >> a){
        str += a;
        cnt++;
        for ( int i = 0; i < list.size(); i++){
            if (cnt >= list[i].size()){
                string temp2 = "";
                for (int j = list[i].size() - 1; j >= 0; j--){
                    char b = str[cnt - j - 1];
                    temp2 += b;
                }
                if (temp2 != list[i]) continue;
                if (f[cnt - list[i].size()]) {
                    f[cnt] = true;
                    break;
                }
            }
        }
    }
    for (int i = cnt; i >= 0; i--){
        if (f[i]){
            out << i << endl;
            break;
        }
        
    }
    
    
    return 0;
}
