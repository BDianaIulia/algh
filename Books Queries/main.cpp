//https://codeforces.com/problemset/problem/1066/C

#include <iostream>
#include <vector>
#include <algorithm>
#define mid 200002

using namespace std;

int main()
{
    int q, m, t;
    char s;
    vector<int> a( mid );
    cin >> q;
    int st = 0, dr = 0;
    for( int i = 0 ; i < q ; i++ )
    {
        cin >> s >> m;
        if( i == 0 )
            a[m] = mid;
        else
        {
            if( s == 'L' )
            {
                st++;
                a[m] = mid - st;
            }
            else if( s == 'R' )
                {
                    dr++;
                    a[m] = mid + dr;
                }
                else
                {
                    cout << min( mid + dr - a[m] , a[m] - (mid - st) ) << endl;
                }
        }

    }

    return 0;
}
