//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, x;
    cin>>n>>x;

    vector<int> a(n), b(n);

    for(int i=0; i<n; i++){
        cin>>a[i];
        b[i]=i;
    }

    sort(b.begin(), b.end(), [&](int& x, int& y){
        return a[x]<a[y];
    });

    for(int i=0, j=n-1; i<n; i++){
        while(j>i && a[b[i]]+a[b[j]]>x)j--;
        if(a[b[i]]+a[b[j]]!=x || i==j)continue;
        cout<<b[j]+1<<' '<<b[i]+1;
        return 0;
    }

    cout<<"IMPOSSIBLE";
    
    return 0;
}