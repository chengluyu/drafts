#include <iostream>
using namespace std;
FILE *in = fopen("fliptile.in", "r"), *out = fopen("fliptile.out", "w");
bool data[20][20],grid[20][20];
int n,m;
void flip(int x, int y) //flips grid[][] at position (x,y)
{
  grid[x][y]=!grid[x][y];
  if (x>0) grid[x-1][y]=!grid[x-1][y];
  if (y>0) grid[x][y-1]=!grid[x][y-1];
  if (x<n-1) grid[x+1][y]=!grid[x+1][y];
  if (y<m-1) grid[x][y+1]=!grid[x][y+1];
}
int solution[20][20],best[20][20];
int bestflips=1000000;
void finishsolution(void)
{
  int i,j;
  //first copy data to grid to work with
  for (i=0;i<n;i++) for (j=0;j<m;j++) grid[i][j]=data[i][j];
  //flip the things in the first row
  for (j=0;j<m;j++) if (solution[0][j]==1) flip(0,j);
  //starting from second row down, flip the tiles we are forced to
  for (i=1;i<n;i++) for (j=0;j<m;j++)
  {
    solution[i][j]=grid[i-1][j];
    if (grid[i-1][j]) flip(i,j);
  }
  //now check to see if anything is left
  bool allclear=true;
  for (j=0;j<m;j++) if (grid[n-1][j]) {allclear=false; break;}
  if (allclear)
  {
    //then this is a solution. check if this is better than what we have
    int flips=0;
    for (i=0;i<n;i++) for (j=0;j<m;j++) if (solution[i][j]) flips++;
    if (flips<bestflips) //this solution is better
    {
      bestflips=flips;
      for (i=0;i<n;i++) for (j=0;j<m;j++) best[i][j]=solution[i][j];
    }
  }
}
int main(void)
{
  int i,j,a;
  //read in data
  fscanf(in,"%i %i",&n,&m);
  for (i=0;i<n;i++) for (j=0;j<m;j++)
  {fscanf(in,"%i",&a); data[i][j]=(a==1);}
  //generate all possible top rows
  for (j=0;j<m;j++) solution[0][j]=0;
  while (true)
  {
    finishsolution();
    //generate the next higher combination
    solution[0][m-1]++;
    for (j=m-1;j>0;j--) if (solution[0][j]>1)
      {solution[0][j]-=2; solution[0][j-1]++;}
    if (solution[0][0]>1) break; //we're done
  }
  if (bestflips==1000000) fprintf(out,"IMPOSSIBLE\n");
  else
  {
    for (i=0;i<n;i++) for (j=0;j<m;j++)
      fprintf(out,"%i%c",best[i][j],j==m-1?'\n':' ');
  }
  fclose(in); fclose(out); return 0;
}