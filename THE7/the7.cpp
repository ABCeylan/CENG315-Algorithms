#include "the7.h"

/*struct Road {
  std::pair<int, int> endpoints;
  int time;
  Road(std::pair<int, int> eps, int t) : endpoints(eps), time(t) {}
};*/

void AdjMatrixHelper(int** result, int n, std::vector<Road> roads){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            result[i][j] = 0;
        }
    }
    for(unsigned int i = 0; i < roads.size(); i++){
        result[roads[i].endpoints.first][roads[i].endpoints.second] = roads[i].time;
        result[roads[i].endpoints.second][roads[i].endpoints.first] = roads[i].time;
    }
}

int minDistance(int dist[], bool sptSet[], int numOfVertices)
{
  
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < numOfVertices; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void dijkstra(int** graph, int src, int numOfVertices, int* dist, bool* sptSet, int* parent)
{
    


    for (int i = 0; i < numOfVertices; i++)
        dist[i] = INT_MAX, sptSet[i] = false, parent[0] = -1;

    dist[src] = 0;

    for (int count = 0; count < numOfVertices - 1; count++) {
        
        int u = minDistance(dist, sptSet, numOfVertices);

        sptSet[u] = true;

        for (int v = 0; v < numOfVertices; v++)

           
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]){
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
                
    }
    

}

void FindRoute(int n, std::vector<Road> roads, int s, int d, int x, int y) {
  // You can change these variables. These are here for demo only.
  std::vector<int> path;
  std::vector<int> path2;
  int** adjMatrix = new int* [n];
  bool sptSet[n]; 
  int cost, current;
  int dist[n];
  int parent[n];
  int first = 0;
  int second = 0;
  for(int i = 0; i < n; i++){
      sptSet[i] = false;
      dist[i] = 0;
      parent[i] = 0;
  }

    for (int i = 0; i < n; i++)
    {
        adjMatrix[i] = new int[n];
    }
    AdjMatrixHelper(adjMatrix, n, roads);
    
    //
    path.insert(path.begin(), d);
    dijkstra(adjMatrix, y, n, dist, sptSet, parent);
    first += dist[d];
    current = parent[d];
    while(current != y){
        path.insert(path.begin(), current);
        current = parent[current]; 
    }
    for(int i = 0; i < n; i++){
      sptSet[i] = false;
      dist[i] = 0;
      parent[i] = 0;
    }
    
    //
    
    path.insert(path.begin(), y);
    dijkstra(adjMatrix, x, n, dist, sptSet, parent);
    first += dist[y];
    current = parent[y];
    while(current != x){
        //std::cout << current << std::endl;
        path.insert(path.begin(), current);
        current = parent[current]; 
    }
    for(int i = 0; i < n; i++){
      sptSet[i] = false;
      dist[i] = 0;
      parent[i] = 0;
    }
    
    //
    
    path.insert(path.begin(), x);
    dijkstra(adjMatrix, s, n, dist, sptSet, parent);
    first += dist[x];
    current = parent[x];
    while(current != s){
        path.insert(path.begin(), current);
        current = parent[current]; 
    }
    for(int i = 0; i < n; i++){
      sptSet[i] = false;
      dist[i] = 0;
      parent[i] = 0;
    }
    
    path.insert(path.begin(), s);
   
   
   
   
   
    ////////////
    
    path2.insert(path2.begin(), d);
    dijkstra(adjMatrix, x, n, dist, sptSet, parent);
    second += dist[d];
    current = parent[d];
    while(current != x){
        path2.insert(path2.begin() , current);
        current = parent[current]; 
    }
    
    
    
    path2.insert(path2.begin(), x);
    dijkstra(adjMatrix, y, n, dist, sptSet, parent);
    second += dist[x];
    current = parent[x];
    while(current != y){
        path2.insert(path2.begin(), current);
        current = parent[current]; 
    }
    for(int i = 0; i < n; i++){
      sptSet[i] = false;
      dist[i] = 0;
      parent[i] = 0;
  }
    
    
    path2.insert(path2.begin(), y);
    dijkstra(adjMatrix, s, n, dist, sptSet, parent);
    second += dist[y];
    current = parent[y];
    while(current != s){
        path2.insert(path2.begin(), current);
        current = parent[current]; 
    }
    for(int i = 0; i < n; i++){
      sptSet[i] = false;
      dist[i] = 0;
      parent[i] = 0;
  }
    
    path2.insert(path2.begin(), s);
    
    if(first < second){
        cost = first;
        std::cout << cost << " ";
        PrintRange(path.begin(), path.end());
        std::cout << std::endl;
    }
    else{
        cost = second;
        std::cout << cost << " ";
        PrintRange(path2.begin(), path2.end());
        std::cout << std::endl;
    }
    
    
    

 
}


