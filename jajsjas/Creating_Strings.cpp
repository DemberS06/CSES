#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    string s;
    set<string> ans;

    cin>>s;

    sort(s.begin(), s.end()); ans.insert(s);

    while(next_permutation(s.begin(), s.end())){
        ans.insert(s);
    }

    cout<<ans.size()<<"\n";
    for(auto u:ans)cout<<u<<"\n";

    return 0;
}