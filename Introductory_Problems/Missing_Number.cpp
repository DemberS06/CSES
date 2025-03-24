//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    long long n, k;
    set<long long> f;
    cin>>n;
    
    for(int i=1; i<=n; i++)f.insert(i);
    
    n--;while(n--){
        cin>>k;
        f.erase(k);
    }
    
    cout<<*f.begin();
 
    return n+1;
}