#include <cstdio>
using namespace std;

FILE *fout = fopen ("contest.out", "w");
FILE *fin = fopen ("contest.in", "r");

const int MAXN = 105;

int N, M;
bool reach [MAXN][MAXN];
int total = 0;

int main ()
{
    fscanf (fin, "%d %d", &N, &M);

// cows are 'connected' to themselves
    for (int i = 0; i < N; i++)
  reach [i][i] = true;

// read input
    int a, b;
    for (int i = 0; i < M; i++)
    {
  fscanf (fin, "%d %d", &a, &b);
  a--, b--;

  reach [a][b] = true;
    }

// use Floyd-Warshall to compute transitive closure
    for (int k = 0; k < N; k++)
  for (int i = 0; i < N; i++)
      if (reach [i][k])
    for (int j = 0; j < N; j++)
        if (reach [k][j])
      reach [i][j] = true;


    for (int i = 0; i < N; i++)
    {
  bool good = true;

// we can find the rank of a cow if all other cows are connected to it
  for (int j = 0; j < N; j++)
      if (!reach [i][j] && !reach [j][i])
      {
    good = false;
    break;
      }

  if (good)
      total++;
    }

    fprintf (fout, "%d\n", total);

    return 0;
}
