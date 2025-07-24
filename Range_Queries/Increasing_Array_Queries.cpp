// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

struct BL{
    int n, k;
    vector<vector<long long>> nxt, sum;
    vector<long long> a, b;
    
    BL(int _n, int _k, vector<long long> _a): n(_n), k(_k+1), a(_a), b(n+1, 0), nxt(n+2, vector<long long> (k, n+1)), sum(n+2, vector<long long> (k, 0)){}

    void build(){
        for(int i=1; i<=n; i++)b[i]=b[i-1]+a[i];

        vector<int> st;
        st.reserve(n);

        for(int i=1; i<=n; i++){
            while(!st.empty() && a[i]>=a[st.back()])nxt[st.back()][0]=i, sum[st.back()][0]=a[st.back()]*(i-st.back()), st.pop_back();
            st.push_back(i);
        }while(!st.empty())sum[st.back()][0]=a[st.back()]*(n+1-st.back()), st.pop_back();

        for(int h=1; h<k; h++){
            for(int i=1; i<=n; i++){
                nxt[i][h]=nxt[nxt[i][h-1]][h-1];
                sum[i][h]=sum[nxt[i][h-1]][h-1] + sum[i][h-1];
            }
        }
    }

    long long query(int l, int r){
        long long ans=b[l-1]-b[r];

        for(int h=k-1; h>=0; h--){
            if(nxt[l][h]>r)continue;
            ans+=sum[l][h];
            l=nxt[l][h];
        }

        ans+=a[l]*(r+1-l);

        return ans;
    }
};

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k=0;
    cin>>n>>m;
    while(n>(1<<k))k++;

    vector<long long> a(n+1, 0);
    
    for(int i=1; i<=n; i++)cin>>a[i];
    BL str(n, k, a);
    str.build();

    while(m--){
        int l, r;
        cin>>l>>r;

        cout<<str.query(l, r)<<"\n";
    }

    return m+1;
}
