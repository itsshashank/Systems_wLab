#include <stdio.h>
#include <limits.h> 
#define max 20 

int minDistance(int dist[], bool sptSet[]) 
{ 
   // Initialize min value 
   int min = INT_MAX, min_index; 
   
   for (int v = 0; v < max; v++) 
     if (sptSet[v] == false && dist[v] <= min) 
         min = dist[v], min_index = v; 
   
   return min_index; 
} 
    
int displayV(int dist[], int n) 
{ 
   printf("Vertex   Distance from Source\n"); 
   for (int i = 0; i < max; i++) 
      printf("%d \t\t %d\n", i, dist[i]); 
} 
void dijkstra(int graph[max][max], int src) 
{ 
     int dist[max];
     bool sptSet[max]; 
    //setting every thing default
    for (int i = 0; i < max; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
    //self loops
    dist[src] = 0; 
     // shortest path for all vertices 
     for (int count = 0; count < max-1; count++) 
     { 
         int u = minDistance(dist, sptSet); 
        sptSet[u] = true; 
   
       for (int v = 0; v < max; v++) 
   
      if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX  
                                       && dist[u]+graph[u][v] < dist[v]) 
            dist[v] = dist[u] + graph[u][v]; 
     }  
     displayV(dist, max); 
} 
int main() 
{ 
   int graph[max][max] ;
   int nofVertices;
   scanf("%d",&nofVertices);
   for(int i=0;i<nofVertices;i++)
   {
       for(int j=0;j<nofVertices;j++)
       {
       printf("enter the weight of %d-%d : ",i+1,j+1);
       scanf("%d",&graph[i][j]);
       }
   }
    dijkstra(graph, nofVertices); 
   
    return 0; 
} 
