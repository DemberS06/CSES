//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;

const long long md=1e9+7;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    long long n, ans=1;
    cin>>n;
    
    while(n--)ans=2*ans%md;

    cout<<ans<<"\n";
 
    return n+1;
}