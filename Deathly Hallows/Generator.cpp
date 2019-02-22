#include<bits/stdc++.h>

const double PI = 3.141592653589793238460;

using namespace std;

typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

char input[] = "input/input00.txt";
char output[] = "output/output00.txt";

int prime[200010];
vector <int> v,s;

bool a[200010],b[200010];
long long cnt1[200010],cnt2[200010];

void fft(CArray& x)
{
    const size_t N = x.size();

    if (N <= 1) 
        return;

    CArray even = x[std::slice(0, N/2, 2)];
    CArray  odd = x[std::slice(1, N/2, 2)];

    fft(even);
    fft(odd);

    for (size_t k = 0; k < N/2; ++k)
    {
        Complex t = std::polar(1.0, -2 * PI * k / N) * odd[k];
        x[k    ] = even[k] + t;
        x[k+N/2] = even[k] - t;
    }
}

void ifft(CArray& x)
{
    x = x.apply(std::conj);
    fft( x );
    x = x.apply(std::conj);
    x /= x.size();
}

vector<long long> solve_me(string s)
{
    int N = s.size() + 1;
    int padded_size = 2 * (1 << int(ceil(log2(N))));
    vector<Complex> num1_vec(padded_size - N, 0.0), num2_vec(padded_size - N, 0.0);

    num1_vec.push_back(0.0);
    num2_vec.push_back(0.0);

    for(int i = 1; i < N; i++) 
    {
        if(s[i-1] == '1')
            num1_vec.push_back(1.0);
        else
            num1_vec.push_back(0.0);
    }

    reverse(s.begin(),s.end());

    for(int i = 1; i < N; i++) 
    {
        if(s[i-1] == '1')
            num2_vec.push_back(1.0);
        else
            num2_vec.push_back(0.0);
    }

    CArray data1(padded_size);
    for(int i = 0; i < padded_size; i++) data1[i] = num1_vec[i];
    CArray data2(padded_size);
    for(int i = 0; i < padded_size; i++) data2[i] = num2_vec[i];

    fft(data1);
    fft(data2);

    CArray data3(padded_size);
    data3 = data1 * data2;

    ifft(data3);

    vector<long long> ans;

    for (int i = 0; i < padded_size - 1; i++)
        ans.push_back((long long)(round(data3[i].real())));

    vector <long long> ans1;

    for(int i = padded_size - N + 1; i < padded_size - 1; i++)
        ans1.push_back(ans[i]);

    return ans1;
}

void solve()
{
    for(int i=2;i*i<=200001;i++)
    {
        if(prime[i] == 0)
        {
            for(int j=i*i;j<200001;j+=i)
                prime[j] = 1;
        }
    }

    for(int i=2;i<200001;i++)
    {
        if(prime[i] == 0)
            v.push_back(i);
    }

    for(int i=1;i<=200000;i++)
        s.push_back(i);
}

void solve1(int n, int m)
{
    random_shuffle(s.begin(),s.end());

    set <int> s1;

    for(int i=0;i<n;i++)
        s1.insert(s[i]);

    for(int i:s1)
        cout << i << " ";
    cout << endl;

    random_shuffle(s.begin(),s.end());

    s1.clear();

    for(int i=0;i<m;i++)
        s1.insert(s[i]);

    for(int i:s1)
        cout << i << " ";
    cout << endl;
}

void solve2(int n, int m, int mod)
{
    int cnt = rand()%mod+1;

    while(n--)
        cout << cnt++ << " ";
    cout << endl;

    cnt = rand()%mod+1;

    while(m--)
        cout << cnt++ << " ";
    cout << endl;
}

void solve3(int n, int m)
{
    int mod = 1e4;

    int cnt = 2*(rand()%mod+1);

    while(n--)
        cout << cnt++ << " ", cnt++;
    cout << endl;

    cnt = 2*(rand()%mod+1);

    while(m--)
        cout << cnt++ << " ", cnt++;
    cout << endl;
}

void solve4(int n, int m)
{
    int mod = 1e4;

    int cnt = 3*(rand()%mod+1);

    while(n--)
        cout << cnt++ << " ", cnt+=2;
    cout << endl;

    cnt = 3*(rand()%mod+1);

    while(m--)
        cout << cnt++ << " ", cnt+=2;
    cout << endl;
}

void solve5(int n, int m)
{
    int mod = 1e4;

    int cnt = 2*(rand()%mod+1);

    while(n--)
        cout << cnt << " ", cnt+=2;
    cout << endl;

    cnt = 3*(rand()%mod+1);

    while(m--)
        cout << cnt << " ", cnt+=3;
    cout << endl;
}

void solve6(int n, int m)
{
    random_shuffle(v.begin(),v.end());

    set <int> s1;

    int i = 0;

    while(s1.size() < n)
        s1.insert(v[i++]);

    random_shuffle(v.begin(),v.end());

    set <int> s2;

    i = 0;

    while(s2.size() < m)
        s2.insert(v[i++]);

    for(int i:s1)
        cout << i << " ";
    cout << endl;

    for(int i:s2)
        cout << i << " ";
    cout << endl;
}

void solve7(int n, int m)
{
    int cnt = 1;

    while(n--)
        cout << cnt << " ", cnt+=rand()%2+1;
    cout << endl;

    cnt = 1;

    while(m--)
        cout << cnt << " ", cnt+=rand()%2+1;
    cout << endl;
}

void solve8(int n, int m)
{
    random_shuffle(s.begin(),s.end());

    set <int> s1;

    for(int i=0;i<n;i++)
        s1.insert(s[i]);

    for(int i:s1)
        cout << i << " ";
    cout << endl;

    s1.clear();

    for(int i=0;i<m;i++)
        s1.insert(s[i]);

    for(int i:s1)
        cout << i << " ";
    cout << endl;
}

void __input(int test_file)
{
	freopen(input, "w", stdout);

	int t = 5;
    cout << t << endl;

    vector <pair<int,int> > vp;
    vp.push_back({rand()%1000+1,rand()%1000+1});
    vp.push_back({rand()%10000+1,rand()%10000+1});
    vp.push_back({rand()%100000+1,rand()%100000+1});
    vp.push_back({10000,10000});
    vp.push_back({100000,100000});

    random_shuffle(vp.begin(),vp.end());

    if(test_file <= 2)
    {
        for(auto i:vp)
            cout << i.first << " " << i.second << endl, solve7(i.first,i.second);
    }
    else if(test_file <= 4)
    {
        for(auto i:vp)
        {
            if(i.first > 10000)
                i.first = 10000;

            if(i.second > 10000)
                i.second = 10000;

            cout << i.first << " " << i.second << endl, solve6(i.first,i.second);
        }
    }
    else if(test_file <= 6)
    {
        for(auto i:vp)
        {
            if(i.first > 10000)
                i.first = 10000;

            if(i.second > 10000)
                i.second = 10000;

            cout << i.first << " " << i.second << endl, solve5(i.first,i.second);
        }
    }
    else if(test_file <= 8)
    {
        for(auto i:vp)
        {
            if(i.first > 10000)
                i.first = 10000;

            if(i.second > 10000)
                i.second = 10000;

            cout << i.first << " " << i.second << endl, solve4(i.first,i.second);
        }
    }
    else if(test_file <= 10)
    {
        for(auto i:vp)
        {
            if(i.first > 10000)
                i.first = 10000;

            if(i.second > 10000)
                i.second = 10000;

            cout << i.first << " " << i.second << endl, solve3(i.first,i.second);
        }
    }
    else if(test_file == 11)
    {
        for(auto i:vp)
            cout << i.first << " " << i.second << endl, solve8(i.first,i.second);
    }
    else if(test_file <= 15)
    {
        for(auto i:vp)
            cout << i.first << " " << i.second << endl, solve2(i.first,i.second,2e5);
    }
    else
    {
        for(auto i:vp)
            cout << i.first << " " << i.second << endl, solve1(i.first,i.second);
    }
}

void __output()
{
	freopen(input, "r", stdin);
	freopen(output, "w", stdout);

	int t;
    cin >> t;
    assert(t >= 1 && t <= 5);

    while(t--)
    {
        int n,m;
        cin >> n >> m;
        assert(n >= 1 && n <= 1e5);
        assert(m >= 1 && m <= 1e5);

        for(int i=0;i<200010;i++)
            a[i] = b[i] = false, cnt1[i] = cnt2[i] = 0;

        string s;
        int cnt = 0;

        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            assert(cnt < x);
            assert(x <= 2e5);

            a[x--] = true;
            
            while(s.size() < x)
                s += "0";

            s += "1";
        }

        auto t1 = solve_me(s);
        s = "";
        
        for(int i=0;i<m;i++)
        {
            int x;
            cin >> x;
            assert(cnt < x);
            assert(x <= 2e5);

            b[x--] = true;
            
            while(s.size() < x)
                s += "0";

            s += "1";
        }

        auto t2 = solve_me(s);

        long long ans = 0;

        for(int i=0;i<min(t1.size(),t2.size());i++)
            ans += t1[i]*t2[i];

        for(int i=1;i<=200000;i++)
        {
            if(a[i])
            {
                for(int j=2*i;j<=200000;j+=i)
                {
                    if(b[j])
                        cnt1[j-i]++;
                }
            }

            if(b[i])
            {
                for(int j=2*i;j<=200000;j+=i)
                {
                    if(a[j])
                        cnt2[j-i]++;
                }

                if(a[i] == b[i])
                    cnt1[0]++;
            }
        }

        for(int i=0;i<=200000;i++)
            ans -= (cnt1[i]*(cnt1[i]-1))/2, ans -= (cnt2[i]*(cnt2[i]-1))/2;

        cout << ans << endl;
    }
}

int32_t main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	srand(time(0));

    int T = 20;
    solve();

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