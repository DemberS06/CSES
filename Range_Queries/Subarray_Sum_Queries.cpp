// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;

const int sz = 388;
 
struct SQRT{
    int n, bloqs;
    vector<long long> a, b, mx, mn, sub;
    
    SQRT(int _n): n(_n), bloqs((n+sz-1)/sz), a(n+1, 0), b(bloqs, 0), mx(bloqs), mn(bloqs), sub(bloqs){}
    
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

            if(j)b[j]=b[j-1];
            b[j]+=a[x-1];
        }
    }

    long long query(int p, long long delta){
        long long ans=0, low=0;
        for(int j=0, x=1, y=sz; j<bloqs; j++, x+=sz, y+=sz){
            y=min(y, n);
            if(x<=p && y>=p){
                mn[j]=0;
                sub[j]=0;
                mx[j]=0;
                for(int i=x; i<=y; i++){
                    if(i>=p)a[i]+=delta;
                    mn[j]=min(mn[j], a[i]);
                    mx[j]=max(mx[j], a[i]);
                    sub[j]=max(sub[j], a[i]-mn[j]);
                }
            }
            if(x>p)b[j]+=delta;
            
            ans=max({ans, mx[j]+b[j]-low, sub[j]});
            low=min(low, mn[j]+b[j]);
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

        cout<<str.query(l, r-a[l])<<"\n";
        a[l]=r; 
    }
    
    return k+1;
}