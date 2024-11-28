def tsp(graph, v, n, current_pos, cost, count, ans):
    # Base case: if all cities are visited and there's a path back to the starting city
    if count == n and graph[current_pos][0] > 0:
        # Update the minimum cost (answer) if the current path is cheaper
        ans = min(ans, cost + graph[current_pos][0])
        return ans
    
    # Try all possible cities as next cities to visit
    for i in range(n):
        # If the city hasn't been visited and there is an edge to it from current city
        if not v[i] and graph[current_pos][i] > 0:
            # Mark the city as visited
            v[i] = True



            # Recur with the next city, updated cost, and incremented count of visited cities
            ans = tsp(graph, v, n, i, cost + graph[current_pos][i], count + 1, ans)

            # Backtrack: unmark the city to allow for other possible paths
            v[i] = False
    
    # Return the minimum cost found
    return ans

def main():
    # Number of cities
    n = 4

    # Distance matrix (graph) where graph[i][j] represents the distance from city i to city j
    graph = [
        [0, 10, 15, 20],
        [10, 0, 35, 25],
        [15, 35, 0, 30],
        [20, 25, 30, 0]
    ]

    # Visited array to track visited cities, initially all set to False
    v = [False] * n

    # Initialize answer with infinity, representing the minimum cost path
    ans = float('inf')

    # Starting from the first city (0), mark it as visited
    v[0] = True

    # Call the tsp function starting from city 0 with initial cost 0 and 1 city visited
    ans = tsp(graph, v, n, 0, 0, 1, ans)

    # Print the minimum cost of visiting all cities and returning to the starting city
    print(ans)

if __name__ == "__main__":
    main()
