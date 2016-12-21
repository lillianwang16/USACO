/*
 ID: fenx14
 PROB: contact
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int A, B, N;
map<string, int> list;
vector<pair<int, string> > ans;
char com[11];

void DFS(int i, int depth){
    if (depth == i){
        list[com] = 0;
        return;
    }
    com[depth] = '1';
    DFS(i, depth + 1);
    com[depth] = '0';
    DFS(i, depth + 1);
}

void Init(int A, int B){
    for (int i = A; i <= B; i++){
        DFS(i, 0);
    }
}
bool cmp (pair<int, string> &a, pair<int, string> &b){
    if (a.first == b.first){
        if (a.second.size() == b.second.size()){
            return a.second < b.second;
        }else{
            return a.second.size() < b.second.size();
        }
    }else{
        return a.first > b.first;
    }
}

int main(){
    ifstream in ("contact.in");
    ofstream out ("contact.out");
    in >> A >> B >> N;
    Init(A, B);
    string temp, str;
    int len;
    while(getline(in, temp)){
        str += temp;
    }
    len = str.length();
    for (int i = A; i <= B; i++){
        for (int j = 0; j <= len - i; j++ ){
            string ss = "";
            int num = 0;
            while (num < i){
                ss += str[j + num];
                num++;
            }
            list[ss]++;
        }
    }
    map<string, int> :: iterator it;
    for (it = list.begin(); it != list.end(); it++){
        if (it -> second != 0){
            ans.push_back(make_pair(it -> second, it -> first));
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    int cnt = 0, row, last = 0;
    for (int i = 0; i < ans.size(); i++){
        if (ans[i].first != last){
            if (cnt >= N){
                break;
            }
            if (cnt != 0) {
                out << endl;
            }
            out << ans[i].first << endl << ans[i].second;
            row = 1;
            cnt++;
            last = ans[i].first;
        }else{
            if (row % 6 == 0){
                out << endl << ans[i].second;
                row = 1;
            }else{
                out << " " << ans[i].second;
                row++;
            }
        }
    }
    out << endl;
    return 0;
}
