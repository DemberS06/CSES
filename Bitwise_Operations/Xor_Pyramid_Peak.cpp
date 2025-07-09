// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, ans=0;
    cin>>n;
    vector<int> f(n, 0);
    
    for(int i=1, x; i<n; i++){
        f[i]=f[i-1];
        x=i;
        while(!(x&1))x/=2, f[i]++;
    }

    for(int i=0, x; i<n; i++){
        cin>>x;
        if(f[n-1]==f[i]+f[n-i-1])ans^=x;
    }
    
    cout<<ans;

    return 0;
}
