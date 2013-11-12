#include <fstream>
#define PID "egroup"
std::ifstream cin(PID ".in");
std::ofstream cout(PID ".out");
using namespace std;
int a[30005],f[30005]={1},f2[30005]={1};
int main()
{
  int n;cin>>n;
  for(int i=0;i<n;++i)
    cin>>a[i];
  int temp=0,temp1=0,maxtemp;
  for(int i=0;i<n;++i)
    {
    for(int j=0;j<i;++j)
    { if(a[i]>=a[j]&&f[j]>temp) temp=f[j];
      if(a[j]>=a[i]&&f2[j]>temp1) temp1=f2[j];  }
     f[i]=temp+1; f2[i]=temp1+1;
      } 
  int maxnu=max(f[n-1],f2[n-1]);
  cout<<n-maxnu;
  return 0;


}