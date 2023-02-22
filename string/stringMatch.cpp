#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define turbo cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

int main() {
    turbo;    
    string a, pattern; cin>>a>>pattern;
    string b = pattern+'#'+a;
    int ile = 0;
    vector<int> pi(b.size(), -1);
    pi[0] = -1;
    for(int i=1; i<b.size(); i++) {
        pi[i] = pi[i-1];
        while(pi[i] != -1 && b[pi[i]+1] != b[i]) {
            pi[i] = pi[pi[i]];
        }
        if(b[pi[i]+1] == b[i]) pi[i]++;

        if(pi[i] == pattern.size()-1) ile++;
    }
    cout<<ile;
}
