#include <bits/stdc++.h>

using namespace std;

const long long N=2e5+5, M=476;

long long a[N], b[M], c[M], blqs, n, q;

void act1(int x, int y, long long sum){
    long long dm=sum;
    for(int j=1; j<=blqs; j++){
        int p=(j-1)*M+1, q=min(n, j*M);

        if(p>y){
            b[j]+=dm;
            continue;
        }
        if(p>=x && q<=y){
            b[j]+=dm;
            c[j]+=sum;
            dm+=sum*(q-p+1)*(q-p+2)/2;
            continue;
        }

        for(int i=max(p, x); i<=min(q, y); i++)a[i]+=dm,dm+=sum;
        for(int i=y+1; i<=q; i++)a[i]+=dm;
    }
    return;
}

void act2(int x, int y, long long sum){
    long long dm=0;
    for(int j=1; j<=blqs; j++){
        int p=(j-1)*M+1, q=min(n, j*M);

        if(p>y){
            b[j]-=dm;
            continue;
        }
        if(p>=x && q<=y){
            b[j]-=dm;
            dm+=c[j]*(q-p+1)*(q-p+2)/2;
            continue;
        }

        for(int i=max(p, x); i<=min(q, y); i++)a[i]+=dm,dm+=sum;
        for(int i=y+1; i<=q; i++)a[i]+=dm;
    }
    return;
}

int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);



    return 0;
}