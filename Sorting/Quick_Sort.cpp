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
ll partition(vl &v, ll l, ll r)
{
    ll pivot = v[l];
    ll i = l, j = r;
    do
    {
        do
        {
            i++;
        } while (v[i] <= pivot);
        do
        {
            j--;
        } while (v[j] > pivot);
        if (i < j)
            swap(v[i], v[j]);
    } while (i < j);
    swap(v[l], v[j]);
    return j;
}
void quickSort(vl &v, ll l, ll r)
{
    if (l < r)
    {
        ll j = partition(v, l, r);
        quickSort(v, l, j);
        quickSort(v, j + 1, r);
    }
}
void solve()
{
    vl v = {100, 20, 1, 1, 50, 60, 2, 6, 7, 0, 8};
    ll n = v.size();
    for (ll i = 0; i < n; i++)
        cout << v[i] << sp;
    cout << nl;
    cout << "Quick Sort: ";
    quickSort(v, 0, n);
    for (auto i : v)
        cout << i << sp;
    cout << nl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    //cin>>tc;
    while (tc--)
        solve();
}
