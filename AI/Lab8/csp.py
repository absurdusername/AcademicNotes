def domain(var):
    if var == "B":
        return (1,)
    return (i for i in range(10))

def is_consistent(assignment):
    A = assignment["A"]
    B = assignment["B"]
    C = assignment["C"]

    if None in (A, B, C):
        return True
    if A == 6 and B == 1 and C == 2:
        return True
    return False

def backtracking_search(assignment):
    """Returns a solution if found, else None
    
    Args:
        assignment (dict): variable -> assigned value or None.
    """

    # pick an unassigned variable, default is None
    var = next((v for v in assignment if assignment[v] is None), None)

    # if there are no unassigned variables left, return solution
    if var is None: 
        return assignment

    for value in domain(var):
        assignment[var] = value
        if is_consistent(assignment): 
            result = backtracking_search(assignment)
            if result is not None:
                return result
        assignment[var] = None # don't miss this

    return None

if __name__ == "__main__":
    variables = {"A", "B", "C"}
    d = {v: None for v in variables}

    solution = backtracking_search(d)
    print(solution)
    is_consistent(solution)