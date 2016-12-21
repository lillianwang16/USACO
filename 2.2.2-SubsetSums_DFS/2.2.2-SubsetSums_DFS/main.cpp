/*
 ID: fenx14
 PROB: subset
 LANG: C++
 */


#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int N, result;

int a[2];
void DFS(int depth){
    if (depth == N){
        if ( a[0] == a[1] ) result++;
        return;
    }
    depth++;
    for (int i = 0; i < 2; i++){
        a[i] += depth;
        DFS(depth);
        a[i] -= depth;
    }

}

/*
 void  DFS(int depth, int a, int b){
    if (depth == N){
        if ( a == b ) result++;
        return;
    }
    depth ++;
    a += depth;
    DFS( depth, a, b );
    a -= depth;
    b += depth;
    DFS( depth, a, b);
    b -= depth;
    
}
*/
int main(){
    
    ifstream in ("subset.in");
    ofstream out ("subset.out");
    
    in >> N;
    DFS(0);
    out << result/2 << endl;
    return 0;
}
