# Define the size of the chessboard (N x N)
N = 4

# Function to print the solution board where queens are placed
def print_solution(board):
    for i in range(N):
        for j in range(N):
            print(board[i][j], end=" ")
        print()
    print()

# Function to check if it's safe to place a queen at board[row][col]
def is_safe(board, row, col):
    # Check the left side of the current row
    for i in range(col):
        if board[row][i]:
            return False

    # Check the upper diagonal on the left side
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j]:
            return False

    # Check the lower diagonal on the left side
    for i, j in zip(range(row, N, 1), range(col, -1, -1)):
        if board[i][j]:
            return False

    # If no conflicts, it's safe to place the queen
    return True

# Utility function to solve the N-Queens problem recursively
def solve_nq_util(board, col):
    # If all queens are placed successfully, return True
    if col >= N:
        return True

    # Try placing a queen in each row of the current column
    for i in range(N):
        # Check if it's safe to place the queen at board[i][col]
        if is_safe(board, i, col):
            # Place the queen at board[i][col]
            board[i][col] = 1

            # Recur to place the rest of the queens
            if solve_nq_util(board, col + 1):
                return True

            # If placing queen at board[i][col] doesn't lead to a solution,
            # backtrack by removing the queen from board[i][col]
            board[i][col] = 0

    # If the queen can't be placed in any row in this column, return False
    return False

# Main function to solve the N-Queens problem
def solve_nq():
    # Initialize an empty N x N board
    board = [[0] * N for _ in range(N)]

    # Start the recursive utility function from the first column
    if not solve_nq_util(board, 0):
        print("Solution does not exist")
        return False

    # Print the solution if one exists
    print_solution(board)
    return True

# Driver code to run the program
if __name__ == "__main__":
    solve_nq()
