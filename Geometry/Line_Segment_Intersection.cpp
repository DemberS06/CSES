// hola soy Dember :D
#include<bits/stdc++.h>

using namespace std;

struct Point{
    long long x, y;
};
 
int main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int m;
    cin>>m;

    auto cross = [](Point& a, Point& b, Point& c){
        return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
    };

    while(m--){
        Point a, b, p, q;
        cin>>a.x>>a.y>>b.x>>b.y;
        cin>>p.x>>p.y>>q.x>>q.y;
        
		long long w=cross(a, b, p);
		long long x=cross(a, b, q);
		long long y=cross(p, q, a);
		long long z=cross(p, q, b);

		if(!w && !x && !y && !z){
			if(b.x<a.x)swap(a.x, b.x);
		    if(q.x<p.x)swap(p.x, q.x);
		    if(b.y<a.y)swap(a.y, b.y);
		    if(q.y<p.y)swap(p.y, q.y);
			if(p.x<=b.x && a.x<=q.x && p.y<=b.y && a.y<=q.y)cout<<"YES\n";
			else cout<<"NO\n";
		}
		else if(((w<=0 && 0<=x)||(x<=0 && 0<=w))&&((y<=0 && 0<=z)||(z<= 0&& 0<=y)))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return m+1;
}