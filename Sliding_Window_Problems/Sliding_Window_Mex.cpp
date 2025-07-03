// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, k;
    cin>>n>>k;

    vector<int> a(n);
    map<int, int> mp;
    set<int> f;
    for(int i=0; i<n; i++){
        cin>>a[i];
        f.insert(i);
    }f.insert(n);

    for(int i=0; i<n; i++){
        mp[a[i]]++;
        if(mp[a[i]]==1)f.erase(a[i]);
        if(i>=k-1){
            cout<<*f.begin()<<' '; 
            mp[a[i-k+1]]--;
            if(mp[a[i-k+1]]==0)f.insert(a[i-k+1]);
        }
    }
    
    return 0;
}