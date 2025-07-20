// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

struct SGT{
    int n;
    vector<long long> sgt;
    vector<int> a;
    
    SGT(int _n): n(_n), sgt(4*n, 0){}

    void build(int i, int l, int r){
        if(l==r){
            sgt[i]=l;
            return;
        }
        build(2*i+1, l, (l+r)/2);
        build(2*i, (l+r)/2+1, r);
        
        int x=sgt[2*i], y=sgt[2*i+1];

        if(a[x]==a[y])sgt[i]=min(x, y);
        else{
            if(a[x]>a[y])sgt[i]=x;
            else sgt[i]=y;
        }
    }

    void build(){
        build(1, 0, n-1);
    }

    long long query(int p, int q, int i, int l, int r){
        if(l>r || l>q || r<p)return q;
        if(l>=p && r<=q)return sgt[i];
        int x=query(p, q, 2*i+1, l, (l+r)/2), y=query(p, q, 2*i, (l+r)/2+1, r);

        if(a[x]==a[y])return min(x, y);
        if(a[x]>a[y])return x;
        return y;
    }

    long long query(int l, int r){
        return query(l, r, 1, 0, n-1);
    }
};

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;

    vector<int> a(n), b(n), dp(n+1, 0), st;
    st.reserve(n);

    for(auto& u:a)cin>>u;

    for(int i=0; i<n; i++){
        while(!st.empty() && a[st.back()]<a[i])b[st.back()]=i, st.pop_back();
        st.push_back(i);
    }while(!st.empty())b[st.back()]=n, st.pop_back();

    for(int i=n-1; i>=0; i--)dp[i]=dp[b[i]]+1;

    SGT sgt(n);
    sgt.a=a;
    sgt.build();

    while(m--){
        int l, r;
        cin>>l>>r; l--; r--;
        cout<<dp[l]-dp[sgt.query(l, r)]+1<<"\n";
    }

    return m+1;
}