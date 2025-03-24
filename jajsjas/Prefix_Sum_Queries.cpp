#include <bits/stdc++.h>

using namespace std;

const long long N=2e5+5, M=475, inf=1e18;

long long a[N], b[M], c[N], mx[M], bloqs, n;

void act(long long p, long long k){
    for(int j=1, x, y; j<=bloqs; j++){
        x=(j-1)*M+1, y=j*M;
        //cout<<x<<' '<<y<<"\n";
        if(y<p)continue;
        if(x>=p){
            b[j]+=k;
            continue;
        }
        for(int i=p; i<=y && i<=n; i++)a[i]+=k;
        long long dm=-inf;
        for(int i=x; i<=y && i<=n; i++)dm=max(dm, a[i]);
        mx[j]=dm;
    }
}

long long que(int p, int q){
    long long ans=-inf;
    for(int j=1, x, y; j<=bloqs; j++){
        x=(j-1)*M+1, y=j*M;
        if(y<p || x>q)continue;
        if(x>=p && y<=q){
            ans=max(ans, mx[j]+b[j]);
            continue;
        }
        for(int i=max(x, p); i<=y && i<=q; i++)ans=max(ans, a[i]+b[j]);
    }
    return ans;
}

long long sum(long long p){
    if(p==0)return 0;
    int x=(p+M-1)/M;
    return a[p]+b[x];
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    long long k, q, xd, zd, ans;

    cin>>n>>k; bloqs=(n+M-1)/M;
    for(int i=1; i<=n; a[i]=a[i-1]+c[i], i++)cin>>c[i];

    for(int j=1, x, y; j<=bloqs; j++){
        x=(j-1)*M+1, y=j*M;
        long long dm=-inf;
        for(int i=x; i<=y && i<=n; i++)dm=max(dm, a[i]);
        mx[j]=dm;
    }
    
    //for(int i=1; i<=n; i++)cout<<a[i]<<' ';cout<<"\n";

    while(k--){
        cin>>q>>xd>>zd;
        if(q==1)act(xd, zd-c[xd]), c[xd]=zd;
        else{
            ans=0;
            ans=que(xd, zd)-sum(xd-1);
            cout<<max(ans, 0ll)<<"\n";
        }
    }

    return 0;
}