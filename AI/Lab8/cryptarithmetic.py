import itertools

class CSP:
    def __init__(self, words, target):
        self.words = words
        self.target = target

        self.variables = set().union(*self.words).union(target)
        self.domains = {v: range(10) for v in self.variables}

        if len(target) > max([len(w) for w in self.words]):
            self.domains[self.target[0]] = (1,)
    
    def is_consistent(self, assignment):
        """Returns True if the assignment is not inconsistent
        Args:
            assignment (dict): maps variable to assigned value
                Unassigned variables may optionally be mapped to None.
        """
        n_assigned_vars = len({var for var in assignment if assignment[var] is not None})
        n_assigned_values = len({val for val in assignment.values() if val is not None})
        if n_assigned_values != n_assigned_vars:
            return False

        reversed_words = [reversed(w) for w in self.words]
        reversed_target = reversed(self.target)

        carry = 0
        for col in itertools.zip_longest(*reversed_words, reversed_target):
            col_values = [assignment.get(letter, None) for letter in col if letter is not None]

            if None in col_values:
                return True
            
            lhs = sum(col_values[:-1]) + carry 
            if col_values[-1] != lhs % 10:
                return False
            
            carry = 1 if lhs >= 10 else 0

        return True
    
def backtracking_search(csp, assignment=dict()):
    """Returns a solution if found, else None
    
    Args:
        csp (CSP): a problem instance
        assignment (dict): variable -> assigned value
    """
    if not assignment:
        assignment = {v: None for v in csp.variables} 

    # pick an unassigned variable, default is None
    var = next((v for v in assignment if assignment[v] is None), None)

    # if there are no unassigned variables left, return solution
    if var is None: 
        return assignment
    
    for value in csp.domains[var]:
        assignment[var] = value
        if csp.is_consistent(assignment): 
            result = backtracking_search(csp, assignment)
            if result is not None:
                return result
        assignment[var] = None # don't miss this

    return None


if __name__ == "__main__":
    n = int(input("How many operand words: "))
    words = [input(f"Word {i + 1}: ") for i in range(n)]
    target = input("Resultant word: ")

    csp = CSP(words, target)
    solution = backtracking_search(csp)
    
    if solution:
        print("Solution: ", solution)
    else:
        print("No solution found")