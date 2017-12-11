// Copy paste this C++ Template and save it as "Labor.cpp"
#include <bits/stdc++.h>
using namespace std;

// write your matric number here: A0154598M
// write your name here: Neo Ken Hong Kelvin
// write list of collaborators here: 
// year 2017 Sem1 hash code: 9sCRYVKRYjb8AjeHhpg4 (do NOT delete this line)

typedef pair<int, int> ii;

// We set V, Q, and AdjList to be global variables so that they are directly accessible in all other methods/functions
int V; // number of vertices in the graph (number of junctions in Singapore map)
int Q; // number of queries
vector<vector<ii>> AdjList; // the weighted graph (the Singapore map), the length of each edge (road) is stored here too, as the weight of edge
unordered_map<int, vector<ii>> cache;

void PreProcess() {
  // Write necessary code to preprocess the graph, if needed
  //
  // write your answer here
  //------------------------------------------------------------------------- 
  cache.clear();
  cache.reserve((V << 1) + 1);
  //------------------------------------------------------------------------- 
}

int Query(int s, int t, int k) {
  int ans = -1;

  // You have to report the shortest path from Steven and Grace's current position s
  // to reach their chosen hospital t, output -1 if t is not reachable from s
  // with one catch: this path cannot use more than k vertices
  //
  // write your answer here
  if (cache.find(s) == cache.end()) {
    vector<ii> predecessor;
    predecessor.assign(V, {-1, 1 << 30});
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});
    predecessor[s] = {-1, -1};
    while (!pq.empty()) {
      ii c = pq.top(); pq.pop();  // Get the lowest weight of the pq
      // if (c.second == t) break;
      // cout << "(" << c.second << "," << c.first << ") -> ";

      for (ii n: AdjList[c.second]) {  // Go through all the neighbours of the current node
        ii pd = predecessor[n.first];
        int nw = c.first + n.second;
        // Don't go backwards and check if the node is faster through the current node than the previous.
        // cout << "(" << n.first << "," << n.second << "," << nw << ") ";
        if (pd.first != c.second && pd.second > nw) {  
          predecessor[n.first] = {c.second, nw};
          pq.push({nw, n.first});
        }
      }
      // cout << endl;
    }

    vector<ii> c;
    ii em = {-1, -1};
    c.assign(V, em);
    c[s] = {0, 0};
    for (int i = 0; i < V; i++) {  // For every vertex
      if (c[i] == em) {  // Check if the weights and junctions for this vertex are already set
        int j = k - 1, n = i;
        ii pw = predecessor[i];
        while (pw.first != -1) {  // While the predecessor exists...
          c[n] = {pw.second, j};  // Set the weight and junctions
          n = pw.first;
          pw = predecessor[n];
        }
      }
    }
    cache.insert({s, c});
  }

  ii wj = cache[s][t];
  // for (auto a: cache[s]) {
  //   cout << "(" << a.first << "," << a.second << ") ";
  // }
  // cout << endl;

  ans = wj.first;
  //------------------------------------------------------------------------- 

  return ans;
}

// You can add extra function(s) if needed
// --------------------------------------------



// --------------------------------------------

int main() {
  int i, j, TC, k, w, source, destination, required_k;
  scanf("%d", &TC);
  while (TC--) {
    scanf("%d", &V);
    // clear the graph and read in a new graph as Adjacency List
    AdjList.assign(V, vector<ii>());
    for (i = 0; i < V; i++) {
      scanf("%d", &k);
      while (k--) {
        scanf("%d %d", &j, &w);
        AdjList[i].emplace_back(j, w); // edge (road) weight (in minutes) is stored here
      }
    }
    PreProcess(); // optional
    scanf("%d", &Q);
    while (Q--) {
      scanf("%d %d %d", &source, &destination, &required_k);
      printf("%d\n", Query(source, destination, required_k));
    }
    if (TC) printf("\n");
  }
  return 0;
}