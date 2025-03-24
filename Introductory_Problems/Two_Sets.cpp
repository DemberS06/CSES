//Hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;
 
void value(int in){cout<<((in)?"YES\n":"NO\n");return;}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    long long n, sum;
    
    cin>>n;sum=n*(n+1)/2;
    
    if(sum&1){
        value(0);
        return 0;
    }

    sum/=2;

    vector<int> a,b;
    
    for(int i=n; i>0; i--){
        if(i<=sum)a.push_back(i), sum-=i;
        else b.push_back(i);
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    value(1);
    
    cout<<a.size()<<"\n";
    for(auto u:a)cout<<u<<' ';cout<<"\n";
    cout<<b.size()<<"\n";
    for(auto u:b)cout<<u<<' ';cout<<"\n";
 
    return 0;
}
