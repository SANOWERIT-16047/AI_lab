#include <iostream>
#include <queue>
#include <type_traits>
#include <vector>

class GraphSearch
{
    private:
    std::vector<std::vector<int>> m_adjacencyMatrix;

    public:
    /**
     *Setter for Adjacency Matrix
     */
    void setAdjacencyMatrix (std::vector<std::vector<int>>& adjMatrix)
    {
        m_adjacencyMatrix = adjMatrix;
    }

    // print adjMatrix
    void printAdjacencyMatrix ()
    {
        std::cout << "Adjacency Matrix for given graph: \n";
        for (auto it = 1; it < m_adjacencyMatrix.size (); it++)
        {
            std::cout << "row " << it << ":\t";
            for (auto it1 = 1; it1 < m_adjacencyMatrix[it].size (); it1++)
            {
                std::cout << m_adjacencyMatrix[it][it1] << "\t";
            }
            std::cout << "\n";
        }
    }
    // For Undirected graph
    void addEdge (int source, int destination)
    {
        m_adjacencyMatrix[source][destination] = 1;
        m_adjacencyMatrix[destination][source] = 1; // For directed graph comment it
    }
    /**
     *@param start - Select Starting vertex
     *@return void - Print Visited Node/Vertex after traversing
     */
    void bfs (int start)
    {
        std::vector<int> visited (m_adjacencyMatrix.size () + 1, 0); // Initialize all value to false
        std::queue<int> track; // For tracking childerns of visited nodes
        track.push (start);
        visited[start] = 1; // Set start vertex as true or alreadr traversed
        while (!track.empty ())
        {
            int current = track.front ();

            // Print Current Node
            std::cout << "Visited: " << current << "\t ";
            track.pop ();

            // For all adjacent vertex to current vertex traversal
            for (int i = 1; i < m_adjacencyMatrix[current].size (); i++)
            {
                if (m_adjacencyMatrix[current][i] == 1 && (!visited[i]))
                {
                    track.push (i);
                    visited[i] = 1;
                }
            }
        }
    }

    /**
     *@param start - For selecting starting vertex/node for traversal
     *@param visited - Keeping trac of already visited vertex/nodes
     *@return void - printing already traversed nodes using depth first searcch
     */

    void dfs (int start, std::vector<int>& visited)
    {
        // Printing Current Node
        std::cout << " Visited: " << start << "\t";

        visited[start] = 1;

        for (int i = 1; i < m_adjacencyMatrix[start].size (); i++)
        {
            if (m_adjacencyMatrix[start][i] == 1 && !visited[i])
            {
                dfs (i, visited);
            }
        }
    }
};

int main ()
{
    GraphSearch test;
    // adjacency matrix
    std::vector<std::vector<int>> adj =
    std::vector<std::vector<int>> (6, std::vector<int> (6, 0));
    test.setAdjacencyMatrix (adj);
    test.addEdge (1, 2);
    test.addEdge (1, 3);
    test.addEdge (1, 4);
    test.addEdge (3, 4);
    test.addEdge (4, 5);

    test.printAdjacencyMatrix ();
    std::cout << "BFS Traversal: \n";
    test.bfs (1);
    // Visited Matrix - size must be equal to adjacency matrix row
    std::vector<int> vis (6, 0);
    std::cout << "\nDFS Traversal:\n ";
    test.dfs (1, vis);
    return EXIT_SUCCESS;
}