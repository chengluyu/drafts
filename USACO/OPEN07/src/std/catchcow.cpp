#include <iostream>
using namespace std;
FILE *in = fopen("catchcow.in", "r"), *out = fopen("catchcow.out", "w");
#define QSIZE 200000
int whereinqueue[QSIZE]; //index of element in queue, -1 if not in queue
int q[QSIZE],qstart,qend; //this is a circular array queue
int dist[QSIZE]; //dist[x] = distance to x from starting position
int n,k;

/*update x in queue, or add if not already in queue and dist==-1*/
void update(int x, int d)
{
  if (whereinqueue[x]==-1 && dist[x]==-1)
  {
    dist[x]=d;
    //add x to the end of queue
    q[qend]=x; whereinqueue[x]=qend;
    qend++; if (qend==QSIZE) qend=0;
  }
}
void processqueue(void) /*process the element at the head of the queue*/
{
  int x=q[qstart],d=dist[q[qstart]];
  //we need to add all places we can reach to the queue
  if (x+1<QSIZE) update(x+1,d+1);
  if (x-1>=0) update(x-1,d+1);
  if (2*x<QSIZE && x!=0) update(2*x,d+1);
  //remove head of queue
  whereinqueue[x]=-1;
  qstart++; if (qstart==QSIZE) qstart=0;
}
int main(void)
{
  int i;
  fscanf(in,"%i %i",&n,&k);
  for (i=0;i<QSIZE;i++) {whereinqueue[i]=-1; dist[i]=-1;}
  q[0]=n; dist[n]=0; qstart=0; qend=1; //start at point n
  while (qstart!=qend) processqueue();
  fprintf(out,"%i\n",dist[k]);
  fclose(in); fclose(out); return 0;
}