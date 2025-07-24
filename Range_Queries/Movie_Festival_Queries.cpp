// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

struct BL{
    int n, k;
    vector<vector<int>> nxt;
    
    BL(int _n, int _k): n(_n), k(_k), nxt(n+5, vector<int> (k, n+1)){}

    void update(int x, int y){
        nxt[x][0]=min(nxt[x][0], y);
    }

    void build(){
        for(int i=n; i>=0; i--)nxt[i][0]=min(nxt[i][0], nxt[i+1][0]);

        for(int h=1; h<k; h++){
            for(int i=1; i<=n; i++){
                nxt[i][h]=nxt[nxt[i][h-1]][h-1];
            }
        }
    }

    long long query(int l, int r){
        long long ans=0;

        for(int h=k-1; h>=0; h--){
            if(nxt[l][h]>r)continue;
            ans+=(1<<h);
            l=nxt[l][h];
        }

        return ans;
    }
};

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;

    BL str(1e6, 21);
    
    for(int i=1, x, y; i<=n; i++){
        cin>>x>>y;
        str.update(x, y);
    }str.build();

    while(m--){
        int l, r;
        cin>>l>>r;

        cout<<str.query(l, r)<<"\n";
    }

    return m+1;
}