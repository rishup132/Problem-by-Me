#include <bits/stdc++.h>

using namespace std;

int a[200010];

bool check(vector <int> v)
{
    int cnt;
    
    if(v[0] == 0 || v[1] == 0)
        cnt = max(v[0],v[1]);
    else
        cnt = __gcd(v[0],v[1]);

    for(int i=2;i<v.size();i++)
    {
        if(v[i] != cnt+v[i-1])
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    assert(1 <= t && t <= 100);

    while(t--)
    {
        int n;
        cin >> n;
        assert(1 <= n && n <= 2e5);

        set <int> s;

        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            assert(0 <= a[i] && a[i] <= 1e9);

            s.insert(a[i]);
        }

        sort(a,a+n);

        if(n == 1)
            cout << a[0] << "\n";
        else if(n == 2)
            cout << a[1] << " " << a[0] << "\n";
        else if(s.size() == 1 && a[0] == 0)
        {
            for(int i=0;i<n;i++)
                cout << a[i] << " ";
            cout << "\n";
        }
        else if(s.size() == n-1)
        {
            vector <int> v;

            for(int i=1;i<n;i++)
            {
                if(a[i] == a[i-1])
                {
                    v.push_back(a[i]);
                    break;
                }
            }

            for(auto i:s)
                v.push_back(i);

            if(!check(v))
                cout << "-1\n";
            else
            {
                for(int i:v)
                    cout << i << " ";
                cout << "\n";
            }
        }
        else if(s.size() == n)
        {
            vector <int> v,v1;

            for(auto i:s)
                v.push_back(i), v1.push_back(i);

            for(int i=n-2;i>=0;i--)
                swap(v[i],v[i+1]);

            if(check(v))
            {
                for(int i:v)
                    cout << i << " ";
            }
            else if(check(v1))
            {
                for(int i:v1)
                    cout << i << " ";
            }
            else
                cout << "-1";

            cout << "\n";
        }
        else
            cout << "-1\n";
    }
}