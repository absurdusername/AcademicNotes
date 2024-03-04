from csputils import CSP

def is_solvable(csp):
    solution = backtracking_search(csp, dict(), {i for i in range(10)})
    return True if solution else False

def backtracking_search(csp, assignment, available):
    """Returns a solution if found, else None
    
    Args:
        csp (CSP): a problem instance
        assignment (dict): variable -> assigned value
        available (set): unassigned digits
    """
    if not assignment:
        assignment = {v: None for v in csp.variables} 

    # pick an unassigned variable, default is None
    var = next((v for v in assignment if assignment[v] is None), None)

    # if there are no unassigned variables left, return solution
    if var is None: 
        return assignment

    for value in csp.domain[var]:
        if value not in available:
            continue

        assignment[var] = value
        available.remove(value)
        if csp.is_consistent(assignment): 
            result = backtracking_search(csp, assignment, available)
            if result is not None:
                return result
        assignment[var] = None # don't miss this
        available.add(value)

    return None

if __name__ == "__main__":
    word1 = input("Word 1: ").strip()
    word2 = input("Word 2: ").strip()
    target = input("Sum: ").strip()
    csp = CSP(word1, word2, target)
    print(is_solvable(csp))