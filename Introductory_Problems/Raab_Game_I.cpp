//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;

void solve(){
    int n, a, b;
    
    cin>>n>>a>>b;
    if(b+a>n || (a && !b) || (!a && b)){
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";

    vector<int> l, r;
    int x=1, y=1;  

    while(a>1 && b>1){
        l.push_back(x); l.push_back(x+1);
        r.push_back(y+1); r.push_back(y);
        a--; x+=2;
        b--; y+=2;
    }

    while(a>0 && b==1){
        l.push_back(y+1); r.push_back(y);
        a--; y++;
    }

    while(a==1 && b>0){
        l.push_back(x); r.push_back(x+1);
        b--; x++;
    }

    l.push_back(x); r.push_back(y);
    
    for(int i=max(x, y)+1; i<=n; i++){
        l.push_back(i);
        r.push_back(i);
    }

    for(auto& u:l)cout<<u<<' '; cout<<"\n";
    for(auto& u:r)cout<<u<<' '; cout<<"\n";

}
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int t=1;
    cin>>t;
    
    while(t--)solve();

    return t+1;
}