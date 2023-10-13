#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
	
    Graph gh;
    gh.addEdge(0, 1);
    gh.addEdge(1, 2);
    gh.addEdge(0, 3);
    gh.addEdge(2, 3);
    
 	cout << gh.isEdge(0, 3) << endl;
 	cout << gh.isEdge(3, 0) << endl;
 	cout << gh.isEdge(1, 3) << endl;
 	
 	cout << gh.isVertex(0) << endl;
 	cout << gh.isVertex(4) << endl;
 	
 	gh.deleteEdge(0, 3);
 	cout << gh.isEdge(0, 3) << endl;
 	
    gh.printGraph();
	
 
    return 0;
}
