#include<bits/stdc++.h>

//#define int long long
#define mod 10007

using namespace std;

char input[] = "input/input00.txt";
char output[] = "output/output00.txt";

void __input(int test_file)
{
	freopen(input, "w", stdout);
	
	int t = 50;
	cout << t << endl;

	vector <int> v;
	set <int> s;

	if(test_file == 1)
	{
		for(int i=1;i<=t;i++)
			v.push_back(i);

		random_shuffle(v.begin(),v.end());

		for(int i:v)
			cout << i << " ";
		cout << endl;
	}
	else if(test_file == 2)
	{
		for(int i=51;i<=100;i++)
			v.push_back(i);

		random_shuffle(v.begin(),v.end());

		for(int i:v)
			cout << i << " ";
		cout << endl;
	}
	else if(test_file <= 4)
	{
		while(s.size() < t)
			s.insert(rand()%300+1);

		for(int i:s)
			v.push_back(i);

		random_shuffle(v.begin(),v.end());

		for(int i:v)
			cout << i << " ";
		cout << endl;
	}
	else if(test_file <= 6)
	{
		while(s.size() < t)
			s.insert(rand()%500+1);

		for(int i:s)
			v.push_back(i);

		random_shuffle(v.begin(),v.end());

		for(int i:v)
			cout << i << " ";
		cout << endl;
	}
	else if(test_file <= 8)
	{
		while(s.size() < t)
			s.insert(200 + rand()%300);

		for(int i:s)
			v.push_back(i);

		random_shuffle(v.begin(),v.end());

		for(int i:v)
			cout << i << " ";
		cout << endl;
	}
	else if(test_file == 9)
	{
		for(int i=401;i<=450;i++)
			v.push_back(i);

		random_shuffle(v.begin(),v.end());

		for(int i:v)
			cout << i << " ";
		cout << endl;
	}
	else if(test_file == 10)
	{
		for(int i=451;i<=500;i++)
			v.push_back(i);

		random_shuffle(v.begin(),v.end());

		for(int i:v)
			cout << i << " ";
		cout << endl;
	}
}

vector <vector<int> > ans;
vector <int> a(4e5,0);

void output1()
{
	int n = 1;
	int cnt = 1;
	a[0] = 1;

	while(true)
	{
		vector <int> tt;

		for(int i=0;i<cnt;i++)
			tt.push_back(a[i]);

		ans.push_back(tt);

		if(n == 500)
			break;

		n++;
		vector <int> b(n*(n-1)/2+2,0);

		for(int i=0;i<cnt;i++)
		{
			b[i] += a[i];
			b[i+n] -= a[i];
		}

		for(int i=1;i<b.size();i++)
			b[i] = b[i] + b[i-1];

		b.pop_back();
		cnt = b.size();

		for(int i=0;i<cnt;i++)
			a[i] = b[i]%mod;
	}
}

void __output()
{
	freopen(input, "r", stdin);
	freopen(output, "w", stdout);

	int t;
	cin >> t;
	assert(1 <= t && t <= 100);

	for(int i=0;i<t;i++)
	{
		int x;
		cin >> x;

		assert(1 <= x && x <= 500);

		x--;

		for(int i:ans[x])
			cout << i << " ";
		cout << endl;
	}
}

int32_t main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	output1();

	srand(time(0));
    int T = 10;

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