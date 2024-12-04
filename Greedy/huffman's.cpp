#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a ,pair<int,int> b)
{
    return a.second < b.second; 
}

int main()
{
    vector<pair<int,int> >v;

    int n;
    cout<<"number of input: 6 \n";
    //cin>>n;

    // for(int i=0;i<n;i++)
    // {
    //     int start,end;
    //     cin>>start>>end ;
    //     v.push_back(make_pair(start, end));
    // }
    v.push_back(make_pair(6, 8));
    v.push_back(make_pair(7, 8));
    v.push_back(make_pair(8, 13));
    v.push_back(make_pair(11, 12));
    v.push_back(make_pair(14, 18));
    v.push_back(make_pair(19, 20));

    sort(v.begin(),v.end(),cmp);

     vector<pair<int, int> > v1;
     v1.push_back(v[0]); 
    int end = v[0].second; 

    int count = 1; 
    

    for (int i = 1; i < v.size(); i++) {
    if (v[i].first >= end) { 
        v1.push_back(v[i]);
        //Endtime += v[i].second; 
        end = v[i].second;    
        count++; 
    }
}
        
     
    for (int i = 0; i < v1.size(); i++) {
     cout << "(" << v1[i].first << "," << v1[i].second << ")"  ;
    }

    cout << "Total activities: " << count << endl;

}
#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
    vector<pair<int, int> > v;

    int n;
    cout << "number of input: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }

    sort(v.begin(), v.end(), cmp);

    vector<pair<int, int> > v1;
    v1.push_back(v[0]);
    int end = v[0].second;

    int count = 1;
    int Endtime = end; // initialize currently with first activity end time

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].first >= end)
        {
            v1.push_back(v[i]);
            Endtime += v[i].second;
            end = v[i].second;
            count++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "(" << v1[i].first << "," << v1[i].second << ")";
    }

    cout << "Total activities: " << count << endl;
}
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
void solve()
{
    
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