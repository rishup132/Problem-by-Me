#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    assert(1 <= t && t <= 1e4);

    while(t--)
    {
        int n;
        cin >> n;
        assert(1 <= n && n <= 1e9);

        int ans = 0;

        if(n%3 == 0)
        {
            n /= 3;

            ans = n*n + (n-1)*(n-1);

            if(n%2 == 0)
            {
                n = (n+1)/2;
                ans -= (n*n + (n-1)*(n-1));
            }
        }

        cout << ans << " ";
    }
}