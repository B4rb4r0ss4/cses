#include<bits/stdc++.h>
using namespace std;
const int MAX = 1<<19;
#define ll long long
ll tr[2*MAX];

ll query(int v) {
    v+=MAX;
    ll sum = tr[v];
    while(v/=2) sum+=tr[v];
    return sum;
}

void update(int l, int r, int val) {
    l+=MAX;
    r+=MAX;
    while(l<=r) {
        if(l&1) 
            tr[l]+=val;
        if(!(r&1)) 
            tr[r]+=val;
        l = (l+1)/2;
        r = (r-1)/2;
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, q; cin>>n>>q;
    for(int i=1; i<=n; i++) 
        cin>>tr[i+MAX];

    while(q-->0) {
        int o; cin>>o;
        if(o==2) {
            int v; cin>>v;
            cout<<query(v)<<'\n';
        } else {
            int l, r, v; cin>>l>>r>>v;
            update(l, r, v);
        }
    }
}
