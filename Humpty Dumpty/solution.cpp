#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tt;
    cin >> tt;

    while(tt--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int c1,c2;
        c1 = c2 = 0;

        for(auto i:s)
            i == '1' ? c1++ : c2++;

        if(min(c1,c2)%2)
            cout << "Humpty Dumpty\n";
        else
            cout << "King\n";
    }
    
    return 0;
}