#include <bits/stdc++.h>

#define int long long
#define end "\n"

using namespace std;

int32_t main()
{
    string s;
    cin >> s;

    int n = s.size();

    assert(1 <= n && n <= 100);

    for(int i=0;i<n;i++)
        assert(s[i] >= 'a' && s[i] <= 'z');

    int count = 0;

    for(int i=0;i<n;i++)
    {
        if(s[i] == s[0])
            count++;
    }

    cout << count << endl;
}