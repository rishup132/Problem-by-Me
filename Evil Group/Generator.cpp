#include <bits/stdc++.h>

#define int long long

using namespace std;

int a[100010];
int tree[400010];
int answers[100010];
int cnt[100010];
int BLOCK_SIZE;
vector <int> v[100010];
pair< pair<int, int>, int> queries[100500];
int ans,active;

int modexp(int a, int n, int m) {
    a %= m;
    int res = 1;
    while(n) {
        if(n & 1)
            res = res * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

const int MAX = 1e6 + 5;
bitset<MAX> prime;
vector<int> prm;
void seive(int N) {
    prime.set();
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= N; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= N ; j += i) {
                prime[j] = false;
            }
        }
    }
    for (int i = 0; i <= N; ++i) {
    	if(prime[i]) {
    		prm.push_back(i);
    	}
    }
}

void build(int node, int start, int end)
{
    if(start == end)
        tree[node] = a[start];
    else
    {
        int mid = (start + end) / 2;

        build(2*node, start, mid);
        build(2*node+1, mid+1, end);

        tree[node] = __gcd(tree[2*node],tree[2*node+1]);
    }
}

int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
        return 0;

    if(l <= start and end <= r)
        return tree[node];

    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return __gcd(p1,p2);
}

inline bool mo_cmp(const pair< pair<int, int>, int> &x, const pair< pair<int, int>, int> &y)
{
    int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;
    if(block_x != block_y)
        return block_x < block_y;
    return x.first.second < y.first.second;
}

int32_t main() 
{
	srand(time(0));
	seive(1000000);
	int T = 40;
	char input[] = "input/input00.txt";
    char output[] = "output/output00.txt";
	bool flag = true;
	for(int t = 0; t < T; ++t) {
		flag = true;
		if(t == 10) {
			output[13] = input[11] = '1';
			output[14] = input[12] = '0';
			flag = false;
		}
		if(t == 20) {
			output[13] = input[11] = '2';
			output[14] = input[12] = '0';
			flag = false;
		}
		if(t == 30) {
			output[13] = input[11] = '3';
			output[14] = input[12] = '0';
			flag = false;
		}
		if(t > 0 && flag) {
            output[14]++;
			input[12]++;
		}

        {
            freopen(input, "w", stdout);
            int n = rand() %  100000 + 1;
    
            if(t >= 20) 
                n = 100000;

            if(t >= 30)
                n = 1000;
            
            int q = rand() %  50000 + 1;
    
            if(t >= 20) 
                q = 50000;

            cout << n << "\n";

            vector<int> v;

            if(t <= 19) {
                for (int i = 0; i < n; ++i) {
                    int x = rand() % 1000000;
                    x++;
                    v.push_back(x);
                    cout << x << " ";
                }
            }
            else {
                if(t == 20) {
                    int x = 1; 
                    for (int i = 0; i < n; ++i) {
                        cout << x <<" ";
                        v.push_back(x);
                    }
                }
                else if(t <= 25){
                    for (int i = 0; i < n; ++i) {
                        int x = rand() % 2;
                        x++;
                        cout << x << " " ;
                        v.push_back(x);
                    }
                }
                else if(t <= 28) {
                    for (int i = 0; i < n; ++i) {
                        int x = rand() % 20;
                        x = modexp(2, x, 1e6);
                        cout << x << "  ";
                        v.push_back(x);
                    }
                }
                else if(t == 29){
                    for (int i = 0; i < n; ++i) {
                        int x = rand() % 78498;
                        cout << prm[x] << " ";
                        v.push_back(prm[x]);
                    }
                }
                else
                {
                    for (int i = 0; i < n; ++i) {
                    int x = rand() % 1000000 + 1;
                    v.push_back(x);
                    cout << x << " ";
                    }
                }
            }
            cout << "\n";
            cout << q << "\n";
            vector<pair<int, int>> query;
            int l = 1, r = n, l1 = 1 , r1 = ((n == 1)? 1 : 2);
            for (int i = 0; i < q; ++i) {
                if (i % 2 == 0) {
                    cout << l << " " << r << "\n";
                    l++;
                    if(l > n) l = 1;
                    query.push_back(make_pair(l, r));
                }
                else {
                    cout << l1 <<" " << r1 << "\n";
                    l1++, r1++;
                    if(l1 > n || r1 > n) {
                        l1 = 1 , r1 = ((n == 1)? 1 : 2);
                    }
                    query.push_back(make_pair(l, r));
                }
            }
        }

        {
            freopen(input,"r",stdin);
            freopen(output,"w",stdout);

            int n;
            cin >> n;

            assert(n >= 1 && n <= 100000);

            BLOCK_SIZE = static_cast<int>(sqrt(n));

            for(int i=0;i<n;i++)
            {
                cin >> a[i];
                assert(a[i] >= 1 && a[i] <= 1e6);
                v[i].clear();
            }

            v[n].clear();
            a[n] = 1;

            build(1,0,n);

            for(int i=0;i<n;i++)
            {
                int l = i;
                int h = n;
                int ans = n;

                while(l <= h)
                {
                    int mid = (l+h)/2;

                    if(query(1,0,n,i,mid) == 1)
                    {
                        ans = mid;
                        h = mid - 1;
                    }
                    else
                        l = mid + 1;
                }

                cnt[i] = ans;
                v[ans].push_back(i);
            }

            int q;
            cin >> q;

            assert(q >= 1 && q <= 50000);

            for(int i=0;i<q;i++) 
            {
                cin >> queries[i].first.first >> queries[i].first.second;
                assert(queries[i].first.first >= 1 && queries[i].first.first <= n);
                assert(queries[i].first.second >= 1 && queries[i].first.second <= n);
                queries[i].second = i;
            }

            sort(queries, queries + q, mo_cmp);

            int mo_left = 0, mo_right = -1;
            ans = active = 0;

            for(int i=0;i<q;i++)
            {
                int left = queries[i].first.first-1;
                int right = queries[i].first.second-1;

                while(mo_right < right) 
                {
                    mo_right++;
                    
                    int temp = lower_bound(v[mo_right].begin(),v[mo_right].end(),mo_left) - v[mo_right].begin();
                    temp = v[mo_right].size() - temp;
                    active += temp;
                    ans += active;

                    //cout << "1 " << ans << " " << active << endl;
                }

                while(mo_right > right) 
                {
                    int temp = lower_bound(v[mo_right].begin(),v[mo_right].end(),mo_left) - v[mo_right].begin();
                    temp = v[mo_right].size() - temp;
                    ans -= active;
                    active -= temp;

                    mo_right--;

                    //cout << "2 " << ans << " " << active << endl;
                }

                while(mo_left < left) 
                {
                    if(cnt[mo_left] <= mo_right)
                    {
                        ans -= (mo_right-cnt[mo_left]+1);
                        active--;
                    }

                    mo_left++;

                    //cout << "3 " << ans << " " << active << endl;
                }

                while(mo_left > left) 
                {
                    mo_left--;

                    if(cnt[mo_left] <= mo_right)
                    {
                        ans += (mo_right-cnt[mo_left]+1);
                        active++;
                    }

                    //cout << "4 " << ans << " " << active << endl;
                }

                answers[queries[i].second] = ans;
            }

            for(int i=0;i<q;i++)
                cout << answers[i] << "\n";
        }
	}
	return 0;
}