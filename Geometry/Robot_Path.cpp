// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

struct Fenwick{
    int n;
    vector<long long> sum;
 
    Fenwick(int _n): n(_n), sum(n+1, 0){}
 
    void update(int i, long long delta){
        for(; i<=n; i+=-i&i)sum[i]+=delta;
    }
 
    long long query(int i){
        long long res=0;
        for(; i>0; i-=-i&i)res+=sum[i];
        return res;
    }
 
    long long query(int l, int r){
        return query(r)-query(l-1);
    }
};

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int n, k=0;
    cin>>n;

    vector<long long> dis, x, y;
    dis.reserve(n+1), x.reserve(n+1), y.reserve(n+1);
    dis.push_back(0); x.push_back(0); y.push_back(0);
    set<long long> f, g;
    string s=" ";

    for(int i=1, d; i<=n; i++){
        char c;
        cin>>c>>d;
        if(s.back()!=c){
            s+=c;
            dis.push_back(dis.back());
            x.push_back(x.back());
            y.push_back(y.back());
        }

        dis.back()+=d;
             if(c=='U')y.back()+=d;
        else if(c=='D')y.back()-=d;
        else if(c=='R')x.back()+=d;
        else if(c=='L')x.back()-=d;
    }n=s.size()-1;

    map<long long, int> a, b;
    vector<long long> l=x, r=y;

    for(auto& u:x)f.insert(u);
    for(auto& u:y)g.insert(u);

    for(auto& u:f)a[u]=++k;k=0;
    for(auto& u:g)b[u]=++k;

    for(auto& u:x)u=a[u];
    for(auto& u:y)u=b[u];

    function<long long(int , int)> touch = [&](int i, int j){
        long long d=1e12;
        if(i==j+1){
                 if(s[j]=='L' && s[i]=='R')return 0ll;
            else if(s[j]=='R' && s[i]=='L')return 0ll;
            else if(s[j]=='U' && s[i]=='D')return 0ll;
            else if(s[j]=='D' && s[i]=='U')return 0ll;

            return d;
        }

        if(x[i]==x[i-1]){
            if(x[j]==x[j-1]){
                if(x[i]!=x[j])return d;

                if(y[i-1]<=y[j] && y[j]<=y[i])d=min(d, r[j]-r[i-1]);
                if(y[i-1]>=y[j] && y[j]>=y[i])d=min(d, r[i-1]-r[j]);

                if(y[i-1]<=y[j-1] && y[j-1]<=y[i])d=min(d, r[j-1]-r[i-1]);
                if(y[i-1]>=y[j-1] && y[j-1]>=y[i])d=min(d, r[i-1]-r[j-1]);

                return d;
            }
            if((x[j-1]<x[i] && x[j]<x[i]) || (x[j-1]>x[i] && x[j]>x[i]))return d;
            if((y[i-1]<y[j] && y[i]<y[j]) || (y[i-1]>y[j] && y[i]>y[j]))return d;
            
            if(r[i-1]<r[j])d=min(d, r[j]-r[i-1]);
            else d=min(d, r[i-1]-r[j]);
            
            return d;
        }
        
        if(y[j]==y[j-1]){
            if(y[i]!=y[j])return d;

            if(x[i-1]<=x[j] && x[j]<=x[i])d=min(d, l[j]-l[i-1]);
            if(x[i-1]>=x[j] && x[j]>=x[i])d=min(d, l[i-1]-l[j]);
            
            if(x[i-1]<=x[j-1] && x[j-1]<=x[i])d=min(d, l[j-1]-l[i-1]);
            if(x[i-1]>=x[j-1] && x[j-1]>=x[i])d=min(d, l[i-1]-l[j-1]);
            
            return d;
        }
        if((y[j-1]<y[i] && y[j]<y[i]) || (y[j-1]>y[i] && y[j]>y[i]))return d;
        if((x[i-1]<x[j] && x[i]<x[j]) || (x[i-1]>x[j] && x[i]>x[j]))return d;
        
        if(l[i-1]<l[j])d=min(d, l[j]-l[i-1]);
        else d=min(d, l[i-1]-l[j]);
        return d;
    };
    
    function<bool(int)> simulation = [&](int d){
        Fenwick fwk(n+1);
        vector<vector<long long>> sweep;
        vector<vector<pair<int, int>>> a(n+1), b(n+1);
        sweep.reserve(d); 
    
        for(int i=1; i<=d; i++){
            if(x[i]==x[i-1])sweep.push_back({x[i], min(y[i-1], y[i]), max(y[i-1], y[i])}), 
                            a[x[i]].push_back({min(y[i], y[i-1]), max(y[i], y[i-1])});
            else sweep.push_back({min(x[i], x[i-1]), -1, y[i]}), 
                 sweep.push_back({max(x[i], x[i-1])+1, -2, y[i]}),
                 b[y[i]].push_back({min(x[i], x[i-1]), max(x[i], x[i-1])});
            if(s[i]=='L' && s[i-1]=='R')return false;
            if(s[i]=='R' && s[i-1]=='L')return false;
            if(s[i]=='U' && s[i-1]=='D')return false;
            if(s[i]=='D' && s[i-1]=='U')return false;
        }
    
        
        for(int i=0; i<=n; i++){
            if(a[i].size()>1){
                sort(a[i].begin(), a[i].end());
                
                for(int j=1; j<a[i].size(); j++)if(a[i][j].first<=a[i][j-1].second)return false;
            }
            if(b[i].size()>1){
                sort(b[i].begin(), b[i].end());
                
                for(int j=1; j<b[i].size(); j++)if(b[i][j].first<=b[i][j-1].second)return false;
            }
        }
        
        sort(sweep.begin(), sweep.end());
        long long ans=0;
    
        for(auto &v:sweep){
            if(v[1]==-1)fwk.update(v[2], 1);
            else if(v[1]==-2)fwk.update(v[2], -1);
            else ans+=fwk.query(v[1], v[2]);
        }

        return ans==d-1;
    };

    int p=0;

    function<void(int, int)> binary = [&](int l, int r){
        if(l>r)return;
        int m=(l+r)/2;
        if(simulation(m))p=m, binary(m+1, r);
        else binary(l, m-1);
    }; binary(1, n);

    long long ans=1e12, d;

    if(p<n){
        for(int i=1; i<=p; i++){
            d=touch(p+1, i);
            ans=min(ans, d);
        }
    }
    if(ans==1e12)ans=0;
    ans+=dis[p];

    cout<<ans;

    return 0;
}