#include <iostream>
using namespace std;
int seq[10000], dist[100][100];
int main() {
	freopen("danger.in", "rt", stdin);
	freopen("danger.out", "wt", stdout);
	int m, n;
	cin>>n>>m;
	for (int i = 0; i < m; ++i) {
		cin>>seq[i];
		seq[i]--;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin>>dist[i][j];
		}
	}
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	int sum=0;
	for (int i = 1; i < m; ++i) {
		sum+=dist[seq[i-1]][seq[i]];

	}
	cout<< sum << endl;
	return 0;
}
