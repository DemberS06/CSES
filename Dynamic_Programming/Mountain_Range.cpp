//Hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, ans=0;
    cin>>n;
    vector<int> a(n), l(n,-1), r(n, n), st, heur(n), sgt(4*n, 0);

    for(auto& u:a)cin>>u;

    for(int i=0; i<n; i++){
        while(!st.empty() && a[st.back()]<=a[i]){
            r[st.back()]=i;
            st.pop_back();
        }
        st.push_back(i);
        heur[i]=i;
    }

    st.clear();

    for(int i=n-1; i>=0; i--){
        while(!st.empty() && a[st.back()]<=a[i]){
            l[st.back()]=i;
            st.pop_back();
        }
        st.push_back(i);
    }

    function<void(int, int, int, int ,int)> update = [&](int i, int p, int q, int x, int y){
        if(p>q || p>x || q<x)return;
        if(p==q){
            sgt[i]=y;
            return;
        }
        update(2*i+1, p, (p+q)/2, x, y);
        update(2*i, (p+q)/2+1, q, x, y);

        sgt[i]=max(sgt[2*i], sgt[2*i+1]);
    };

    function<int(int, int, int, int ,int)> query = [&](int i, int p, int q, int x, int y){
        if(p>q || p>y || q<x)return 0;
        if(p>=x && q<=y)return sgt[i];
        return max(query(2*i+1, p, (p+q)/2, x, y), query(2*i, (p+q)/2+1, q, x, y));
    };

    sort(heur.begin(), heur.end(), [&](int& x, int& y){
        return a[x]<a[y];
    });

    for(auto& u:heur)update(1, 0, n-1, u, query(1, 0, n-1, l[u]+1, r[u]-1)+1);
    
    cout<<sgt[1];

    return 0;
}