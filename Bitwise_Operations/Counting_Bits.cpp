// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;

long long f(long long n, long long x){
    if(x>2*n)return 0;
    return (n/x)*(x/2) + max(0ll, n%x-x/2) + f(n, 2*x);
}
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    long long n;
    cin>>n;

    cout<<f(n+1, 2);

    return 0;
}