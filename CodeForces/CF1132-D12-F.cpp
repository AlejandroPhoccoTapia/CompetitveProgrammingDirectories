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

const int INF = 1e9;

void solve(){
    ll n;
    cin >> n;

    string s;
    cin >> s;

    vvi dp(n, vi(n, INF));
    for (ll i = 0; i < n; ++i) dp[i][i] = 1;

    for (ll len = 2; len <= n; ++len) {
        for (ll be = 0; be+len-1 < n; ++be) {
            ll en = be + len - 1;

            for (ll i = be; i < en; ++i) {
                dp[be][en] = min(dp[be][en], dp[be][i] + dp[i+1][en]);
            }

            for (ll i = be; i < en; ++i) {
                if (s[be] == s[en] && s[be] == s[i]) 
                    dp[be][en] = min(dp[be][en], dp[be][i] + dp[i][en] - 1);
            }

            if (s[be] == s[en]) {
                if (be+1 <= en-1)
                    dp[be][en] = min(dp[be][en], dp[be+1][en-1] + 1);
                else
                    dp[be][en] = min(dp[be][en], 1);
            }

            // cout << "be: " << be << " en: " << en << endl;
            // cout << dp[be][en] << endl;
        }
    }

    cout << dp[0][n-1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; 
    tt = 1;
    // cin >> tt;
    while(tt--) solve();
}
