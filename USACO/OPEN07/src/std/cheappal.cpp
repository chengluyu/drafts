#include <stdio.h>
#include <algorithm>
#define MAXN 2001

FILE *in = fopen("cheappal.in","r");
FILE *out = fopen("cheappal.out","w");

using std::max;

int n, m, is[26], de[26], dp[MAXN][MAXN];
char str[MAXN + 1];

int main () {
    int i, j, a, b;
    char ch;
    
    fscanf (in, "%d%d%s", &n, &m, str);
    for (i = 0; i < n; i ++) {
        do fscanf(in,"%c",&ch);
            while (ch <= ' ');
        fscanf(in,"%d%d",&a,&b);
        is[ch - 'a'] = a;
        de[ch - 'a'] = b;
        }
    for (a = 0; a < m; a ++)
        for (i = 0; i + a < m; i ++) {
            j = i + a;
            if (i == j || i + 1 == j && str[i] == str[j])
                dp[i][j] = 0;
            else {
                dp[i][j] = dp[i+1][j] + max(max(is[str[i]-'a'], de[str[i]-'a']), (dp[i][j-1] + max(is[str[j]-'a'], de[str[j]-'a'])));
                if (str[i] == str[j])
                    dp[i][j] = max(dp[i][j], dp[i+1][j-1]);
                }
            }
    fprintf(out,"%d\n",dp[0][m - 1]);
    fclose(in);
    fclose(out);
    return 0;
}