#include <bits/stdc++.h>

using namespace std;

const long long N=2e5+5;

int sgt[4*N], a[N], n;

void act(int i, int l, int r, int p){
    if(l>r || l>p || r<p)return;
    sgt[i]++;
    if(l==r)return;
    act(2*i, l, (l+r)/2, p);
    act(2*i+1, (l+r)/2+1, r, p);
    return;
}

int que(int i, int l, int r, int p){
    if(l>r || l>p)return 0;
    if(r<=p)return sgt[i];
    return que(2*i, l, (l+r)/2, p)+que(2*i+1, (l+r)/2+1, r, p);
}

int BS(int l, int r, int x, int p){
    if(l>r)return p;
    int mt=(l+r)/2, dm=que(1,1,n,mt);
    if(mt-dm>=x)return BS(l, mt-1, x, mt);
    else return BS(mt+1, r, x, p);
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1; i<=n; i++)cin>>a[i];

    for(int i=0, x, p; i<n; i++){
        cin>>x; p=BS(1,n,x,0);
        cout<<a[p]<<' ';
        //for(int j=1; j<=n; j++)cout<<que(1, 1, n, j)<<' ';cout<<"\n";
        act(1,1,n,p);
    }
}