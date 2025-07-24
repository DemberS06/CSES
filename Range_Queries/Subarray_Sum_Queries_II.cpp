// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;

const int sz = 388;
 
struct SQRT{
    int n, bloqs;
    vector<long long> a, b, mx, mn, sub;
    
    SQRT(int _n): n(_n), bloqs((n+sz-1)/sz), a(n+1, 0), mx(bloqs), mn(bloqs), sub(bloqs){}
    
    void update(int p, long long delta){
        int y=min(n, (p+sz-1)/sz*sz);
        
        for(int i=p; i<=y; i++)a[i]+=delta;
    }

    void build(){
        for(int j=0, x=1, y=sz; j<bloqs; j++, x+=sz, y+=sz){
            y=min(y, n);
            mn[j]=0;
            sub[j]=0;
            mx[j]=0;
            for(int i=x; i<=y; i++){
                mn[j]=min(mn[j], a[i]);
                mx[j]=max(mx[j], a[i]);
                sub[j]=max(sub[j], a[i]-mn[j]);
            }
        }
    }

    long long query(int p, int q){
        long long ans=0, low=0, sum=0;
        for(int j=0, x=1, y=sz; j<bloqs; j++, x=y+1, y+=sz){
            if(y<p || x>q)continue;
            
            if(p<=x && y<=q){
                ans=max({ans, mx[j]+sum-low, sub[j]});
                low=min(low, mn[j]+sum);
                sum+=a[y];
                continue;
            }

            if(x<p)sum-=a[p-1], x=p;
            y=min(y, q);

            for(int i=x; i<=y; i++){
                low=min(low, a[i]+sum);
                ans=max(ans, a[i]+sum-low);
            }
            
            sum+=a[y];
        }
        return ans;
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
    }str.build();
 
    while(k--){
        int l, r;
        cin>>l>>r;

        cout<<str.query(l, r)<<"\n";
    }
    
    return k+1;
}