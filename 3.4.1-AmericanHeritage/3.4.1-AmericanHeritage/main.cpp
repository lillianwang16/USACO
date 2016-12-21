/*
 ID: fenx14
 PROB: heritage
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
ifstream in ("heritage.in");
ofstream out ("heritage.out");

void DFS(string in_o, string pre_o){
    if (in_o.empty() || pre_o.empty()){
        return;
    }
    char node = pre_o[0];
    size_t p = in_o.find(node);
    string left_in, left_pre, right_in, right_pre;
    for (int i = 0; i < p; i++){
        left_in += in_o[i];
        left_pre += pre_o[i + 1];
    }
    for (size_t i = p + 1; i < in_o.size(); i++){
        right_in += in_o[i];
        right_pre += pre_o[i];
    }
    DFS(left_in, left_pre);
    DFS(right_in, right_pre);
    out << node;
}

int main(){
    string in_o, pre_o;
    in >> in_o >> pre_o;
    DFS(in_o, pre_o);
    out << endl;
    return 0;
}
