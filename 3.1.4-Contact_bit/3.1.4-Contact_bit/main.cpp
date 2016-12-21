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
struct Node{
    int Index, Count;
    string ss;
};
vector<Node> n(10000);
vector<bool> flag(10000);
ifstream in ("contact.in");
ofstream out ("contact.out");

bool cmp(Node &a, Node &b){
    if (a.Count == b.Count){
        return a.Index < b.Index;
    }else{
        return a.Count > b.Count;
    }
}

int main(){
    in >> A >> B >> N;
    string temp, str;
    int len;
    while(getline(in, temp)){
        str += temp;
    }
    len = str.length();
    for (int i = A; i <= B; i++){
        for (int j = 0; j <= len - i; j++ ){
            int num = 1, cnt = 0;
            while(cnt < i){
                num = num << 1;
                num = num | (int)(str[j + cnt] - '0');
                cnt++;
            }
            n[num].Count++;
            if (n[num].Count == 1){
                n[num].Index = num;
                for (int k = 0; k < i; k++){
                    n[num].ss += str[j + k];
                }
            }
        }
    }
    sort(n.begin(), n.end(), cmp);
    int cnt = 0, row = 0, i = 0;
    while(1){
        if (n[i].Count == 0){
            break;
        }
        if (!flag[n[i].Count]){
            cnt++;
            if (cnt > N){
                break;
            }
            if (cnt != 0){
                out << endl;
            }
            out << n[i].Count << endl;
            out << n[i].ss;
            row = 1;
            flag[n[i].Count] = true;

        }else{
            if (row % 6 == 0){
                out << endl;
                row = 1;
            }
            out  << " " << n[i].ss;
            row++;
        }
        i++;
    }
    out << endl;
    
    return 0;
}
