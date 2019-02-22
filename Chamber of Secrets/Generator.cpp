#include<bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

char input__[] = "input/input00.txt";
char output__[] = "output/output00.txt";
int givegcd(int a,int b)
{
	if(a>b)
		return givegcd(b,a);
	else if(a==0 && a==b)
		return 0;
	else if(a==0)
		return b;
	else 
		return __gcd(a,b);
}
void input2(int T)
{
	freopen(input__, "w", stdout);
	cout<<100<<endl;
	int t,i;
	for(t=0;t<10;t++)
	{
		int n=2;
		cout<<n<<endl;
		cout<<rand()%1000<<" "<<rand()%1000<<endl;
	}
	int j;
	int k=1000;
	for(t=10;t<100;t++)
	{
		j=rand()%2;
		if(j==0)
		{
			int n;
			n=rand()%k +k;
			cout<<n<<endl;
			int first=rand()%10000;
			int second=first + t;
			if(first>second)
			{
				int temp=first;
				first=second;
				second=temp;
			}
			// cout<<first<<" "<<second<<" ";
			vector<int> v;
			v.push_back(first);
			v.push_back(second);
			for(i=0;i<n-2;i++)
			{
				int third=second+givegcd(first,second);
				v.push_back(third);
				// cout<<third<<" ";
				first=second;
				second=third;
			}

			random_shuffle(v.begin(),v.end());

			for(i=0;i<v.size();i++)
			{
				cout<<v[i]<<" ";
			}
			cout<<endl;
		}
		else
		{
			int n;
			n=rand()%k +k;
			cout<<n<<endl;
			for(int i=0;i<n;i++)
			{
				cout<<rand()%1000<<" ";
			}
			cout<<endl;
		}

	}
}
void input(int T)
{
	freopen(input__, "w", stdout);
	cout<<20<<endl;
	int j,i,k,t;
	if(T<10)
			k=1000;
		else
			k=100000;
	for( t=0;t<17;t++)
	{
		// cout<<"test no."<<t<<endl;
		j=rand()%2;
		
		if(j==0)
		{
			int n;

			n=rand()%k +k;
			cout<<n<<endl;
			int first=rand()%100;
			int second=rand()%100;
			if(first>second)
			{
				int temp=first;
				first=second;
				second=temp;
			}
			// cout<<first<<" "<<second<<" ";
			vector<int> v;
			v.push_back(first);
			v.push_back(second);
			for(i=0;i<n-2;i++)
			{
				int third=second+givegcd(first,second);
				v.push_back(third);
				// cout<<third<<" ";
				first=second;
				second=third;
			}

			random_shuffle(v.begin(),v.end());

			for(i=0;i<v.size();i++)
			{
				cout<<v[i]<<" ";
			}
			cout<<endl;
		}
		else
		{
			int n;
			n=rand()%k +k;
			cout<<n<<endl;
			for(int i=0;i<n;i++)
			{
				cout<<rand()%1000<<" ";
			}
			cout<<endl;
		}
	}
	// cout<<"test no."<<t++<<endl;
	cout<<10*T<<endl;
	for(i=0;i<10*T;i++)
	{
		cout<<0<<" ";
	}
	cout<<endl;
	// cout<<"test no."<<t++<<endl;
	int n;
	n=rand()%k +k;
	cout<<n<<endl;
	int first=rand()%100;
	int second=rand()%100;
	if(first>second)
	{
		int temp=first;
		first=second;
		second=temp;
	}
	// cout<<first<<" "<<second<<" ";
	vector<int> v;
	v.push_back(first);
	v.push_back(second);
	for(i=0;i<n-2;i++)
	{
		int third=second+givegcd(first,second);
		v.push_back(third);
		// cout<<third<<" ";
		first=second;
		second=third;
	}
	v[v.size()-1]=v[n/2];
	random_shuffle(v.begin(),v.end());

	for(i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	n=rand()%1000 +1000;
	// cout<<"test no."<<t++<<endl;
	cout<<n<<endl;
	cout<<"0 0 0 0 ";
	for(i=4;i<n;i++)
	{
		cout<<i<<" "; 
	}
	cout<<endl;


}

void output()
{
	freopen(input__, "r", stdin);
	freopen(output__, "w", stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		int i,first,second;
		cin>>n;
		assert(n<1000000 && n>=1);
	    int arr[n];
	    map<int,int> m;
	    for(i=0;i<n;i++)
	    {
	    	cin>>arr[i];
	    	assert(arr[i]>=0 && arr[i]<=1e9);
	    	m[arr[i]]++;
	    }
	    if(n==1)
	    {
	    	cout<<arr[0]<<endl;
	    }
	    else if(n==2)
    	{
    	sort(arr,arr+n);
    	cout<<arr[1]<<" "<<arr[0]<<endl;
    	}
	    else
	    {
		    sort(arr,arr+n);
		    // for(i=0;i<n;i++)
		    // {
		    // 	cout<<arr[i]<<" ";
		    // }
		    // cout<<endl;
		    if(arr[0]==0 && arr[1]==0)
		    {
		    	// cout<<"yo\n";
		    	if(m[0]==n)
		    	{
		    		for(i=0;i<n;i++)
		    		{
		    			cout<<0<<" ";
		    		}
		    		cout<<endl;
		    	}
		    	else 
		    	{
		    		cout<<-1<<endl;
		    	}
		    }
		    
		    else
		    {
		    	m[arr[0]]--;
		    	m[arr[1]]--;
		    	first=arr[0];
		    	second=arr[1];
		    	vector<int> v;
		    	v.pb(first);
		    	v.pb(second);
		    	// cout<<first<<" "<<second<<endl;
		    	for(i=2;i<n;i++)
		    	{

		    		int third=second+givegcd(first,second);
		    		 // cout<<third<<endl;
		    		if(m.find(third)==m.end())
		    		{
		    			break;
		    		}
		    		else
		    		{
		    			m[third]--;
		    			first=second;
		    			second=third;
		    			v.pb(third);
		    		}
		    		 // cout<<v.size()<<"size"<<endl;
		    	}
		    	int count=0;
		    	int num;
		    	for(auto it=m.begin();it!=m.end();it++)
		    	{
		    		if(it->second==1)
		    		{
		    			num=it->first;
		    		}
		    		count+=it->second;
		    	}
		    	// cout<<num<<endl;
		    	if(count>1)
		    		cout<<"-1\n";
		    	else if(count==1)
		    	{
		    		if(givegcd(num,v[0])+v[0]==v[1])
		    		{
		    			cout<<num<<" ";
		    			for(i=0;i<v.size();i++)
		    			{
		    				cout<<v[i]<<" ";
		    			}
		    			cout<<endl;
		    		}
		    		else
		    		{
		    			// cout<<"yo2";
		    			cout<<"-1\n";
		    		}
		    	}
		    	else
		    	{
		    		if(givegcd(v[v.size()-1],v[0])+v[0]==v[1])
		    		{
		    			cout<<v[v.size()-1]<<" ";
		    			for(i=0;i<(v.size()-1);i++)
		    			{
		    				cout<<v[i]<<" ";
		    			}
		    			cout<<endl;
		    		}
		    		else
		    		{
		    			for(i=0;i<v.size();i++)
		    			{
		    				cout<<v[i]<<" ";
		    			}
		    			cout<<endl;
		    		}
		    	}
		    	
		    }
		}
	}
}

int32_t main() {

	srand(time(0));
    int T = 20;
    
    int t;
	for( t = 0; t < 18; t++) 
    {
    	// cout<<t<<endl;
		if(t == 10) 
        {
			output__[13] = input__[11] = '1';
			output__[14] = input__[12] = '0';
		}
		else if(t > 0)
        {
			output__[14]++;
            input__[12]++;
        }
        // cout<<input__<<endl;
		//input(t+1);
		output();
	}
	while(t<T)
	{
		output__[14]++;
        input__[12]++;
		// cout<<input__<<endl;
		//input2(t+1);
		t++;
		 output();
		
	}
	return 0;
}