#include<bits/stdc++.h>

#define int long long
#define mod1 1000000007

using namespace std;

char input[] = "input/input00.txt";
char output[] = "output/output00.txt";

vector <int> r,d;
int segment[400010];
int ans[200010];

bool cmp(pair<int,int> a, pair<int,int> b)
{
	if(a.first == b.first)
		return a.second > b.second;
	
	return a.first < b.first;
}

int query1(int node, int l, int r, int start, int end)
{
	if(start > r || end < l)
		return 0;

	else if (start <= l && r <= end)
		return segment[node];

	int mid=l+(r-l)/2;

	int p1 = query1(2*node,l,mid,start,end);
	int p2 = query1(2*node+1,mid+1,r,start,end);

	return (p1%mod1 + p2%mod1)%mod1;
}

void update(int node,int l,int r,int index,int val)
{
	if(l==r)
		segment[node] = val+1;
	else
	{
		int mid=l+(r-l)/2;

		if(index<=mid)
			update(2*node,l,mid,index,val);
		else
			update(2*node+1,mid+1,r,index,val);

		segment[node] = (segment[2*node]%mod1 + segment[2*node+1]%mod1)%mod1;
	}
}

void solve()
{
    d.clear();
    r.clear();

    for(int i=0;i<1000010;i++)
        r.push_back(rand()%1000000+1);

    for(int i=0;i<1000010;i++)
    {
        if(i%3 == 1)
            r[i] *= (rand()%1000+1);
        else if(i%3 == 2)
            r[i] /= (rand()%1000+1), r[i]++;

        assert(r[i] >= 1 && r[i] <= 1e9);
    }

    int cnt = 1;

    for(int i=0;i<1000010;i++)
        assert(cnt >= 1 && cnt <= 1e9), d.push_back(cnt), cnt += 50 + rand()%50;

    random_shuffle(d.begin(),d.end());
    random_shuffle(r.begin(),r.end());
}

void __input(int test_file)
{
    srand(time(0));

	freopen(input, "w", stdout);
	
	int t = 20;
	cout << t << endl;

    for(int j=1;j<=t;j++)
    {
        solve();
        int n,q;

        if(test_file == 1)
            n = rand()%1000+1, q = n + rand()%1000+1;
        else if(test_file == 2)
            n = 1000, q = 2000;
        else if(test_file == 3)
            n = rand()%100000+1, q = n + rand()%100000+1;
        else
            n = 100000, q = 200000;

        assert(r.size() >= n && d.size() >= n);
        assert(r.size() >= q && d.size() >= q);

        cout << n << " " << q << endl;

        if(j == 1)
        {
            for(int i=0;i<n;i++)
                cout << 1 << " ";
            cout << endl;

            for(int i=0;i<q;i++)
            {
                if(i%2)
                    cout << r[i] << " ";
                else
                    cout << rand()%100000+1 << " ";
            }
            cout << endl;
        }
        else if(j == 2)
        {
            for(int i=0;i<n;i++)
                cout << 1000000000 << " ";
            cout << endl;

            for(int i=0;i<q;i++)
            {
                if(i%2)
                    cout << r[i] << " ";
                else
                    cout << rand()%100000+1 << " ";
            }
            cout << endl;
        }
        else if(j == 3)
        {
            vector <int> v;

            for(int i=1;i<=n;i++)
                v.push_back(i);

            for(int i:v)
                cout << i << " ";
            cout << endl;

            v.clear();

            for(int i=1;i<=q;i++)
                v.push_back(i);

            for(int i:v)
                cout << i << " ";
            cout << endl;
        }
        else if(j == 4)
        {
            vector <int> v;

            for(int i=1;i<=n;i++)
                v.push_back(i);

            random_shuffle(v.begin(),v.end());
            
            for(int i:v)
                cout << i << " ";
            cout << endl;

            v.clear();

            for(int i=1;i<=q;i++)
                v.push_back(i);

            random_shuffle(v.begin(),v.end());
            
            for(int i:v)
                cout << i << " ";
            cout << endl;
        }
        else if(j <= 12)
        {
            vector <int> v;

            if(j <= 8)
            {
                for(int i=0;i<n;i++)
                {
                    if(i%2)
                        v.push_back(r[i]);
                    else
                        v.push_back(rand()%100000+1);
                }
            }
            else
            {
                for(int i=0;i<n;i++)
                    v.push_back(d[i]);
            }

            sort(v.begin(),v.end());

            if(j == 6 || j == 9)
                sort(v.begin(),v.end(),greater<int> ());
            else if(j == 7 || j == 10)
                reverse(v.begin(),v.begin()+v.size()/2);
            else if(j == 8 || j == 11)
            {
                sort(v.begin(),v.end(),greater<int> ());
                reverse(v.begin(),v.begin()+v.size()/2);          
            }

            for(int i:v)
                cout << i << " ";
            cout << endl;

            while(v.size() < q)
                v.push_back(rand()%100000+1);

            random_shuffle(v.begin(),v.end());

            for(int i:v)
                cout << i << " ";
            cout << endl;
        }
        else if(j <= 14)
        {
            for(int i=0;i<n;i++)
            {
                if(i%2)
                    cout << r[i] << " ";
                else
                    cout << rand()%100000+1 << " ";
            }
            cout << endl;

            for(int i=0;i<q;i++)
            {
                if(i%2)
                    cout << d[i] << " ";
                else
                    cout << rand()%100000+1 << " ";
            }
            cout << endl;
        }
        else
        {
            int cnt = j - 14;

            int cnt1 = pow(10,cnt) - 1;
            int cnt2 = pow(10,cnt-1);

            vector <int> v;

            for(int i=0;i<n;i++)
                v.push_back(cnt2 + rand()%cnt1);

            for(int i:v)
                cout << i << " ";
            cout << endl;

            while(v.size() < q)
                v.push_back(rand()%100000+1);

            random_shuffle(v.begin(),v.end());

            for(int i:v)
                cout << i << " ";
            cout << endl;
        }
    }
}

void __output()
{
	freopen(input, "r", stdin);
	freopen(output, "w", stdout);

	int t;
    cin >> t;
	assert(t >= 1 && t <= 20);

	while(t--)
	{
		int n,q;
		cin >> n >> q;
		assert(n >= 1 && n <= 100000);
		assert(q >= 1 && q <= 200000);

		memset(segment,0,400010*sizeof(segment[0]));

		int x;
		vector <pair<int,int> > query,v;

		for(int i=1;i<=n;i++)
		{
			cin >> x;
			assert(x >= 1 && x <= 1e9);
			v.push_back({x,i});
		}

		for(int i=0;i<q;i++)
		{
			cin >> x;
			assert(x >= 1 && x <= 1e9);
			query.push_back({x,i});
		}

		sort(v.begin(),v.end(),cmp);
		sort(query.begin(),query.end());
		reverse(v.begin(),v.end());

		for(auto i:query)
		{
			while(!v.empty() && v.back().first <= i.first)
			{
				int temp = query1(1,1,n,1,v.back().second);
				update(1,1,n,v.back().second,temp);

				v.pop_back();
			}

			ans[i.second] = segment[1];
		}

		for(int i=0;i<q;i++)
			cout << ans[i] << " ";
		cout << endl;
	}
}

int32_t main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int T = 4;

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