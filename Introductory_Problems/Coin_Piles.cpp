//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
void value(int in){cout<<((in)?"YES\n":"NO\n");return;}
 
void solve(){
    long long n, m;
    cin>>n>>m;
    
    if(2*m<n || 2*n<m)return value(0);
    if((n+m)%3==0)return value(1);
    value(0);
    
    return;
}
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int t=1;
    cin>>t;
    
    while(t--)solve();
 
    return t+1;
}