# Data Structures: Assignment 3 - Priority Queue & Dijkstra

This project contains the files for Assignment 3 (Priority Queue & Dijkstra) of the course Data Structures, taught by *dr. H.J. Hoogeboom* in the Fall semester of 2019 at *Leiden University*.

## How-to
Run `make` in terminal from the project root-folder to build the executable: **Priority**

Upon execution the program requests a filename for a file of type **.grf*. The filename without extension should be specified. Example, for file *fibo.grf*: `Input filename: fibo`.

## Graphs
The implemented *Graph* assumes that edges are directional. Thus, for non-directional graphs, edges must be added twice (2x) with the same weight; once for each vertex.

For example: A non-directed graph that has an edge between vertices v1 & v2, the adjacency-list that is implemented in *Graph*, should show the existence of the edge at both index 1 & index 2. 

To demonstrate this difference 2 examples graphs are provided:

* **test_directed.grf**
* **test_nondirected.grf**

Dijkstra's Algorithm will have different results in the output, for the shortest path-distances from a given starting node.

## Project Files
* Makefile

### include
* dijkstra.h
* graph.h
* priority.h

### src
* main.cpp

## Author
* **Efraim Lumunon (s1077694)** --- e-mail: [e.m.w.lumunon@umail.leidenuniv.nl](mailto:e.m.w.lumunon@umail.leidenuniv.nl)
