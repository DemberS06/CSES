//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    long long n, mx=0, sum=0;
    cin>>n;
    
    for(long long i=0, x; i<n; i++){
        cin>>x;
        mx=max(x, mx);
        sum+=x;
    }
    
    cout<<max(sum, 2*mx);

    return 0;
}