// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using i128 = __int128_t;    

struct Line {
    ll m, b;
    ll eval(ll x)const{
        return m*x + b;
    }
};

bool bad(const Line &a, const Line &b, const Line &c){
    return (i128)(b.b-a.b)*(i128)(b.m-c.m) >= (i128)(c.b-b.b)*(i128)(a.m-b.m);
}

vector<Line> build_hull(vector<Line> &v) {
    sort(v.begin(), v.end(), [](auto &A, auto &B) {
        if(A.m!=B.m)return A.m<B.m;
        return A.b>B.b;
    });
    vector<Line> hull;
    for(auto &ln:v){
        if(!hull.empty() && hull.back().m==ln.m)continue;
        while(hull.size()>=2 && bad(hull[hull.size()-2], hull[hull.size()-1], ln))hull.pop_back();
        hull.push_back(ln);
    }
    return hull;
}

ll query_hull(const vector<Line> &hull, ll x) {
    if(hull.empty())return LLONG_MIN;
    int l=0, r=hull.size() - 1;
    while (r-l>3) {
        int m1=l+(r-l)/3;
        int m2=r-(r-l)/3;
        if(hull[m1].eval(x)<hull[m2].eval(x))l=m1;
        else r=m2;
    }
    ll res=LLONG_MIN;
    for (int i=l; i<=r; i++)res=max(res, hull[i].eval(x));
    return res;
}

struct SegCHT {
    int n;
    vector<vector<Line>> seg, hulls;
    SegCHT(int _n): n(_n), seg(4*n), hulls(4*n) {}

    void add_line(int node, int l, int r, int ql, int qr, const Line &ln) {
        if(qr<=l || r<=ql) return;
        if(ql<=l && r<=qr) { seg[node].push_back(ln); return; }
        int m=(l+r)>>1;
        add_line(node<<1, l, m, ql, qr, ln);
        add_line(node<<1|1, m, r, ql, qr, ln);
    }

    void add_segment(const Line &ln, int ql, int qr){
        add_line(1,0,n,ql,qr,ln);
    }

    void build_all(int node, int l, int r){
        if(!seg[node].empty())hulls[node]=build_hull(seg[node]);
        if(r-l==1) return;
        int m=(l+r)>>1;
        build_all(node<<1, l, m);
        build_all(node<<1|1, m, r);
    }

    ll query_rec(int node, int l, int r, int x) const {
        ll ans = LLONG_MIN;
        if(!hulls[node].empty())ans=max(ans, query_hull(hulls[node], x));
        if(r-l==1)return ans;
        int m=(l+r)>>1;
        if(x<m)ans=max(ans, query_rec(node<<1, l, m, x));
        else   ans=max(ans, query_rec(node<<1|1, m, r, x));
        return ans;
    }
    ll query(int x){
        return query_rec(1,0,n,x);
    }
};

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, k; 
    cin>>n>>k;
    
    vector<ll> v(n);
    for(auto& u:v)cin>>u;

    vector<int> L(n), R(n), st;
    st.reserve(n);
    for (int i=0; i<n; i++){
        while(!st.empty() && v[st.back()]>v[i])R[st.back()]=i-1, st.pop_back();
        st.push_back(i);
    }while(!st.empty())R[st.back()]=n-1, st.pop_back();
    for (int i=n-1;i>=0;i--){
        while(!st.empty() && v[st.back()]>v[i])L[st.back()]=i+1, st.pop_back();
        st.push_back(i);
    }while(!st.empty())L[st.back()]=0, st.pop_back();

    for(int i=0; i<n; i++)st.push_back(i);
    sort(st.begin(), st.end(), [&](int& x, int& y){
        if(L[x]!=L[y])return L[x]<L[y];
        if(R[x]!=R[y])return R[x]<R[y];
        return v[x]>v[y];
    });

    SegCHT cht(n);
    for(int j=0;j<n;j++){
        if(j && L[st[j]]==L[st[j-1]] && R[st[j]]==R[st[j-1]])continue;
        int& i=st[j];
        int l=L[i], r=R[i]; ll h=v[i];
        if(r-l+1<k){
            cht.add_segment({h,(1LL-l)*h},l,r+1);
            cht.add_segment({0,(r-l+1)*h},r+1,l+k-1);
            cht.add_segment({-h,(r+k)*h},l+k-1,r+k);
        } else {
            cht.add_segment({h,(1LL-l)*h},l,l+k);
            cht.add_segment({0,k*h},l+k,r);
            cht.add_segment({-h,(r+k)*h},r,r+k);
        }
    }
    cht.build_all(1,0,n);
    
    for(int i=k-1;i<n;i++)cout<<cht.query(i)<<' ';
}
