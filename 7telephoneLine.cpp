#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int from;
    int to;
    int cost;
};

vector<Edge> edges;
vector<vector<int>> graph;

const int INF = 1e9;

void addEdge(int from, int to, int cost) {
    Edge e = {from, to, cost};
    edges.push_back(e);
    graph[from][to] = cost;
    graph[to][from] = cost; // assuming undirected graph
}

void displayConnections() {
    cout << "Connections:" << endl;
    for (const auto& e : edges) {
        cout << "Office " << e.from << " -> Office " << e.to << " : Cost = " << e.cost << endl;
    }
}

int main() {
    int numOffices;
    cout << "Enter the number of offices: ";
    cin >> numOffices;

    graph.resize(numOffices, vector<int>(numOffices, INF));

    int choice;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add a connected edge" << endl;
        cout << "2. Display connections" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int from, to, cost;
                cout << "Enter the offices to connect (from, to, cost): ";
                cin >> from >> to >> cost;
                addEdge(from, to, cost);
                break;
            }
            case 2:
                displayConnections();
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice. Try again!" << endl;
        }
    }

    return 0;
}