import sys

def floyds_algorithm(a):
    
    
    # k represents the intermediate vertex through which the paths are checked
    for k in range(0, 4):
        # i represents the source vertex
        for i in range(0, 4):
            # j represents the destination vertex
            for j in range(0, 4):
                # Update the distance from vertex i to vertex j by considering if the path
                # through vertex k is shorter than the current known distance.
                a[i][j] = min(a[i][j], a[i][k] + a[k][j])
    
    # Print the final shortest path matrix
    print("Shortest path matrix:")
    for i in range(0, 4):
        print("\n")
        for j in range(0, 4):
            # Print the shortest distance from vertex i to vertex j
            print(a[i][j], end="\t")

# Initialize the adjacency matrix for the graph
a = [ 
    [ 0, 3, sys.maxsize, 7 ],       # Distances from vertex 0 to others
    [ 8, 0, 2, sys.maxsize ],       # Distances from vertex 1 to others
    [ 5, sys.maxsize, 0, 1 ],       # Distances from vertex 2 to others
    [ 2, sys.maxsize, sys.maxsize, 0 ]  # Distances from vertex 3 to others
]

# Execute Floyd-Warshall algorithm to compute shortest paths
floyds_algorithm(a)
