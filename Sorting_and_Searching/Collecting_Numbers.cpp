//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, ans=0;
    cin>>n;

    vector<int> a(n), b(n+1, 0);

    for(int i=0; i<n; i++){
        cin>>a[i];
        b[a[i]]=1;

        if(b[a[i]-1]-1)ans++;
    }
    
    cout<<ans;

    return 0;
}