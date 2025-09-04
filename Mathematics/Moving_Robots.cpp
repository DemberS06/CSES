//hola soy Dember :D

#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    vector<vector<int>> adj(64);
    vector<vector<int>> id(8, vector<int>(8));

    for(int i=0, x=0; i<8; i++){
        for(int j=0; j<8; j++)id[i][j]=x++;
    }

    vector<long double> p(64, 0);

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(i>0)p[id[i][j]]++, adj[id[i][j]].push_back(id[i-1][j]);
            if(j>0)p[id[i][j]]++, adj[id[i][j]].push_back(id[i][j-1]);
            if(i<7)p[id[i][j]]++, adj[id[i][j]].push_back(id[i+1][j]);
            if(j<7)p[id[i][j]]++, adj[id[i][j]].push_back(id[i][j+1]);
            p[id[i][j]]=1/p[id[i][j]];
        }
    }

    int n;
    cin>>n;

    vector<vector<vector<long double>>> dp(64, vector<vector<long double>> (64, vector<long double> (n+1, 0)));

    for(int i=0; i<64; i++)dp[i][i][0]=1;

    for(int k=1; k<=n; k++){
        for(int i=0; i<64; i++){
            for(int j=0; j<64; j++){
                for(auto& u:adj[i])dp[i][j][k]+=dp[u][j][k-1]*p[i];
            }
        }
    }

    long double ans=0;

    for(int i=0; i<64; i++){
        long double P=1;
        for(int j=0; j<64; j++){
            P*=1-dp[j][i][n];
        }
        ans+=P;
    }

    cout<<fixed<<setprecision(6)<<ans;

    return 0;
}