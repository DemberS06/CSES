// hola soy Dember :D
#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);

    vector<int> a(1e6, 0), p;
    p.reserve(1e6);

    for(int i=2; i<1e6; i++){
        if(a[i])continue;
        p.push_back(i);
        for(int j=i; j<1e6; j+=i)a[j]=1;
    }

    function<bool(long long)> is_prime = [&](long long x){
        for(auto& u:p){
            if(u*u>x)break;
            if(x%u==0)return 0;
        }
        return 1;
    };

    int t;
    cin>>t;

    while(t--){
        long long x;
        cin>>x;
        while(!is_prime(++x));
        cout<<x<<"\n";
    }

    return t+1;;
}