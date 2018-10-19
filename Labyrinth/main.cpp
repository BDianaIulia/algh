#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

struct st
{
    int val = 0;
    int st = 0;
    int dr = 0;
} matrix[2003][2003];

unsigned int coada[2][2003*2003];

int di[] = {0,0,-1,1};
int dj[] = {1,-1,0,0};

int n, m, x, y, d, istart, jstart, r, c, maxst, maxdr;
char ch;

int main()
{
    cin >> n >> m;
    cin >> istart >> jstart;
    cin >> maxst >> maxdr;
    for(int i = 0; i < n; i++ )
        for( int j = 0; j < m; j++ )
        {
            cin >> ch;
            if( ch == '*' )
                matrix[i][j].val = 2;
        }

    int prima = 1;
    int ultima = 1;
    coada[0][1] = istart - 1;
    coada[1][1] = jstart - 1;
    matrix[istart - 1][jstart - 1].val = 1;

    while( prima <= ultima )
    {
        int iactual = coada[0][prima];
        int jactual = coada[1][prima];
        for( d = 0; d <= 3; d++) {
            int ivecin = iactual + di[d];
            int jvecin = jactual + dj[d];

            if( ivecin >= 0 && ivecin < n && jvecin >= 0 && jvecin < m && matrix[ivecin][jvecin].val == 0 )
            {
                ultima++;
                coada[0][ultima] = ivecin;
                coada[1][ultima] = jvecin;
                matrix[ivecin][jvecin].val = 1;
                if( d == 0 )
                {
                    matrix[ivecin][jvecin].dr = 1 + matrix[iactual][jactual].dr;
                    matrix[ivecin][jvecin].st = matrix[iactual][jactual].st;
                }
                else if( d == 1 )
                    {
                        matrix[ivecin][jvecin].st = 1 + matrix[iactual][jactual].st;
                        matrix[ivecin][jvecin].dr = matrix[iactual][jactual].dr;
                    }
                    else
                    {
                        matrix[ivecin][jvecin].dr = matrix[iactual][jactual].dr;
                        matrix[ivecin][jvecin].st = matrix[iactual][jactual].st;
                    }
            }
        }
        prima++;
    }

    int counter = 0;
    for(int i = 0; i < n; i++ )
    {
        for( int j = 0; j < m; j++ )
        {
            if( matrix[i][j].st <= maxst && matrix[i][j].dr <= maxdr && matrix[i][j].val == 1 )
                counter++;
        }
    }

    cout << counter;
    return 0;
}
