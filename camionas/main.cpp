//https://www.infoarena.ro/problema/camionas
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#define DIM 50010
#define INF 1000000000

using namespace std;

vector<pair<int, int> > L[DIM*2];
set <pair<int,int> > s;
int v[DIM], D[DIM];
int n, m, i, nod, vecin, cost, x, y, c, minim, g;

int main () {
    ifstream fin ("camionas.in");
    ofstream fout("camionas.out");

    fin >> n >> m >> g;

    for( i = 0; i < m; i++ )
    {
        fin >> x >> y >> c;
        L[x].push_back( make_pair( y, c) );
        L[y].push_back( make_pair( x, c) );
    }

    D[1] = 0;
    for( i = 2; i <= n; i++ )
        D[i] = INF;

    s.insert( make_pair( 0 , 1 ) );

    while( !s.empty() )
    {
        nod = s.begin() -> second;
        s.erase( s.begin() );

        for( i = 0; i < L[nod].size(); i++ )
        {
            vecin = L[nod][i].first;
            cost = L[nod][i].second;

            if( D[vecin] > D[nod]  )
            {
                s.erase(  make_pair( D[vecin], vecin ) );
                if( cost < g )
                    D[vecin] = D[nod] + 1;
                else
                    D[vecin] = D[nod];
                s.insert(  make_pair( D[vecin], vecin ) );
            }
        }
    }

    fout << D[n];
    return 0;
}
