from Lab6.ChessBoard import ChessBoard
from copy import deepcopy


class ExtendedChessBoard(ChessBoard):
    def __init__(self, n=8):
        super().__init__(n=n)

    def is_safe(self, f):
        """Return True if the queen on file `f` is safe from left side"""
        rank = self.config[f]

        # same rank
        if rank in self.config[:f]:
            return False

        # same diagonal
        for delta in range(1, f + 1):
            if self.config[f - delta] in (rank + delta, rank - delta):
                return False

        return True

    def solutions(self, f=0):
        """Return solutions by modifying the board file `c` onwards"""
        if f == self.n:
            return [deepcopy(self)]

        result = []
        for i in range(self.n):
            self.config[f] = i
            if self.is_safe(f):
                result.extend(self.solutions(f + 1))
        return result


if __name__ == "__main__":
    solutions = ExtendedChessBoard().solutions()
    for solution in solutions:
        print(solution)
    print(len(solutions))