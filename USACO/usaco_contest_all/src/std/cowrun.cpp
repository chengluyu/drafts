#include <cstdio>
using namespace std;

//FILE *fout = fopen ("cowrun.out", "w");
//FILE *fin = fopen ("cowrun.in", "r");
FILE *fout = stdout;
FILE *fin = stdin;

const int MAXN = 10005;

int N, M;
int dist [MAXN], best [MAXN];

int main ()
{
    fscanf (fin, "%d %d", &N, &M);

    for (int i = 0; i < N; i++)
        fscanf (fin, "%d", dist + i);


    for (int i = 0; i < N; i++)
    {
// skip the value
        if (best [i] > best [i + 1])
            best [i + 1] = best [i];

        int sum = best [i], pos = i;

        for (int j = 0; j < M && pos < N; j++)
        {
// update each value
            sum += dist [i + j];
            pos += 2;

            if (sum > best [pos])
                best [pos] = sum;
        }
    }

    fprintf (fout, "%d\n", best [N]);

    return 0;
}
