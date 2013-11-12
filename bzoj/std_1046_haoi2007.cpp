# include <iostream>
# include <cstdio>
# include <cmath>
# include <cstring>
# include <algorithm>
# define maxn 50010
using namespace std;
int dp[maxn], a[maxn], c[maxn], N, M, p, Max_dp;
 
int dichotomy(int num)
{
  int l=0, r=Max_dp, ret;
  while (l<=r) {
    int mid=(l+r)>>1;
    if (c[mid]>num)
      l=mid+1, ret=mid;
    else r=mid-1;
  }
  return ret;
}
 
void PUT_OUT(int p)
{
  int L=-0x7ffffff;
  for (int i=1; i<=N; i++) 
    if (dp[i]>=p && a[i]>L) {
      printf("%d",a[i]);
      if (p==1) {
      printf("\n"); break;
      } else printf(" "), p--, L=a[i];
    }
}
 
int main()
{
  scanf("%d",&N);
  for (int i=1; i<=N; i++)
    scanf("%d",&a[i]);
  memset(c, 128, sizeof(c));
  c[0]=0x7ffffff, Max_dp=0;
  for (int i=N; i>0; i--) {
    int t=dichotomy(a[i]);
    dp[i]=t+1;
    c[dp[i]]=max(c[dp[i]], a[i]);
    Max_dp=max(Max_dp, dp[i]);
  }
  scanf("%d",&M);
  while (M--) {
    scanf("%d",&p);
    if (p>Max_dp) printf("Impossible\n");
    else PUT_OUT(p);
  }
  for (int i = 1; i <= N; ++i)
    cout << dp[i] << ' ';
  return 0;
}