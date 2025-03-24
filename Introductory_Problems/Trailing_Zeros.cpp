//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
long long n;
 
long long f(long long k){
    if(k>n)return 0;
    return n/k+f(k*5);
}
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    cin>>n;
    
    cout<<f(5);
 
    return 0;
}