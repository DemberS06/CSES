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
        if(b[j])     for(int i=x; i<=y; i++)a[i]= (i-x+1) * (b[j]+c[j]);
        else if(c[j])for(int i=x; i<=y; i++)a[i]+=(i-x+1) *       c[j] ;
        
        b[j]=c[j]=0;
    }

    void sum(int p, int q, long long delta){
        long long val;
        for(int j=0, x=1, y=sz, l, r; j<bloqs; j++, x+=sz, y+=sz){
            if(y<p || x>q)continue;
            y=min(y, n);
            
            if(p<=x && y<=q){
                c[j]+=delta;
                continue;
            }

            update(j, x, y);
            
            val=0;
            l=max(x, p), r=min(y, q);

            if(q<y)for(int i=r+1; i<=y; i++)a[i]+=(r-l+1)*delta;
            
            for(int i=l; i<=r; i++)val+=delta, a[i]+=val;            
        }
    }

    void set(int p, int q, long long delta){
        long long val;
        for(int j=0, x=1, y=sz, l, r; j<bloqs; j++, x+=sz, y+=sz){
            if(y<p || x>q)continue;
            y=min(y, n);
            
            if(p<=x && y<=q){
                c[j]=0;
                b[j]=delta;
                continue;
            }

            update(j, x, y);
            
            if(p>x)val=a[p-1];
            else val=0;
            l=max(x, p), r=min(y, q);

            if(q<y)for(int i=r+1; i<=y; i++)a[i]+=val-a[r]+(r-l+1)*delta;

            for(int i=l; i<=r; i++)val+=delta, a[i]=val;            
        }
    }

    long long query(int p, int q){
        long long ans=0;
        for(int j=0, x=1, y=sz; j<bloqs; j++, x+=sz, y+=sz){
            if(y<p || x>q)continue;
            y=min(y, n);
            
            if(p<=x && y<=q){
                if(b[j])ans+=(y-x+1)*(b[j]+c[j]);
                else ans+=a[y]+(y-x+1)*c[j];
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
        int t, l, r, x;
        cin>>t>>l>>r;
        if(t==1){
            cin>>x;
            str.sum(l, r, x);
        }
        if(t==2){
            cin>>x;
            str.set(l, r, x);
        }
        if(t==3)cout<<str.query(l, r)<<"\n";
    }
    
    return k+1;
}