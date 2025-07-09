// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, k;
    cin>>n>>k;
    k=n-k;
    
    vector<int> a(n+1, 0);

    for(int i=1; i<=n; i++)cin>>a[i];
    
    for(int bit=1; bit<=k; bit*=2){
        if(k&bit){
            for(int i=1; i+bit<=n; i++)a[i]^=a[i+bit];
        }
    }
    
    for(int i=1; i<=n-k; i++)cout<<a[i]<<' ';
    
    return 0;
}
