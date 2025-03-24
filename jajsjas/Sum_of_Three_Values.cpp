#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int n, x;
    cin>>n>>x;

    vector<int> v(n);
    map<int, vector<int>> mp;
    multiset<int> f;

    for(auto &u:v)cin>>u;

    for(int i=n-1; i>=0; i--)mp[v[i]].push_back(i+1), f.insert(v[i]);

    for(int i=0; i<n; i++){
        mp[v[i]].pop_back();
        f.erase(f.find(v[i]));
        for(int j=0; j<i; j++){
            if(!f.count(x-v[i]-v[j]))continue;
            cout<<j+1<<' '<<i+1<<' '<<mp[x-v[i]-v[j]].back();
            return 0;
        }
    }

    cout<<"IMPOSSIBLE";

    return 0;
}