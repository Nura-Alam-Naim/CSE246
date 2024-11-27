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
bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    return a.second < b.second;
}
void solve()
{
    vector<pair<ll, ll>> v;
    ll n;
    cout << "number of input: ";
    cin >> n;
    ll start, end;
    for (ll i = 0; i < n; i++)
    {
        cin >> start >> end;
        v.push_back({start, end});
    }
    sort(all(v), cmp);
    vector<pair<ll, ll>> v1;
    v1.push_back(v[0]);
    ll end = v[0].second;
    ll count = 1;
    for (ll i = 1; i < v.size(); i++)
        if (v[i].first >= end)
        {
            v1.push_back(v[i]);
            // Endtime += v[i].second;
            end = v[i].second;
            count++;
        }
    for (int i = 0; i < n; i++)
        cout << "(" << v1[i].first << "," << v1[i].second << ")";
    cout << "Total activities: " << count << endl;
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