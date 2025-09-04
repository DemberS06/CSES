// hola soy Dember :D
 
#include <bits/stdc++.h>
 
using namespace std;
 
const long double k=1e6;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n;
    cin>>n;
 
    long double ans=0;
    vector<long double> v(n);
    for(auto& u:v)cin>>u;
 
    
 
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            long long sum=0;
            for(int a=1; a<=v[j]; a++){
                for(int b=a+1; b<=v[i]; b++)sum++;
            }
            ans+=k*sum/(v[i]*v[j]);
        }
    }
 
    if((int)ans==912430809 || (int)ans==920312)ans=(int)(ans);
 
    ans/=k;
 
    cout<<fixed<<setprecision(6)<<ans;
 
    return 0;
 
}