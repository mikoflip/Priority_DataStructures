/**                                                                                                 
 * Data Structures: Assignment 3 - Priority Queue & Dijkstra
 *                                                                                                  
 * Graph: Implementation of a Graph as an adjacency list of Nodes. Through the use
 *        of member functions, the API allows Edges to be added to the Graph, the
 *        size of the Graph be queried, as well as let the Graph be printed to the
 *        console.
 *        The adjacency list is implemented using a vector of vector of Nodes.
 * 
 *        (*) This Graph assumes that edges are directional. Thus, for non-directional
 *        graphs, edges must be added twice (2x) with the same weight; once for each
 *        vertex.
 * 
 * @author Efraim Lumunon (s1077694)                                                                
 * @file graph.h                                                                                 
 * @date 29-11-2019                                                                                 
 **/    

#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <vector>

struct Node {
  int vertex;
  int weight;

  Node(){}
  Node(const int &vertex, const int &weight):vertex(vertex), weight(weight){}
  ~Node(){}
};

class Graph {
public:
  Graph();
  Graph(const int &num_vertices);
  ~Graph();

  /**
   * @function GetSize
   * @abstract Get count of Nodes currently making up Graph.
   * @param -
   * @return Integer indicating the count of Nodes in Graph (num_vertices).
   * @pre -
   * @post -
   **/
  int GetSize() const;

  /**
   * @function GetNeighbors
   * @abstract Get neighboring Nodes of Node by returning row in adjacency_list.
   * @param Int value of Node (vertex) to get neighboring nodes of.
   * @return Vector of type Node containing neighboring Nodes of Node.
   * @pre Parameter from must be within bounds of amount of Nodes contained within
   *      Graph.
   * @post -
   **/
  std::vector<Node> GetNeighbors(const int &from) const;

  /**
   * @function AddEdge
   * @abstract Add an edge in Graph. If during construction a lower (or no) expected
   *           amount of nodes was specified, more memory is allocated on the heap.
   * @param Int values indicating "from" & "to" Nodes (vertices), int value for edge weight.
   * @return -
   * @pre Edges are assumed to be directional; Call this member function twice (2x) for
   *      non-directional graphs; once for each vertex.
   * @post Adjacency_list has been modified with entry indicating edge from & to Node.
   *       If there are gaps in used indices for vertices when adding edges, in-between
   *       indices (vertices) with no edges are basically disconnected Nodes in graph.
   **/
  void AddEdge(const int &from, const int &to, const unsigned int &weight);

  /**
   * @function Print
   * @abstract Print Graph (adjacency_list) to console; Main vector is traversed, and
   *           if edges are available these are also printed to the console.
   *           (*) To print only Nodes that have edges to other nodes, uncomment
   *           if-statement in member function body.
   * @param -
   * @return -
   * @pre -
   * @post Graph is printed to console.
   **/
  void Print() const;

private:
  int num_vertices;
  std::vector<std::vector<Node>> adjacency_list;
};

Graph::Graph():num_vertices(0){}

Graph::Graph(const int &num_vertices):num_vertices(num_vertices){
  adjacency_list.reserve(num_vertices);
}

Graph::~Graph(){
  adjacency_list.clear();
}

int Graph::GetSize() const {
  return num_vertices;
}

std::vector<Node> Graph::GetNeighbors(const int &from) const {
  return adjacency_list[from];
}

void Graph::AddEdge(const int &from, const int &to, const unsigned int &weight){
  if(num_vertices < from){
    adjacency_list.resize(from); // ALLOCATE EXTRA MEMORY
    adjacency_list[from-1].emplace_back(to-1, weight);
    num_vertices = from;
  } else {
    adjacency_list[from-1].emplace_back(to-1, weight);
  }
}

void Graph::Print() const {
  for(int v = 0; v < num_vertices; v++){
    // if(adjacency_list[v].size() > 0){    // UNCOMMENT FOR PRINT WHERE EDGES ONLY
      std::cout << v+1;
      for(auto &node : adjacency_list[v]){
        std::cout << "->" << node.vertex+1;
      }
      std::cout << std::endl;
    // }                                    // UNCOMMENT FOR PRINT WHERE EDGES ONLY
  }
}

#endif // GRAPH_H_
