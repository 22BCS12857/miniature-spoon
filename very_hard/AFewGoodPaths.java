package very_hard;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class AFewGoodPaths {

    // Parent array for union-find structure
    private int[] parent;

    // Method to calculate the number of good paths
    public int numberOfGoodPaths(int[] vals, int[][] edges) {
        int n = vals.length;  // Number of vertices
        parent = new int[n];  // Initialize the parent array for union-find

        int[][] valueIndexPairs = new int[n][2];  // Array to hold value and index pairs
        @SuppressWarnings("unchecked")
        List<Integer>[] graph = new List[n];  // Adjacency list for graph representation

        Arrays.setAll(graph, k -> new ArrayList<>());  // Initialize the adjacency list

        // Construct the graph from edges
        for (int[] edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].add(b);
            graph[b].add(a);
        }

        // Map to keep track of component sizes with specific values
        Map<Integer, Map<Integer, Integer>> componentSize = new HashMap<>();

        for (int i = 0; i < n; ++i) {
            parent[i] = i;  // Make each vertex its own parent initially
            valueIndexPairs[i] = new int[] {vals[i], i};  // Create pairs of value and its index
            // Initialize the component size map
            componentSize.computeIfAbsent(i, k -> new HashMap<>()).put(vals[i], 1);
        }

        // Sort the valueIndexPairs based on values
        Arrays.sort(valueIndexPairs, (a, b) -> a[0] - b[0]);

        int ans = n;  // Initialize count of good paths (every vertex is a trivial good path)

        for (var pair : valueIndexPairs) {
            int value = pair[0], vertexIndex = pair[1];

            for (int neighbor : graph[vertexIndex]) {
                // Skip the neighbor vertices that have a greater value
                if (vals[neighbor] > value) {
                    continue;
                }

                // Find the parents of the current vertex and the neighbor
                int setA = find(vertexIndex), setB = find(neighbor);

                if (setA != setB) {
                    // Combine sizes of the components if they have the same vertex value
                    ans += componentSize.get(setA).getOrDefault(value, 0) * componentSize.get(setB).getOrDefault(value, 0);
                    parent[setA] = setB;  // Union the two sets

                    // Merge the size maps after performing the union
                    int sizeSum = componentSize.get(setB).getOrDefault(value, 0) + componentSize.get(setA).getOrDefault(value, 0);
                    componentSize.get(setB).put(value, sizeSum);
                }
            }
        }

        return ans;
    }

    // Find method with path compression for union-find
    private int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression step
        }
        return parent[x];
    }

    // Main function to test the numberOfGoodPaths method
    public static void main(String[] args) {
        AFewGoodPaths solution = new AFewGoodPaths();

        // Example 1: 
        int[] vals1 = {1, 3, 2, 1, 3};
        int[][] edges1 = {{0, 1}, {0, 2}, {2, 3}, {2, 4}};
        System.out.println("Number of good paths (Example 1): " + solution.numberOfGoodPaths(vals1, edges1));

        // Example 2:
        int[] vals2 = {1, 2, 3};
        int[][] edges2 = {{0, 1}, {1, 2}};
        System.out.println("Number of good paths (Example 2): " + solution.numberOfGoodPaths(vals2, edges2));
    }
}
