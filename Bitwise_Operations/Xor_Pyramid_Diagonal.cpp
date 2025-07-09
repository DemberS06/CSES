// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m=1;
    cin>>n;
    while(m<n)m*=2;

    vector<int> a(m, 0);

    for(int i=0; i<n; i++)cin>>a[i];
    
    for(int bit=1; bit<m; bit*=2){
        for(int i=0; i<m; i++){
            if(i&bit)a[i]^=a[i^bit];
        }
    }
    
    for(int i=0; i<n; i++)cout<<a[i]<<' ';
    
    return 0;
}
