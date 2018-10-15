//https://www.infoarena.ro/problema/fof

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

vector < int > adj[1002];
vector< pair<int, int> > freq;
int exist[1002];
int n, m, x, y, prieten, nod;

ifstream fin("fof.in");
ofstream fout("fof.out");

bool myfunction( pair<int, int> i, pair<int, int> j )
{
    if( i.first == j.first )
        return( i.second < j.second );
    return( i.first > j.first );
}

int main()
{
    fin >> n >> m;
    for( int i = 1 ; i <= m ; i++ )
    {
        fin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int i;
    for (i=1;i<=n;i++)
        sort(adj[i].begin(), adj[i].end());

    vector<int>:: iterator it, itt;
    for( i = 1 ; i <= n ; i++ )
    {
        nod = i;
        for( int j = 0 ; j <= n + 1 ; j++ )
        {
            freq.push_back( make_pair( 0 , j ) );
            exist[j] = 0;
        }
        for( it = adj[i].begin() ; it != adj[i].end() ; it++ )
            exist[*it] = 1;

        for( it = adj[i].begin() ; it != adj[i].end() ; it++ )
        {
            prieten = *it;
            for( itt = adj[prieten].begin() ; itt != adj[prieten].end() ; itt++ )
            {
                if( *itt != nod && exist[*itt] == 0 )
                    freq[*itt].first++;
            }

        }
        sort( freq.begin() , freq.end(), myfunction );
        vector< pair<int, int> >::iterator it2;
        for( it2 = freq.begin() ; it2 != freq.end() ; it2++ )
        {
            if( it2 -> first != 0 )
            fout << it2 -> second << " ";
        }
        fout << endl;
        freq.clear();
    }

    return 0;
}
