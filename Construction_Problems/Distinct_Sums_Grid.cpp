// hola soy Dember :D

#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    long long n;
    cin>>n;

    if(n<=3){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    if(n==4){
        cout<<"1 1 3 2\n2 1 2 4\n3 3 3 4\n2 1 4 4";
        return 0;
    }

    vector<vector<int>> ans(n, vector<int> (n, 0));
    vector<int> v(n-2);
    for(int i=0; i<n-2; i++)v[i]=i+2;

    for(int i=0; i<n-2; i++){
        for(int j=0; j<n-2; j++){
            ans[i][j]=v[(i+j)%(n-2)];
        }
    }
    for(int i=0; i<n-1; i++)ans[i][n-2]=1, ans[i][n-1]=i+1, ans[n-2][n-i-2]=i+1;
    for(int i=0; i<n; i++)ans[n-1][i]=n;
    

    for(auto& v:ans){
        for(auto& u:v)cout<<u<<' ';
        cout<<"\n";
    }

    return 0;
}