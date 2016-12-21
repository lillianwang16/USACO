/*
 ID: fenx14
 PROB: msquare
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

string goal;
map<string, int> visited;
struct Node{
    string state;
    int cnt;
    string path;
};
queue<Node> q;

ifstream in ("msquare.in");
ofstream out ("msquare.out");

string switch_s(string s, int a, int b){
    char temp = s[a];
    s[a] = s[b];
    s[b] = temp;
    return s;
}

string change(string s, int i){
    string ss;
    if (i == 1){
        for (int i = 7; i >= 0; i--){
            ss += s[i];
        }
    }
    if (i == 2){
        char a = s[3];
        char b = s[4];
        ss = s;
        ss = ss.erase(3, 2);
        ss = a + ss + b;
    }
    if (i == 3){
        ss = switch_s(s, 1, 2);
        ss = switch_s(ss, 5, 6);
        ss = switch_s(ss, 1, 5);
    }
    return ss;
}


void BFS(){
    while(!q.empty()){
        Node temp = q.front();
        q.pop();
        string s = temp.state;
        if (s == goal){
            out << temp.cnt << endl << temp.path << endl;
            return;
        }
        for (int i = 1; i <= 3; i++){
            string ss = change(s, i);
            if (!visited[ss]){
                visited[ss] = 1;
                Node new_temp;
                new_temp.state = ss;
                new_temp.cnt = temp.cnt + 1;
                new_temp.path = temp.path + char('A' + i - 1);
                q.push(new_temp);
            }
        }
    }
}


int main(){
    string a;
    for (int i = 0; i < 8; i++){
        in >> a;
        goal += a;
    }
    string start = "12345678";
    visited[start] = 1;
    Node temp;
    temp.state = start;
    temp.cnt = 0;
    q.push(temp);
    BFS();
    string s = change(start, 3);
    return 0;
}
