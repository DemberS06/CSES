// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

const int N=1e6+1;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    function<long long(long long)> nin2 = [](long long x){
        return x*(x-1)/2;
    };

    vector<long long> fr(N, 0), dv(N, 0), p(N, 0);
    long long n, ans=0;
    cin>>n;

    for(int i=0, x; i<n; i++){
        cin>>x;
        for(int h=1; h*h<=x; h++){
            if(x%h)continue;
            fr[h]++;
            if(h*h!=x)fr[x/h]++;
        }
    }

    for(int i=2; i<N; i++){
        if(p[i])continue;
        for(int j=i; j<N; j+=i){
            p[j]=i;
            dv[j]++;
            if(p[j/i]==i)fr[j]=0;
        }
    }


    for(int i=1; i<N; i++){
        if(dv[i]&1)ans-=nin2(fr[i]);
        else ans+=nin2(fr[i]);
    }

    cout<<ans;

    return 0;
}