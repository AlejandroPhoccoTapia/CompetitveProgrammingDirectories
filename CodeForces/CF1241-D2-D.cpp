#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

void solve(){
    ll n;
    cin >> n;

    vi a(n);
    for (auto& e : a) cin >> e;

    vi b = a;
    vi trans(n+1, -1);
    sort(all(b));

    int cur = 1;
    for (ll i = 0; i < n; ++i) {
        if (trans[b[i]] == -1) {
            trans[b[i]] = cur;
            cur++;
        }
    }

    for (ll i = 0; i < n; ++i) {
        a[i] = trans[a[i]];
    }

    vii range(n+1, {1e9, -1e9});
    for (int i = 0; i < n; ++i) {
        range[a[i]].first = min(range[a[i]].first, i);
        range[a[i]].second = max(range[a[i]].second, i);
    }

    // for (int i = 0; i < n; ++i) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    if (cur == 2) {
        cout << 0 << "\n";
        return;
    }

    int response = cur-1;
    vi dp(cur, 1);
    for (int i = cur-2; i >= 1; --i) {
        if (range[i].second < range[i+1].first) {
            dp[i] = dp[i+1] + 1;
        }
        // cout << "i: " << dp[i] << endl;

        response = min(response, cur-1-dp[i]);
    }

    cout << response << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; 
    tt = 1;
    cin >> tt;
    while(tt--) solve();
}
