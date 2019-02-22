#include<bits/stdc++.h>

#define int long long

using namespace std;

char input[] = "input/input00.txt";
char output[] = "output/output00.txt";

void __input(int test_file)
{
	freopen(input, "w", stdout);
	
	int t = 500;
	cout << t << endl;

	map <int,bool> m;

	if(test_file == 1)
	{
		for(int i=1;i<=t;i++)
			cout << i << endl;
	}
	else if(test_file == 2)
	{
		int mod = 1e6;
		int cnt = 0;

		while(cnt < t)
		{
			int temp = rand()%mod+1;

			if(!m[temp])
			{
				cnt++;
				m[temp] = true;
				cout << temp << endl;
			}
		}
	}
	else if(test_file == 3)
	{
		int mod;
		int cnt = 0;

		while(cnt < t)
		{
			if(cnt == 0)
				mod = 1e4;
			else if(cnt == 100)
				mod = 1e5;
			else if(cnt == 200)
				mod = 1e6;
			else if(cnt == 300)
				mod = 1e7;
			else if(cnt == 400)
				mod = 1e8;

			int temp = mod + rand()%mod;

			if(!m[temp])
			{
				cnt++;
				m[temp] = true;
				cout << temp << endl;
			}
		}
	}
	else if(test_file == 4)
	{
		int mod = 1e8;
		int cnt = 0;

		while(cnt < t)
		{
			int temp = rand()%mod+1;

			if(!m[temp])
			{
				cnt++;
				m[temp] = true;
				cout << mod + temp << endl;
			}
		}
	}
	else if(test_file == 5)
	{
		int mod = 1e9;

		for(int i=0;i<t;i++)
			cout << mod - i << endl;
	}
	else
	{
		int mod;
		int cnt = 0;

		while(cnt < t)
		{
			if(cnt == 0)
				mod = 1e4;
			else if(cnt == 100)
				mod = 1e5;
			else if(cnt == 200)
				mod = 1e6;
			else if(cnt == 300)
				mod = 1e7;
			else if(cnt == 400)
				mod = 1e8;

			int temp = mod + rand()%mod;

			if(!m[temp])
			{
				cnt++;
				m[temp] = true;
				cout << 3*temp << endl;
			}
		}
	}
}

void __output()
{
	freopen(input, "r", stdin);
	freopen(output, "w", stdout);

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

        cout << ans << endl;
    }
}

int32_t main() 
{
	srand(time(0));
    int T = 6;

	for(int t = 0; t < T; ++t) 
    {
		if(t == 10) 
        {
			output[13] = input[11] = '1';
			output[14] = input[12] = '0';
		}
		else if(t > 0)
        {
			output[14]++;
            input[12]++;
        }

		__input(t+1);
		__output();
	}
	return 0;
}