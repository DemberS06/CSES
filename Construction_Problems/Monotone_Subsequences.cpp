// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;

void solve(){
    int n, k, x=1;
    cin>>n>>k;
    if(k*k<n){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    vector<int> v(n);

    for(int i=1; i<=(n+k-1)/k; i++){
        for(int j=0; j<k; j++){
            if(i*k-j>n)continue;
            v[i*k-j-1]=x;
            x++;
        }
    }

    for(auto& u:v)cout<<u<<' ';
    cout<<"\n";
}
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int t=1;
    cin>>t;

    while(t--){
        solve();
    }

    return t+1;
}