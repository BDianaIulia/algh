//https://www.infoarena.ro/problema/camionas

#include <iostream>
#include <fstream>
#include <vector>
#define DIM 50010
#define INF 1000000000

using namespace std;

vector<pair<int, int> > L[DIM*2];
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

    for(;;)
    {
        minim = INF;
        for( i = 1; i <= n; i++ )
            if( v[i] == 0 && D[i] < minim )
            {
                minim = D[i];
                nod = i;
            }

        if( minim == INF )
            break;

        v[nod] = 1;
        for( i = 0; i < L[nod].size(); i++)
        {
            vecin = L[nod][i].first;
            cost = L[nod][i].second;

            if( cost < g && D[vecin] > D[nod] + 1 )
                D[vecin] = D[nod] + 1;
            else
                D[vecin] = D[nod];
        }
    }

    fout << D[n];
    return 0;
}
