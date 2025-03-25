//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
const long long N=2e5+5;
 
long long n, a[N], b[N], sgt[4*N], ans=1, xd, zd;
set<long long> f;
map<long long, long long> mp;
 
long long que(long long l=1, long long r=N-1, long long i=1){
    if(l>r || r<xd)return 0;
    if(l>=xd)return sgt[i];
    return max(que(l, l+r>>1, 2*i), que((l+r>>1)+1, r, 2*i+1));
}
void bld(long long l=1, long long r=N-1, long long i=1){
    if(l>r || l>xd || r<xd)return;
    sgt[i]=max(zd, sgt[i]);
    if(l==r)return;
    bld(l, l+r>>1, 2*i), bld((l+r>>1)+1, r, 2*i+1);
    return;
}
 
int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        f.insert(a[i]);
    }
    for(auto u:f)mp[u]=ans, ans++;
    
    for(int i=1; i<=n; i++)a[i]=mp[a[i]];
    
    for(int i=n; i>0; i--){
        xd=a[i]+1;
        zd=b[i]=que()+1;xd--;
        bld();
    }
    
    sort(b+1, b+n+1);
    
    cout<<b[n];
    
    return 0;
}