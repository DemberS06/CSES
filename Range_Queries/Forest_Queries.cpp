// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, q;
    cin>>n>>q;

    vector<vector<int>> a(n+1, vector<int> (n+1, 0));
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            char c;
            cin>>c;
            
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+(c=='*');
        }
    }
    
    while(q--){
        int l, r, x, y;
        cin>>l>>r>>x>>y;
        
        cout<<a[x][y]-a[x][r-1]-a[l-1][y]+a[l-1][r-1]<<"\n";
    }
    
    return q+1;
}