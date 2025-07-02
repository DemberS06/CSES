//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n;
    cin>>n;

    set<int> f;
    for(int i=0; i<2*n; i++)f.insert(i);

    vector<vector<set<int>>> w(n, vector<set<int>> (n, f));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int p=*w[i][j].begin();
            for(int h=i+1; h<n; h++)w[h][j].erase(p);
            for(int h=j+1; h<n; h++)w[i][h].erase(p);
            
            w[i][j].clear();
            cout<<p<<' ';
        }
        cout<<"\n";
    }
 
    return 0;
}