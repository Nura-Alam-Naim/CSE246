//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
#define nl "\n"
#define sp ' '
#define yes cout << "YES" << nl
#define no cout << "NO" << nl
#define all(v) v.begin(), v.end()
#define pb push_back
#define ff first
#define ss second
const ll N = 1e6 + 1;
void SelectActivities(vl s, vl f)
{
    vector<pair<ll, ll>> ans;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,
                   greater<pair<ll, ll>>> p;

    for (ll i = 0; i < s.size(); i++)

        p.push(make_pair(f[i], s[i]));
    
    auto it = p.top();
    ll start = it.second;
    ll end = it.first;
    p.pop();
    ans.push_back({start, end});

    while (!p.empty())
    {
        auto it = p.top();
        p.pop();
        if (it.ss >= end)
        {
            start = it.second;
            end = it.first;
            ans.pb({start, end});
        }
    }
    cout << "Following Activities should be selected. " << nl << nl;

    for (auto it:ans)
        cout << "Activity started at " << it.ff
             << " and ends at " << it.ss << nl;
}
void solve()
{
    vl s = {1, 3, 0, 5, 8, 5};
    vl f = {2, 4, 6, 7, 9, 9};
    SelectActivities(s, f);

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin>>tc;
    while (tc--)
        solve();
}