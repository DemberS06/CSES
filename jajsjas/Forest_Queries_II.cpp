#include <bits/stdc++.h>

using namespace std;

const int N=1001;

int n, m, fwk[N][N], a[N][N];

void act(int x, int y, int k){
    for(int i=x; i<=n; i+=-i&i){
        for(int j=y; j<=n; j+=-j&j){
            fwk[i][j]+=k;
        }
    }
    return;
}

int que(int x, int y){
    int ans=0;
    for(int i=x; i>0; i-=-i&i){
        for(int j=y; j>0; j-=-j&j){
            ans+=fwk[i][j];
        }
    }
    return ans;
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin>>n>>m; char c;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>c;
            if(c=='*')a[i][j]++, act(i, j, 1);
        }
    }

    for(int t, p, q, x, y; m; m--){
        cin>>t;
        if(t==1){
            cin>>x>>y;
            if(a[x][y])act(x, y, -1);
            else act(x, y, +1);
            a[x][y]^=1;
        }
        else{
            cin>>p>>q>>x>>y;
            cout<<que(x, y)+que(p-1, q-1)-que(x,q-1)-que(p-1, y)<<"\n";
        }
    }

    return 0;
}