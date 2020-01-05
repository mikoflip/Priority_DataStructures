/**                                                                                                 
 * Data Structures: Assignment 3 - Priority Queue & Dijkstra
 *                                                                                                  
 * Dijkstra: Implementation of Dijkstra's Algorithm using Min Priority Queue.
 *                                                                                                 
 * @author Efraim Lumunon (s1077694)                                                                
 * @file dijkstra.h                                                                                 
 * @date 29-11-2019                                                                                 
 **/    

#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include "graph.h"
#include "priority.h"

/**
 * @function Dijkstra
 * @abstract Given a graph of nodes and a starting point, the shortest paths to all other nodes is calculated using Dijkstra's Algorithm.
 * @param Pointer to Graph in adjacency list format, int start_point from which to start calculation of shortest paths, pointer to array to store distances.
 * @return -
 * @pre Parameter graph must point to valid Graph, start_point must be contained in
 *      Graph, distances must point to valid int array of sufficient size to hold
 *      distances to all nodes.
 * @post Pointer distances points to array containing all shortest path distances from
 *       node start_point.
 **/
void Dijkstra(const Graph *graph, const int &start_point, int *distances){
  MinPriorityQueue<int> pq;
  PriorityItem<int> item;
  const int &num_vertices = graph->GetSize();

  // INITIALIZATION
  for(int v = 0; v < num_vertices; v++){
    if(v == start_point){
      distances[v] = 0;
    } else {
      distances[v] = INT_MAX;
    }
  }
  
  // DIJKSTRA
  pq.Insert(start_point, distances[start_point]);

  while(!pq.IsEmpty()){
    item = pq.GetMinimum();
    pq.DeleteMinimum();
    const std::vector<Node> &adjacent_nodes = graph->GetNeighbors(item.key);

    for(auto &node : adjacent_nodes){
      if(node.weight + distances[item.key] < distances[node.vertex])
      {
        distances[node.vertex] = node.weight + distances[item.key];
        pq.Insert(node.vertex, node.weight);
      }
    }
  }
}

#endif // DIJKSTRA_H_
