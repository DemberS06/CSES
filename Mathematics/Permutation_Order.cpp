// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    vector<long long> f(21, 1);
    for(int i=1; i<=20; i++)f[i]=f[i-1]*i;

    auto P = [&](int n, long long k){
        vector<int> ans, vis(n+1, 0);
        int x;
        while(n--){
            x=(k+f[n]-1)/f[n];
            k-=(x-1)*f[n];
            for(int i=1; x; i++){
                if(vis[i])continue;
                x--;
                if(!x)ans.push_back(i), vis[i]=1;
            }
        }

        return ans;
    };

    auto Q = [&](int n, vector<int> p){
        vector<int> vis(n, 0);
        long long ans=1, x=0;
        for(auto& u:p){
            for(int i=0; i<u; i++){
                if(vis[i])continue;
                x++;
            }
            ans+=(x-1)*f[--n];
            vis[u-1]=1; x=0;
        }
        return ans;
    };

    int t;
    cin>>t;

    while(t--){
        int x, n;
        cin>>x>>n;
        
        vector<int> p;
        long long k;
        if(x==1){
            cin>>k;
            p=P(n, k);
            for(auto& u:p)cout<<u<<' ';
            cout<<"\n";
        }
        else{
            p.resize(n);
            for(auto& u:p)cin>>u;
            k=Q(n, p);
            cout<<k<<"\n";
        }
    }

    return 0;
}