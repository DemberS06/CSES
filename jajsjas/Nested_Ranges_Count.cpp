#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;

int sgt[4*N], ans1[N], ans2[N], n, p=1, q, m, id[N], a[N], b[N];
set<int> f;
map<int, int> coor;

void act(int i=1, int l=1, int r=m){
    if(l>p || r<p || l>r)return;
    if(l==r)return sgt[i]++, void();
    act(2*i, l, l+r>>1), act(2*i+1, (l+r)/2+1, r);
    return sgt[i]=sgt[2*i]+sgt[2*i+1], void();
}

int que(int i=1, int l=1, int r=m){
    if(l>q || r<p || l>r)return 0;
    if(l>=p && r<=q)return sgt[i];
    return que(2*i, l, l+r>>1)+que(2*i+1, (l+r)/2+1, r);
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin>>n;

    vector<vector<int>> v(n, vector<int> (3));
    
    for(int i=0; i<n; i++){
        cin>>v[i][0]>>v[i][1]; v[i][2]=i;
        f.insert(v[i][0]);
    }
    
    for(auto &u:f)coor[u]=p++; m=p;
    for(auto &u:v)u[0]=coor[u[0]]; 
    
    sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b){
        if(b[1]==a[1])return a[0]>b[0];
        return a[1]<b[1];
    });
    
    for(auto &u:v){
        p=u[0];q=m;
        ans1[u[2]]+=que();
        act(1, 1, m);
    }

    for(int i=0; i<=4*m; i++)sgt[i]=0;


    reverse(v.begin(), v.end());
    //ans2
    for(auto &u:v){
        p=1; q=u[0];
        ans2[u[2]]=que(1,1,m);
        p=q;
        act(1,1,m);
    }

    for(int i=0; i<n; i++)cout<<(ans1[i]>0)<<' ';cout<<"\n";
    for(int i=0; i<n; i++)cout<<(ans2[i]>0)<<' ';cout<<"\n";

    return 0;
}