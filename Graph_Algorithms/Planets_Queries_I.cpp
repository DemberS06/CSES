// hola soy Dember :D
#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;

    vector<int> a(n);
    vector<vector<int>> b(n, vector<int> (30));

    for(int i=0; i<n; i++){
        cin>>a[i];
        b[i][0]=--a[i];
    }

    for(int h=1; h<30; h++){
        for(int i=0; i<n; i++){
            b[i][h]=b[b[i][h-1]][h-1];
        }
    }

    while(m--){
        int x, k;
        cin>>x>>k;
        x--;

        for(int h=0; h<30; h++){
            if((k>>h)&1)x=b[x][h];
        }
        cout<<x+1<<'\n';
    }

    return m+1;
}