//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n;
    cin>>n;

    vector<vector<int>> w(n, vector<int> (n, 0));
    int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
    
    queue<pair<int, int>> q;

    q.push({0, 0});

    while(!q.empty()){
        auto [x, y]=q.front();
        q.pop();

        for(int h=0; h<8; h++){
            int nx=x+dx[h], ny=y+dy[h];
            if(nx<0 || nx>=n || ny<0 || ny>=n || w[nx][ny])continue;
            w[nx][ny]=w[x][y]+1;
            q.push({nx, ny});
        }
    }

    w[0][0]=0;

    for(auto& v:w){
        for(auto & u:v)cout<<u<<' ';
        cout<<"\n";
    }
 
    return 0;
}