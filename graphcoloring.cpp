#include<bits/stdc++.h>

using namespace std;

bool isSafeToColor(int v, vector < vector < int >> & graphMatrix, vector < int > color, int c, int V) {
    for (int i = 0; i < V; i++){
        if (graphMatrix[v][i] == 1 && c == color[i]){
            return false;
        }
    }
    return true;
}

bool graphColorUtil(vector < vector < int >> & graphMatrix, int m, vector < int > color, int v, int V){
    if (v == V){
        return true;
    }

    for (int i = 1; i <= m; i++){
      if (isSafeToColor(v, graphMatrix, color, i, V)){
        color[v] = i;
        if(graphColorUtil(graphMatrix, m, color, v + 1, V)){
            return true;
        }
        color[v] = 0;
      }
    }
    return false;
}

void printColoringSolution(vector<int> &color, int V) {
    cout << ("Color schema for vertices are: ") << endl;
    for (int i = 0; i < V; i++){
        cout << (color[i]) << endl;
    }
  }
bool graphColoring(vector < vector < int >> & graphMatrix, int m, int V) {
    vector<int> color(V, 0);
 
    if (!graphColorUtil(graphMatrix, m, color, 0, V)) {
      cout << "Color schema not possible" << endl;
      return false;
    }
 
    printColoringSolution(color, V);
    return true;
}

int main(){

    int V=4, m=5;

    vector<vector<int>> graphMatrix={
        {0, 0, 1, 0, 1},
        {0, 0, 1, 1, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0}
    };

    graphColoring(graphMatrix, m, V);

    return 0;
}