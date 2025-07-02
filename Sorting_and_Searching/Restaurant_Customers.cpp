//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, ans=0;
    cin>>n;

    vector<int> a(n), b(n);

    for(int i=0; i<n; i++)cin>>a[i]>>b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    for(int i=0, j=0; i<n; i++){
        while(j<n && b[j]<a[i])j++;
        ans=max(i-j+1, ans);
    }

    cout<<ans;
    
    return 0;
}