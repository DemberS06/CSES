#include <bits/stdc++.h>

using namespace std;

const int N=2e5+5;

int sgt[4*N];

void act(int i, int l, int r, int p, int q){
    if(l>r || r<p || l>p)return;
    if(l==r)return sgt[i]+=q, void();

    act(2*i,l,(l+r)/2, p, q);act(2*i+1,(l+r)/2+1, r, p, q);

    sgt[i]=sgt[2*i]+sgt[2*i+1];

    return;
}

int que(int i, int l, int r, int p, int q){
    if(l>r || r<p || l>q)return 0;
    if(l>=p && r<=q)return sgt[i];

    return que(2*i,l,(l+r)/2, p, q)+que(2*i+1,(l+r)/2+1, r, p, q);
}

int main(){
    cin.tie(); cout.tie(0); ios_base::sync_with_stdio(0);

    int n, q;
    cin>>n>>q;

    map<int, vector<int>> mp;

    for(int i=1, x; i<=n; i++){
        cin>>x;
        mp[x].push_back(i);
    }

    vector<vector<int>> events;

    for(auto &[x, u]:mp){
        u.push_back(n+3);
        act(1,1,n+5, u[0], +1);
        for(int i=1; i<u.size(); i++){
            events.push_back({u[i-1], u[i], 0});
        }
    }

    vector<int> ans(q+1);

    for(int i=1, x, y; i<=q; i++){
        cin>>x>>y;
        events.push_back({x, y, i});
    }

    sort(events.begin(), events.end());

    for(auto u:events){
        if(!u[2]){
            act(1,1,n+5,u[0], -1);
            act(1,1,n+5,u[1], +1);
        }
        else ans[u[2]]=que(1,1,n+5, u[0], u[1]);
    }

    for(int i=1; i<=q; i++)cout<<ans[i]<<'\n';

    return 0;
}