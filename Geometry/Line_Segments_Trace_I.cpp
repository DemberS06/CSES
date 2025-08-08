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
        if(!p)return -1;
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

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;

    LiChao sgt(0, m);
    for(int i=0; i<n; i++){
        long long y, q;
        cin>>y>>q;
        sgt.insert_line(Line((q-y)/m, y));
    }

    for(int i=0; i<=m; i++){
        cout<<sgt.eval(i)<<' ';
    }

    return 0;
}
