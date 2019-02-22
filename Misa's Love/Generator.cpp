#include <bits/stdc++.h>

#define int long long
#define mod 1000000007
#define endl "\n"

using namespace std;

int32_t main()
{
    srand(time(0));
    int T = 14;
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
		int n = rand() % 100 + 1;

		string s = "";
	
		for (int i = 0; i < n; ++i) {
			
			int x = rand() % 26;
            
			if(t == 13)
				x = 0;

			s += char(97 + x);
		}

        if(t == 0)
            s = "ab";

		cout << s << endl;

        freopen(input, "r", stdin);

        cin >> s;

        n = s.size();

        assert(1 <= n && n <= 100);

        for(int i=0;i<n;i++)
            assert(s[i] >= 'a' && s[i] <= 'z');

        freopen(output, "w", stdout);

        int count = 0;

        for(int i=0;i<n;i++)
        {
            if(s[i] == s[0])
                count++;
        }

        cout << count << endl;
    }
}