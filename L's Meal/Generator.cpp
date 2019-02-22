#include<bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {

	srand(time(0));
    int T = 22;
    char input[] = "input/input00.txt";
	char output[] = "output/output00.txt";

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

		freopen(input, "w", stdout);

		int n = rand() % 199999 + 2;

		string s = "";
		
		if(t <= 11) 
		{
			for (int i = 0; i < n; ++i) 
			{
				int x = rand() % 2;
				
				if(x == 0)
					s += 'p';
				else
					s += 'c';
			}
		}
		if(t == 12)
		{
			s = "cpcpcp";
		}
		if(t == 13)
		{
			s = "ppp";
		}
		if(t == 14)
		{
			for (int i = 1; i <= 100000; ++i) {
				s += "cp";
			}
		}
		if(t == 15) {
			for (int i = 1; i <= 100000; ++i) {
				s += 'p';
			}
		}
		if (t == 16) {
			for (int i = 1; i <= 100000; ++i) {
				s += 'c';
			}
		}
		if (t == 17) {
			for (int i = 1; i <= 100000; ++i) {
				s += 'p';
			}
			for (int i = 1; i <= 100000; ++i) {
				s += 'c';
			}
		}
		if (t == 18) {
			for (int i = 1; i <= 100000; ++i) {
				s += 'c';
			}
			for (int i = 1; i <= 100000; ++i) {
				s += 'p';
			}
		}
		if (t == 19) {
			for (int i = 1; i <= 100000; ++i) {
				s += "pc";
			}
		}

		cout << s << endl;

		freopen(input, "r", stdin);

        cin >> s;

        n = s.size();

        assert(2 <= n && n <= 2e5);

        for(int i=0;i<n;i++)
            assert(s[i] == 'p' || s[i] == 'c');

        freopen(output, "w", stdout);

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
	return 0;
}