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
typedef pair<ll, ll> pll;
typedef vector<pii> vii;

void solve(){
    ll n, t;
    cin >> n >> t;

    vector<pll> info(n);
    for (ll i = 0; i < n; ++i) cin >> info[i].first >> info[i].second;

    sort(all(info));
    // reverse(all(info));

    ll response = 0;
    vl dp(t, 0);
    for (auto [a, b] : info) {
        for (ll j = t-1; j >= 0; --j) {
            ll nj = j+a;

            response = max(response, dp[j] + b);

            if (nj < t)
                dp[nj] = max(dp[nj], dp[j] + b);
        }
    }

    cout << response << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();
}
