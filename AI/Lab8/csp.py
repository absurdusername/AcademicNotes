from csputils import CSP

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
    csp = CSP("SEND", "MORE", "MONEY")
    solution = backtracking_search(csp, dict(), {i for i in range(10)})
    print(solution)