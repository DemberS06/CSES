// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

struct SGT{
    struct Node{
        long long sum;
        int left, right;
        Node(): sum(0), left(0), right(0) {}
        Node(long long _s, int _l, int _r): sum(_s), left(_l), right(_r) {}
    };

    int m, nxt_free=1;
    vector<int> root;
    vector<Node> seg;

    SGT(int n, int _m): root(n+1, 0), seg(40*n), m(_m){}

    int build(int l, int r) {
        int node=nxt_free++;
        seg[node]=Node(0, 0, 0);
        if(l!=r) {
            seg[node].left  = build(l,   (l+r)/2  );
            seg[node].right = build((l+r)/2+1, r);
        }
        return node;
    }
     
    int update(int old, int l, int r, int pos, long long val) {
        int cur=nxt_free++;
        seg[cur]=seg[old];
        seg[cur].sum+=val;
        if (l!=r) {
            if(pos<=(l+r)/2)seg[cur].left  = update(seg[old].left , l, (l+r)/2  , pos, val);
            else            seg[cur].right = update(seg[old].right, (l+r)/2+1, r, pos, val);
        }
        return cur;
    }
     
    long long query_sum(int nodeB, int nodeA, int l, int r, int ql, int qr) {
        if(qr<l || r<ql)return 0;
        if(ql<=l && r<=qr)return seg[nodeB].sum-seg[nodeA].sum;
        
        return query_sum(seg[nodeB].left,  seg[nodeA].left , l, (l+r)/2  , ql, qr)
             + query_sum(seg[nodeB].right, seg[nodeA].right, (l+r)/2+1, r, ql, qr);
    }

    long long query(int l, int r, long long R){
        return query_sum(root[r], root[l-1], 0, m, 0, R);
    }
};
 
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
 
    int n, q;
    cin>>n>>q;
    vector<long long> a(n);
    for(auto& u:a)cin>>u;
    
    vector<long long> comp=a;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    int V=comp.size();
    SGT sgt(n, comp.size()-1);
 
    sgt.root[0]=sgt.build(0, V-1);
 
    for(int i=1; i<=n; i++) {
        int idx=lower_bound(comp.begin(), comp.end(), a[i-1])-comp.begin();
        sgt.root[i]=sgt.update(sgt.root[i-1], 0, V-1, idx, a[i-1]);
    }
 
    while(q--){
        int l, r;
        cin>>l>>r;
        long long ans=1;
        while(true){
            int R=upper_bound(comp.begin(), comp.end(), ans)-comp.begin()-1;
            if(R<0)break;
            long long sum=sgt.query(l, r, R);
            if(sum<ans)break;
            ans=sum+1;
        }
        cout<<ans<<"\n";
    }
    return q+1;
}