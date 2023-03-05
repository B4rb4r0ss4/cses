#include <bits/stdc++.h>
#define turbo cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;
typedef long long ll;
 
struct Point {
    ll x; 
    ll y;
};
 
ll wek(Point a, Point b) {
    return (a.x - b.x) * (a.y + b.y);
}
 
int main() {
    turbo;
    int n; cin>>n;
    vector<Point> points;
    
    for(int i=0; i<n; i++) {
        Point x;
        cin >> x.x >> x.y;
        points.push_back(x);
    }
 
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        int nxt = (i % n); //circle (last element is connected with first element)
        ans += wek(points[i-1], points[nxt]);
    }
    ans = abs(ans);
    cout<<ans;   
}
