
#include <cstdio>
#include <vector>

using namespace std;
const int inf = 1 << 30;

// given adjacency matrix adj, finds shortest path from A to B
int dijk(int A, int B, vector< vector<int> > adj) {
  int n = adj.size();
  vector<int> dist(n);
  vector<bool> vis(n);

  for(int i = 0; i < n; ++i) {
    dist[i] = inf;
  }
  dist[A] = 0;

  for(int i = 0; i < n; ++i) {
    int cur = -1;
    for(int j = 0; j < n; ++j) {
      if (vis[j]) continue;
      if (cur == -1 || dist[j] < dist[cur]) {
        cur = j;
      }
    }

    vis[cur] = true;
    for(int j = 0; j < n; ++j) {
      int path = dist[cur] + adj[cur][j];
      if (path < dist[j]) {
        dist[j] = path;
      }
    }
  }

  return dist[B];
}

int main() {
  int n,m;
  scanf("%d", &N);
    scanf("%d", &M);
  vector< vector<int> > adj(N);
  for(int i = 0; i < N; ++i) {
    adj[i] = vector<int>(N);
    for(int j = 0; j < N; ++j) {
      adj[i][j] = inf;
    }
  }

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      scanf("%d", &(adj[i][j]));
    }
  }

  int ans = dijk(0, N - 1, adj);
  printf("%d\n", ans);
}






