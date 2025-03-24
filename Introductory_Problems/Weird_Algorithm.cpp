//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
void f(long long n){
    cout<<n<<' ';
    if(n==1)return;
    if(n%2==0){f(n/2);}
    else f(3*n+1);
    
    return;
}
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    long long n;
    cin>>n;
    f(n);
 
    return 0;
}