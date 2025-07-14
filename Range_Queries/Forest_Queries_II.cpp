// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
struct Fenwick{
    int n;
    vector<vector<int>> sum;

    Fenwick(int _n): n(_n), sum(n+1, vector<int> (n+1, 0)){}
 
    void update(int i, int x, int delta){
        for(; i<=n; i+=-i&i){
            for(int j=x; j<=n; j+=-j&j){
                sum[i][j]+=delta;
            }
        }
    }
 
    int query(int i, int x){
        int res=0;
        for(; i>0; i-=-i&i){
            for(int j=x; j>0; j-=-j&j){
                res+=sum[i][j];
            }
        }
        return res;
    }
 
    int query(int l, int r, int x, int y){
        return query(x, y)+query(l-1, r-1)-query(x, r-1)-query(l-1, y);
    }
};
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, k;
    cin>>n>>k;
 
    vector<vector<int>> a(n+1, vector<int> (n+1));
    Fenwick fwk(n);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            char c;
            cin>>c;
            a[i][j]=(c=='*');
            fwk.update(i, j, a[i][j]);
        }
    }

    while(k--){
        int t;
        cin>>t;
        if(t==1){
            int i, j;
            cin>>i>>j;
            fwk.update(i, j, -a[i][j]);
            a[i][j]^=1;
            fwk.update(i, j, a[i][j]);
        }
        else{
            int l, r, x, y;
            cin>>l>>r>>x>>y;
            cout<<fwk.query(l, r, x, y)<<"\n";
        }
    }
    
    return k+1;
}