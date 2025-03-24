#include <bits/stdc++.h>

using namespace std;

const long long N=1e6+6;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    long long n, ans=0;
    vector<long long> v(N, 0), crib(N, 0);
    
    cin>>n;

    for(int i=0, x; i<n; i++){
        cin>>x;
        for(int h=1; h*h<=x; h++){
            if(x%h)continue;
            v[h]++;
            if(h*h!=x)v[x/h]++;
        }
    }

    for(int i=2; i<N; i++){
        if(crib[i])continue;
        for(int j=i; j<N; j+=i){
            if(crib[j]==-1)continue;
            if((j/i)%i)crib[j]++;
            else crib[j]=-1;
        }
    }

    for(int i=1; i<N; i++){
        if(crib[i]==-1)continue;
        //cout<<v[i]<<' ';
        if(crib[i]&1)ans-=v[i]*(v[i]-1)/2;
        else ans+=v[i]*(v[i]-1)/2;
    }

    cout<<ans;

    return 0;
}