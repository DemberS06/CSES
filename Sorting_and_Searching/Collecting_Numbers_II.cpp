//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m, ans=-1;
    cin>>n>>m;

    vector<int> a(n), b(n+2, 0); b[n+1]=n;

    for(int i=0; i<n; i++){
        cin>>a[i];
        b[a[i]]=i;

        if(!b[a[i]-1])ans++;
    }
    
    for(int i=0, x, y; i<m; i++){
        cin>>x>>y; x--; y--;
        
        if(b[a[x]-1]>b[a[x]])ans--;
        if(b[a[x]+1]<b[a[x]])ans--;
        if(b[a[y]-1]>b[a[y]] && a[y]-1!=a[x])ans--;
        if(b[a[y]+1]<b[a[y]] && a[y]+1!=a[x])ans--;
        
        swap(b[a[x]], b[a[y]]);
        swap(a[x], a[y]);

        if(b[a[x]-1]>b[a[x]])ans++;
        if(b[a[x]+1]<b[a[x]])ans++;
        if(b[a[y]-1]>b[a[y]] && a[y]-1!=a[x])ans++;
        if(b[a[y]+1]<b[a[y]] && a[y]+1!=a[x])ans++;

        cout<<ans<<"\n";
    }

    return 0;
}