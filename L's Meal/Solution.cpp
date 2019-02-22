#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

int32_t main()
{
    string s;
    cin >> s;

    int n = s.size();

    for(int i=0;i<n;i++)
        assert(s[i] == 'p' || s[i] == 'c');

    int c1,c2;

    for(int i=0;i<n;i++)
    {
        if(s[i] == 'c')
        {
            c1 = i;
            break;
        }
    }

    for(int i=n-1;i>=0;i--)
    {
        if(s[i] == 'p')
        {
            c2 = i;
            break;
        }
    }

    if(c1 < c2)
        swap(s[c1],s[c2]);

    int cnt = 0;
    int ans = 0;

    for(int i=0;i<n;i++)
    {
        if(s[i] == 'c')
            cnt++;
        else
            ans += cnt;
    }

    cnt = 0;

    for(int i=n-1;i>=0;i--)
    {
        if(s[i] == 'p')
            cnt++;
        else
            ans += cnt;
    }

    cout << ans << endl;
}