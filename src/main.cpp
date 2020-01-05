/**
 * Data Structures: Assignment 3 - Priority Queue & Dijkstra
 *
 * @author Efraim Lumunon (s1077694)
 * @file main.cpp
 * @date 29-11-2019
 **/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "graph.h"
#include "dijkstra.h"

int main(){
	std::string input, line, word;
	std::ifstream file;
	std::ofstream export_file;
	std::istringstream ss;

	Graph *graph;

	bool word_count_set = false;
	int word_count = 0, from, to, weight;
	int *distances = nullptr;
	int start_point = 1; // GRAPH NODE INDEX STARTING FROM 1

	std::cout << "Input Filename 'xxx' (xxx.grf): ";
	std::cin >> input;

	// IMPORT
	file.open(input+".grf");
	
	while(file >> word){
		if(word[0] == '%'){ // COMMENTS
			getline(file, line);

		} else {
			if(!word_count_set){
				word_count = std::stoi(word);
				graph = new Graph(word_count);
				word_count_set = true;

			} else {
				from = std::stoi(word);
				file >> word;
				to = std::stoi(word);
				file >> word;
				weight = std::stoi(word);

				graph->AddEdge(from, to, weight);
			}
		}
	}
	
	//DIJKSTRA
	distances = new int[word_count];
	Dijkstra(graph, start_point-1, distances);

	//EXPORT
	export_file.open(input+".dis");
	for(int vertex = 0; vertex < word_count; vertex++){
		export_file << " " << vertex+1 << "   " << distances[vertex] << std::endl;
	}
	export_file.close();
	std::cout << "File Exported: " << input << ".dis" << std::endl << std::endl;

	// CLEAN UP
	delete [] distances;
	delete graph;

	return 0;
} // main
