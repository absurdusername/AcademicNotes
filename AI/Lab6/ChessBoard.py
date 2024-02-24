from random import shuffle, randint
import os

class ChessBoard:
    """A configuration of the chess board
    
    Attributes:
        config (list): Stores the positions of the Queens. If config[i] = j 
            then the Queen in the ith row is placed in the jth column.
    """

    def __init__(self, config=None):
        """Create a ChessBoard
        
        Args:
            config (list): The config attribute. If not specified, the board
                is set to a default configuration.
        """
        if not config:
            config = [randint(0, N - 1) for i in range(N)] # place the Queens arbitrarily
        self.config = config.copy()

    def __str__(self):
        """Return a string representing the chess board

        Enables print to be used with ChessBoard instances.
        """
        result = "-" * N * 3 + "\n"
        for row in range(N):
            for col in range(N):
                result += " Q " if self.config[row] == col else " . "
            result += "\n"
        result += "-" * N * 3
        result += f"\tcost = {self.cost()}" 
        return result

    def cost(self) -> int:
        """Return the number of attacking pairs"""
        cost = 0
        
        for row in range(N):
            col = self.config[row]

            # same column
            cost += self.config[row + 1:].count(col)

            # same diagonal
            for delta in range(1, N - row):
                if self.config[row + delta] in (col + delta, col - delta):
                    cost += 1

        return cost
    
    def neighbors(self, i=0) -> list:
        """Return a list of all neighboring chess boards"""
        result = []

        for i in range(N):
            neighbor_config = self.config.copy()

            for j in range(N):
                if j != self.config[i]:
                    neighbor_config[i] = j
                    result.append(ChessBoard(neighbor_config))

        shuffle(result) # PREVENTS INFINITE RECURSION MOST OF THE TIME
        return result 
    
    def __hash__(self):
        return sum([self.config[i] * N**i for i in range(N)])
    
    def __eq__(self, other):
        return self.config == other.config
    

def hill_climb_racing(initial_state: ChessBoard) -> ChessBoard:
    print(initial_state)
    current = initial_state
    
    while current.cost() != 0:
        current = min(current.neighbors(), key=lambda x: x.cost())
        os.system("clear")
        print(current)

    return current

if __name__ == "__main__":
    # size of the board (N x N)
    N = int(input("N: "))

    initial_state = ChessBoard() 
    solution = hill_climb_racing(initial_state)
    os.system("clear")
    print(solution)