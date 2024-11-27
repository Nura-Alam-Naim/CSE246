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
ll partition(vl &v, ll l, ll h)
{
    ll pivot = v[l];
    ll i = l, j = h;
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
void quickSort(vl &v, ll l, ll h)
{
    if (l < h)
    {
        ll j = partition(v, l, h);
        quickSort(v, l, j);
        quickSort(v, j + 1, h);
    }
}
void solve()
{
    vl v = {8, 10, 11, 1, 9, 8, 7, 5};
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
