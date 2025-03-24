#include<bits/stdc++.h>

using namespace std;

const long long md=1e9+7, N=1e6;

int main(){
    long long n, ans=0, x, y, res;
    cin>>n;x=y=n;

    for(int i=2; i<=N; i++){
        if(y<=N)break;
        x=n/i;
        res=((y%md)*((y+1)%md)%md)*500000004-N*(N+1)/2; res=res%md;
        //cout<<i-1<<' '<<x<<' '<<y<<"\n";
        ans=(ans+res+md)%md;
        
        y=x;
    }
    for(int i=1; i<=N; i++){
        y=n/i;
        ans=(ans+i*y)%md;
    }
    cout<<ans;

    return 0;
}