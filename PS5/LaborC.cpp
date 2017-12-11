// Copy paste this C++ Template and save it as "Labor.cpp"
#include <bits/stdc++.h>
using namespace std;

// write your matric number here: A0154598M
// write your name here: Neo Ken Hong Kelvin
// write list of collaborators here: 
// year 2017 Sem1 hash code: 9sCRYVKRYjb8AjeHhpg4 (do NOT delete this line)

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

// We set V, Q, and AdjList to be global variables so that they are directly accessible in all other methods/functions
int V; // number of vertices in the graph (number of junctions in Singapore map)
int Q; // number of queries
vector<vector<ii>> AdjList; // the weighted graph (the Singapore map), the length of each edge (road) is stored here too, as the weight of edge

void PreProcess() {
  // Write necessary code to preprocess the graph, if needed
  //
  // write your answer here
  //------------------------------------------------------------------------- 
  //------------------------------------------------------------------------- 
}

int Query(int s, int t, int k) {
  int ans = -1;

  // You have to report the shortest path from Steven and Grace's current position s
  // to reach their chosen hospital t, output -1 if t is not reachable from s
  // with one catch: this path cannot use more than k vertices
  //
  // write your answer here
  if (s != t) {
    vector<iii> predecessor;  // Parent V, Weight, Junction
    predecessor.assign(V, make_tuple(-1, 1 << 30, k));
    priority_queue<iii, vector<iii>, greater<iii>> pq;  // Junction, Weight, Destination
    pq.push(make_tuple(0, 0, s));
    predecessor[s] = make_tuple(-1, -1, 1);
    while (!pq.empty()) {
      iii c = pq.top(); pq.pop();  // Get the lowest weight of the pq
      // if (get<2>(c) == t) break;
      // cout << "(" << get<1>(c) << "," << get<0>(c) << "," << get<2>(c) << ") -> ";

      for (ii n: AdjList[get<2>(c)]) {  // Go through all the neighbours of the current node
        iii pd = predecessor[n.first];
        int nw = get<1>(c) + n.second, nj = get<0>(c) + 1;
        // cout << "(" << n.first << "," << n.second << "," << nw << "," << nj << ") ";

        // Don't go backwards and check if the node is faster through the current node than the previous.
        if (get<0>(pd) != get<2>(c) && get<1>(pd) > nw && nj < k) {  
          predecessor[n.first] = make_tuple(get<1>(c), nw, nj);
          pq.push(make_tuple(nj, nw, n.first));
        }
      }
      // cout << endl;
    }
    ans = get<1>(predecessor[t]) == 1 << 30 ? -1 : get<1>(predecessor[t]);
    // for (auto a: cache[s]) {
    //   cout << "(" << a.first << "," << a.second << ") ";
    // }
    // cout << endl;
  } else {
    ans = 0;
  }
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