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
const ll MOD = ll(1e9) + 7;

void solve(){
    ll n, k;
    cin >> n >> k;
    
    auto find_range = [&](ll cur) -> pair<ll, ll> {
        ll d = n / cur;
        pair<ll, ll> res;
        res.first = (n / (d+1)) + 1;
        res.second = n / d;

        return res;
    };

    vl dp;
    vl d;
    for (ll i = 1; i <= n;) {
        dp.push_back(1);
        d.push_back(n/i);
        i = find_range(i).second + 1;
    }
    // cout << "ga" << endl;
    ll m = sz(dp);

    // cout << "ga" << endl;
    for (ll i = 1; i < k; ++i) {
        // cout << "i: " << i << endl;
        vl dp2(m, 0);
        ll sum = 0;
        ll cur = 0;

        // cout << "entra" << endl;
        for (ll j = m-1; j >= 0; --j) {
            ll nx = d[j];
            ll y = nx;
            ll ny = n/y;

            // cout << "d[cur]: " << d[cur] << " ny: " << ny << endl;
            // cout << "y: " << y << endl;
            while (ny != d[cur]) {
                auto [l, r] = find_range(n / d[cur]);
                sum += ((r-l+1) * dp[cur]) % MOD;
                sum %= MOD;
                ++cur;
            }
            // cout << "sum: " << sum << endl;

            dp2[j] = sum;
            auto [l, r] = find_range(n / ny);
            dp2[j] += ((y-l+1) * dp[cur]) % MOD;
            dp2[j] %= MOD;
        }
        // cout << "sale" << endl;
        swap(dp, dp2);
    }
    // cout << "dp: " << endl;
    // for (auto e : dp) cout << e << " ";
    // cout << endl;

    ll response = 0;
    for (ll i = 0; i < m; ++i) {
        auto [l, r] = find_range(n / d[i]);
        response += ((r-l+1) * dp[i]) % MOD;
        response %= MOD;
    }

    cout << response << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; 
    tt = 1;
    // cin >> tt;
    while(tt--) solve();
}
