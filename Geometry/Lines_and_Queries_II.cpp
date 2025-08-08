// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

const long long INF=4e18;

struct Line{
    long long m, b;
    Line(long long _m=0, long long _b=-INF): m(_m), b(_b) {}
    long long eval(long long x){return m*x+b;}
};

struct LiChao {
    struct Node {
        Line ln;
        Node *l, *r;
        Node(Line _ln): ln(_ln), l(nullptr), r(nullptr) {}
    };
    Node *root;
    int L, R;
    LiChao(int _L=0, int _R=100000): root(nullptr), L(_L), R(_R) {}

    void insert_line(Line ln, Node*& p, int l, int r){
        if(!p){
            p=new Node(ln);
            return;
        }
        int m=(l+r)>>1;
        //esto se cambia para max o min
        bool lef=ln.eval(l)>p->ln.eval(l);
        bool mid=ln.eval(m)>p->ln.eval(m);
        if(mid)swap(ln, p->ln);
        if(r-l==0) return;
        if(lef!=mid)insert_line(ln, p->l, l,   m);
        else        insert_line(ln, p->r, m+1, r);
    }

    void insert_line(Line ln){ 
        insert_line(ln, root, L, R);
    }

    long long query(int x, Node* p, int l, int r){
        //esto se cambia para max o min
        if(!p)return -INF;
        long long cur=p->ln.eval(x);
        if(l==r)return cur;
        int m=(l+r)>>1;
        //esto se cambia para max o min
        if(x<=m)return max(cur, query(x, p->l, l,   m));
        else    return max(cur, query(x, p->r, m+1, r));
    }

    long long eval(int x){
        return query(x, root, L, R);
    }
};

struct CHT{
    int n;
    vector<LiChao> segT;

    CHT(int _n): n(_n){
        segT.resize(4*(n+1), LiChao(0, n));
    }

    void add_line(int idx, int L, int R, int l, int r, Line ln) {
        if(r<L || R<l) return;
        if(l<=L && R<=r){
            segT[idx].insert_line(ln);
            return;
        }
        int M=(L+R)>>1;
        add_line(idx<<1,   L,   M, l, r, ln);
        add_line(idx<<1|1, M+1, R, l, r, ln);
    }

    void add_line(int l, int r, long long a, long long b){
        add_line(1, 0, n, l, r, Line(a, b));
    }

    long long query(int idx, int L, int R, int x) {
        long long ans=segT[idx].eval(x);
        if(L==R)return ans;
        int M=(L+R)>>1;
        //esto se cambia para max o min
        if(x<=M)return max(ans, query(idx<<1,   L,   M, x));
        else    return max(ans, query(idx<<1|1, M+1, R, x));
    }

    long long query(int x){
        return query(1, 0, n, x);
    }
};

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int m;
    cin>>m;

    CHT sgt(1e5);

    while(m--){
        int t, l, r, x;
        long long ans, a, b;
        cin>>t;

        if(t==1){
            cin>>a>>b>>l>>r;
            sgt.add_line(l, r, a, b);
        }
        else{
            cin>>x;
            ans=sgt.query(x);
            if(ans==-INF)cout<<"NO\n";
            else cout<<ans<<"\n";
        }
    }

    return m+1;
}
