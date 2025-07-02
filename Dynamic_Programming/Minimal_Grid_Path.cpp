//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n;
    cin>>n;

    vector<vector<char>> w(n, vector<char> (n));
    for(auto& v:w){
        for(auto& u:v)cin>>u;
    }

    vector<pair<int, int>> f, g;

    f.push_back({0, 0});

    while(!f.empty()){
        auto p = f[0];
        cout<<w[p.first][p.second];

        char m='Z';

        for(auto &[x, y]:f){
            if(x<n-1)m=min(w[x+1][y], m);
            if(y<n-1)m=min(w[x][y+1], m);
        }

        for(auto &[x, y]:f){
            if(x<n-1 && w[x+1][y]==m && (g.empty() || g.back()!=make_pair(x+1, y)))g.push_back({x+1, y});
            if(y<n-1 && w[x][y+1]==m)g.push_back({x, y+1});
        }

        f.clear();
        swap(f, g);
    }

    return 0;
}