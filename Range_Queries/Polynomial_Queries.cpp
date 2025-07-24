// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;

const int sz = 448;
 
struct SQRT{
    int n, bloqs;
    vector<long long> a, b, c;
    
    SQRT(int _n): n(_n), bloqs((n+sz-1)/sz), a(n+1, 0), b(bloqs, 0), c(bloqs, 0){}
    
    void update(int p, long long delta){
        int y=min(n, (p+sz-1)/sz*sz);
        
        for(int i=p; i<=y; i++)a[i]+=delta;
    }

    void update(int j, int x, int y){
        if(!c[j])return;
        for(int i=x; i<=y; i++)a[i]+=b[j]*(i-x+1)+c[j]*(i-x+1)*(i-x+2)/2;
        
        b[j]=c[j]=0;
    }

    void sum(int p, int q){
        long long val;
        for(int j=0, x=1, y=sz, l, r; j<bloqs; j++, x+=sz, y+=sz){
            if(y<p || x>q)continue;
            y=min(y, n);
            
            if(p<=x && y<=q){
                c[j]++;
                b[j]+=x-p;
                continue;
            }

            update(j, x, y);
            
            val=0;
            l=max(x, p), r=min(y, q);

            for(int i=l; i<=r; i++)val+=(i-l+1)+max(0, x-p), a[i]+=val;            
            if(q<y)for(int i=r+1; i<=y; i++)a[i]+=val;
            
        }
    }

    long long query(int p, int q){
        long long ans=0;
        for(int j=0, x=1, y=sz; j<bloqs; j++, x+=sz, y+=sz){
            if(y<p || x>q)continue;
            y=min(y, n);
            
            if(p<=x && y<=q){
                ans+=a[y] + (y-x+1)*b[j] + (y-x+1)*(y-x+2)/2*c[j];

                continue;
            }

            update(j, x, y);

            ans+=a[min(y, q)];
            if(p>x)ans-=a[p-1];
        }
        return ans;
    }
};
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, k;
    cin>>n>>k;
 
    SQRT str(n);
    
    for(int i=1, x; i<=n; i++){
        cin>>x;
        str.update(i, x);
    }
 
    while(k--){
        int t, l, r;
        cin>>t>>l>>r;
        if(t==1)str.sum(l, r);
        else cout<<str.query(l, r)<<"\n";
    }
    
    return k+1;
}