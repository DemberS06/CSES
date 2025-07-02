//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m; 
    string s="ABCD";

    cin>>n>>m;

    vector<vector<char>> w(n, vector<char> (m));

    for(auto& v:w){
        for(auto& u:v)cin>>u;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int x=1<<(w[i][j]-'A');

            if(i>0)x|=1<<(w[i-1][j]-'A');
            if(j>0)x|=1<<(w[i][j-1]-'A');

            for(int h=0; h<4; h++){
                if((x>>h)&1)continue;
                w[i][j]=s[h];
            }
        }
    }

    for(auto& v:w){
        for(auto& u:v)cout<<u;
        cout<<"\n";
    }
 
    return 0;
}