// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    long long n, k, ans=0, x, a, b, c, sum=0;
    cin>>n>>k>>x>>a>>b>>c;

    vector<long long> v(n, x), in, out;

    for(int i=1; i<n; i++)v[i]=(a*v[i-1]+b)%c;

    for(int i=0; i<n; i++){
        in.push_back(v[i]); sum|=v[i];
        if(out.empty()){
            while(!in.empty()){
                if(!out.empty())in.back()|=out.back();
                out.push_back(in.back());
                in.pop_back();
            }
            sum=0;
        }
        if(i>=k-1)ans^=sum|out.back(), out.pop_back();
    }

    cout<<ans;
    
    return 0;
}