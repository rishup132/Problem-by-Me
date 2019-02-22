#include<bits/stdc++.h>

#define mod 1000000007

using namespace std;

int mx = 1000000000;

char input[] = "input/input00.txt";
char output[] = "output/output00.txt";

vector <int> v,v1;

void n_solve(int n, int q)
{
    cout << n << " " << q << endl;

    v.clear();
    v1.clear();

    for(int i=1;i<=n;i++)
        v.push_back(i);

    random_shuffle(v.begin(),v.end());

    for(int i=0;i<q;i++)
    {
        int x = rand()%30000;
        int y = rand()%30000;

        v1.push_back(x);
        v1.push_back(y);
        v1.push_back(x*y);
    }
}

void q_solve(int n, int q)
{
    for(int i=0;i<q;i++)
    {
        int x = rand()%2;

        if(x == 0)
            cout << 1 << " " << v[rand()%v.size()] << " " << v[rand()%v.size()] << " " << min(mx,n + v1[rand()%v1.size()]) << endl;
        else
            cout << 2 << " " << v[rand()%v.size()] << " " << v[rand()%v.size()] << endl;
    }
}

void solve1(int n, int q)
{
    n_solve(n,q);

    for(int i=1;i<v.size();i++)
        cout << v[i] << " " << v[i-1] << endl;

    for(int i=1;i<q;i++)
        cout << 1 << " " << v[0] << " " << v[n-1] << " " << min(mx,n + v1[rand()%v1.size()]) << endl;
    cout << 2 << " " << v[0] << " " << v[n-1] << endl;
}

void solve2(int n, int q)
{
    n_solve(n,q);

    for(int i=1;i<v.size();i++)
        cout << v[i] << " " << v[i-1] << endl;

    q_solve(n,q);
}

void solve3(int n, int q)
{
    n_solve(n,q);

    cout << 2 << " " << 1 << endl;
    cout << 2 << " " << 3 << endl;
    cout << 2 << " " << 4 << endl;

    int mm = n;

    n -= 4;
    n /= 2;
    int cnt = 4;

    while(n--)
    {
        cout << cnt << " " << cnt+1 << endl;
        cout << cnt << " " << cnt+2 << endl;

        cnt += 2;
    }

    q_solve(mm,q);
}

void solve4(int n, int q)
{
    n_solve(n,q);

    int d = 2;

    queue <int> vq;
    int cnt = 2;

    int temp = d+1;

    while(temp--)
    {    
        cout << 1 << " " << cnt << endl;
        vq.push(cnt++);
    }

    while(true)
    {
        int x = vq.front();
        int temp = d;

        while(temp--)
        {
            if(cnt > n)
                break;

            cout << x << " " << cnt << endl;
            vq.push(cnt++);
        }

        if(cnt > n)
            break;
    }

    q_solve(n,q);
}

void solve5(int n, int q)
{
    n_solve(n,q);
    
    int d = rand()%(n/2)+3;

    queue <int> vq;
    int cnt = 2;

    int temp = d+1;

    while(temp--)
    {
        cout << 1 << " " << cnt << endl;
        vq.push(cnt++);
    }

    while(true)
    {
        int x = vq.front();
        int temp = d;

        while(temp--)
        {
            if(cnt > n)
                break;

            cout << x << " " << cnt << endl;
            vq.push(cnt++);
        }

        if(cnt > n)
            break;
    }

    q_solve(n,q);
}

void solve6(int n, int q)
{
    n_solve(n,q);

    int x = rand()%(n/3)+3;
    int y = rand()%(n/3)+3;
    int z = n - 1 - x - y;
    x -= 2, y -= 2, z -= 2;

    int cnt = 5;

    cout << 1 << " " << 2 << endl;
    cout << 1 << " " << 3 << endl;
    cout << 1 << " " << 4 << endl;

    cout << 2 << " " << cnt << endl;
    while(x--)
        cout << cnt << " " << ++cnt << endl;

    cout << 3 << " " << ++cnt << endl;
    while(y--)
        cout << cnt << " " << ++cnt << endl;

    cout << 4 << " " << ++cnt << endl;
    while(z--)
        cout << cnt << " " << ++cnt << endl;

    q_solve(n,q);
}

void solve7(int n, int q)
{
    n_solve(n,q);
    
    int x = rand()%(n/4)+4;
    int y = rand()%(n/4)+4;
    int z = rand()%(n/4)+4;
    int u = n - 1 - x - y - z;
    x -= 2, y -= 2, z -= 2, u -= 2;

    int cnt = 6;

    cout << 1 << " " << 2 << endl;
    cout << 1 << " " << 3 << endl;
    cout << 1 << " " << 4 << endl;
    cout << 1 << " " << 5 << endl;

    cout << 2 << " " << cnt << endl;
    while(x--)
        cout << cnt << " " << ++cnt << endl;

    cout << 3 << " " << ++cnt << endl;
    while(y--)
        cout << cnt << " " << ++cnt << endl;

    cout << 4 << " " << ++cnt << endl;
    while(z--)
        cout << cnt << " " << ++cnt << endl;

    cout << 5 << " " << ++cnt << endl;
    while(u--)
        cout << cnt << " " << ++cnt << endl;

    q_solve(n,q);
}

void solve8(int n, int q)
{
    n_solve(n,q);
    
    for(int i=2;i<=n;i++)
    {
        int x = rand()%(i-1)+1;

        cout << x << " " << i << endl;
    }

    q_solve(n,q);
}

void __input(int test_file)
{
	freopen(input, "w", stdout);
	
	int t;

    if(test_file == 1)
    {
        t = 2;
        cout << t << endl;

        for(int i=1;i<=t;i++)
        {
            if(i == 1)
                solve1(100000,100000);
            else
                solve2(rand()%100000+1,rand()%100000+1);
        }
    }
    else if(test_file == 2)
    {
        t = 2;
        cout << t << endl;

        for(int i=1;i<=t;i++)
        {
            if(i == 1)
                solve1(1e4,1e4);
            else
                solve2(rand()%10000+1,rand()%10000+1);
        }
    }
    else if(test_file == 3)
    {
        t = 100;
        cout << t << endl;

        for(int i=1;i<=t;i++)
        {
            if(i <= 25)
                solve1(1e3,1e3);
            else if(i <= 500)
                solve2(2*(rand()%1000+1),2*(rand()%1000+1));
            else if(i <= 75)
                solve1(1e2,1e2);
            else
                solve2(2*(rand()%100+1),2*(rand()%100+1));
        }
    }
    else if(test_file == 4)
    {
        t = 2;
        cout << t << endl;

        for(int i=1;i<=t;i++)
        {
            if(i == 1)
                solve3(100000,100000);
            else
                solve3(2*(rand()%50000+1),2*(rand()%50000+1));
        }
    }
    else if(test_file == 5)
    {
        t = 2;
        cout << t << endl;

        for(int i=1;i<=t;i++)
        {
            if(i == 1)
                solve4(1e5,1e5);
            else
                solve4(rand()%99990+5,rand()%99990+5);
        }
    }
    else if(test_file == 6)
    {
        t = 100;
        cout << t << endl;

        for(int i=1;i<=t;i++)
        {
            if(i <= 25)
                solve3(1e3,1e3);
            else if(i <= 500)
                solve3(2*rand()%500+4,2*rand()%500+4);
            else if(i <= 75)
                solve3(1e2,1e2);
            else
                solve3(2*rand()%50+4,2*rand()%50+4);
        }
    }
    else if(test_file == 7)
    {
        t = 100;
        cout << t << endl;

        for(int i=1;i<=t;i++)
        {
            if(i <= 25)
                solve4(1e3,1e3);
            else if(i <= 500)
                solve4(2*rand()%500+4,2*rand()%500+4);
            else if(i <= 75)
                solve4(1e2,1e2);
            else
                solve4(2*rand()%50+4,2*rand()%50+4);
        }
    }
    else if(test_file == 8)
    {
        t = 2;
        cout << t << endl;

        for(int i=0;i<t;i++)
            solve5(rand()%99990 + 5,rand()%99990 + 5);
    }
    else if(test_file == 9)
    {
        t = 30;
        cout << t << endl;

        for(int i=0;i<15;i++)
            solve5(rand()%9990 + 5,rand()%9990 + 5);

        for(int i=0;i<15;i++)
            solve5(1e4,1e4);
    }
    else if(test_file == 10)
    {
        t = 5;
        cout << t << endl;

        for(int i=0;i<3;i++)
            solve6(rand()%99850 + 105,rand()%99850 + 105);

        for(int i=0;i<2;i++)
            solve6(1e5,1e5);
    }
    else if(test_file == 11)
    {
        t = 30;
        cout << t << endl;

        for(int i=0;i<15;i++)
            solve6(rand()%9850 + 105,rand()%9850 + 105);

        for(int i=0;i<15;i++)
            solve6(1e4,1e4);
    }
    else if(test_file == 12)
    {
        t = 5;
        cout << t << endl;

        for(int i=0;i<3;i++)
            solve7(rand()%99850 + 105,rand()%99850 + 105);

        for(int i=0;i<2;i++)
            solve7(1e5,1e5);
    }
    else if(test_file == 13)
    {
        t = 30;
        cout << t << endl;

        for(int i=0;i<15;i++)
            solve7(rand()%9850 + 105,rand()%9850 + 105);

        for(int i=0;i<15;i++)
            solve7(1e4,1e4);
    }
    else if(test_file == 14)
    {
        t = 5;
        cout << t << endl;

        for(int i=1;i<=t;i++)
        {
            if(i <= 2)
                solve8(rand()%10000+1,rand()%10000+1);
            else
                solve8(rand()%100000+1,rand()%100000+1);
        }
    }
    else if(test_file == 15)
    {
        t = 90;
        cout << t << endl;

        for(int i=1;i<=t;i++)
        {
            if(i <= 30)
                solve8(rand()%10+1,rand()%10+1);
            else if(i <= 60)
                solve8(rand()%100+1,rand()%100+1);
            else
                solve8(rand()%1000+1,rand()%1000+1);
        }
    }
    else if(test_file == 16)
    {
        t = 5;
        cout << t << endl;

        for(int i=1;i<=t;i++)
        {
            if(i <= 2)
                solve8(10000,10000);
            else
                solve8(100000,100000);
        }
    }
    else if(test_file == 17)
    {
        t = 90;
        cout << t << endl;

        for(int i=1;i<=t;i++)
        {
            if(i <= 30)
                solve8(10,10);
            else if(i <= 60)
                solve8(100,100);
            else
                solve8(1000,1000);
        }
    }
    else if(test_file == 18)
    {
        int t = 1e3;
        cout << t << endl;

        for(int i=0;i<t;i++)
        {
            cout << 32 << " " << 2 << endl;

            cout << 1 << " ";
            for(int i=2;i<=31;i++)
                cout << i << endl << i << " ";
            cout << 32 << endl;

            cout << 1 << " " << 1 << " " << 32 << " " << 44000 + rand()%t << endl;
            cout << 2 << " " << 1 << " " << 16 << endl;
        }
    }
    else if(test_file == 19)
    {
        int t = 500;
        cout << t << endl;

        for(int i=0;i<t;i++)
            solve8(1e3,1e3);
    }
    else if(test_file == 20)
    {
        int t = 5000;
        cout << t << endl;

        for(int i=0;i<t;i++)
            solve8(rand()%100+1,rand()%100+1);
    }
}

bool vis[200010];
vector <int> v2[200010];
int a[200010];
int tx,sum;
int cnt;

void dfs(int x)
{
    vis[x] = true;
    cnt++;

    for(int i:v2[x])
    {
        if(!vis[i])
            dfs(i);
    }
}

bool dfs1(int x, int cnt1)
{
    vis[x] = true;

    bool ans = false;

    if(x == tx)
        ans = true;

    for(int i:v2[x])
    {
        if(!vis[i])
            ans |= dfs1(i,cnt1-1);
    }

    if(ans)
        a[x] = (a[x] + cnt1)%mod;

    return ans;
}

bool dfs2(int x)
{
    vis[x] = true;

    bool ans = false;

    if(x == tx)
        ans = true;

    for(int i:v2[x])
    {
        if(!vis[i])
            ans |= dfs2(i);
    }

    if(ans)
        sum = (sum + a[x])%mod;

    return ans;
}

void __output()
{
	freopen(input, "r", stdin);
	freopen(output, "w", stdout);

	int t;
	cin >> t;
	// assert(1 <= t && t <= 1e5);

    // int tot1,tot2;
    // tot1 = tot2 = 0;

    while(t--)
    {
        int n,q;
        cin >> n >> q;
        // assert(1 <= n && n <= 1e5);
        // assert(1 <= q && q <= 1e5);

        // tot1 += n;
        // tot2 += q;

        for(int i=0;i<=n;i++)
            v2[i].clear(), a[i] = 0, vis[i] = false;

        int temp = n;

        while(--temp)
        {
            int x,y;
            cin >> x >> y;
            // assert(x != y);
            // assert(1 <= x && x <= n);
            // assert(1 <= y && y <= n);

            v2[x].push_back(y);
            v2[y].push_back(x);
        }

        // cnt = 0;
        // dfs(1);
        // assert(cnt == n);

        temp = q;

        while(temp--)
        {
            int type;
            cin >> type;
            // assert(type == 1 || type == 2);

            for(int i=0;i<=n;i++)
                vis[i] = false;

            if(type == 1)
            {
                int x,y,z;
                cin >> x >> y >> z;
                // assert(1 <= x && x <= n);
                // assert(1 <= y && y <= n);
                // assert(n <= z && z <= 1e9);

                tx = y;
                dfs1(x,z);
            }
            else
            {
                int x,y;
                cin >> x >> y;
                // assert(1 <= x && x <= n);
                // assert(1 <= y && y <= n);

                sum = 0;
                tx = y;
                dfs2(x);

                cout << sum << endl;
            }
        }
    }

    // assert(1 <= tot1 && tot1 <= 500000);
    // assert(1 <= tot2 && tot2 <= 500000);
}

int32_t main() 
{
	srand(time(0));

    int T = 20;

	for(int t = 0; t<T; ++t)
    {
        if(t == 20)
        {
            output[13] = input[11] = '2';
			output[14] = input[12] = '0';
        }
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
		// __output();
	}
	return 0;
}