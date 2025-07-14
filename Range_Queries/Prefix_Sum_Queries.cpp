// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
struct SQRT{
    int n, bloqs;
    vector<long long> a, b, mx;
    
    SQRT(int _n): n(_n), bloqs((n+474)/475), a(n+1, 0), b(n+1, 0), mx(n+1, 0){}
 
    void update(int p, long long delta){
        for(int j=1, x=1, y=475; j<=bloqs; j++, x+=475, y+=475){
            if(y<p)continue;
            if(x>=p){
                b[j]+=delta;
                continue;
            }
            mx[j]=-1e18;
            for(int i=p; i<=y && i<=n; i++)a[i]+=delta;
            for(int i=x; i<=y && i<=n; i++)mx[j]=max(mx[j], a[i]);
        }
    }
 
    long long Query(int l, int r){
        long long ans=-1e18;
        for(int j=1, x=1, y=475; j<=bloqs; j++, x+=475, y+=475){
            if(y<l || x>r)continue;
            if(x>=l && y<=r){
                ans=max(ans, mx[j]+b[j]);
                continue;
            }
            for(int i=max(x, l); i<=y && i<=r; i++)ans=max(ans, a[i]+b[j]);
        }
        return ans;
    }

    long long sum(int p){
        return a[p]+b[(p+474)/475];
    }
 
    long long query(int l, int r){
        return max(Query(l, r)-sum(l-1), 0ll);
    }
};
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, k;
    cin>>n>>k;
 
    SQRT str(n);
    vector<int> a(n+1);
    
    for(int i=1; i<=n; i++){
        cin>>a[i];
        str.update(i, a[i]);
    }
 
    while(k--){
        int x, l, r;
        cin>>x>>l>>r;

        if(x==1)str.update(l, r-a[l]), a[l]=r;
        else cout<<str.query(l, r)<<'\n'; 
    }
    
    return k+1;
}