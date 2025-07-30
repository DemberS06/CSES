// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    vector<long long> tr; tr.reserve(2e6);

    for(long long i=1; i<=2e6; i++)tr.push_back(i*(i+1)/2);

    int t;
    cin>>t;

    while(t--){
        long long n, x;
        cin>>n;

        x=sqrt(8*n+1);

        if(x*x==8*n+1){
            cout<<"1\n";
            continue;
        }

        int ok=1;

        for(int i=0, j=2e6-1; i<=j && ok; i++){
            while(j>i && tr[i]+tr[j]>n)j--;
            if(tr[i]+tr[j]==n){
                cout<<"2\n";
                ok=0;
            }
        }
        if(ok)cout<<"3\n";
    }

    return t+1;
}