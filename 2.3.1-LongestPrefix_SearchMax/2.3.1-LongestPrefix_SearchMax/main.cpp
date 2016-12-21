/*
 ID: fenx14
 PROB: prefix
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;
char list[200][11];
int Max = 0;
string str = "";

int main() {
    ifstream in ("prefix.in");
    ofstream out ("prefix.out");
    int acc = 0;
    while (in >> list[acc] && list[acc++][0] != '.');
    string a;
    while (in >> a){
        str += a;
    }
    for (int i = 0; i < str.length(); i++){
        for (int j = 0; j < acc; j++){
            if(str.length() >= i + strlen(list[j])){
                bool flag = true;
                for (int k = 0; k < strlen(list[j]); k++){
                    if (str[i + k] != list[j][k] ){
                        flag = false;
                        break;
                    }
                }
                if (flag){
                    if (Max < i + strlen(list[j])){
                        Max = i + strlen(list[j]);
                    }
                }
            }
        }
        if (Max < i + 1){
            break;
        }
        
    }
    out << Max << endl;
    
    return 0;
}
