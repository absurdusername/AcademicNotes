class Constraint:
    """
    Attributes:
        scope (list): list of variables involved
        condition (Callable): a boolean function on the scope variables.
    """
    def __init__(self, scope, condition):
        self.scope = scope
        self.condition = condition

    def holds(self, assignment):
        """Returns True if constraint holds for given assignment
        Variables in constraint scope must be initialized.
        """
        return self.condition(*tuple(assignment[v] for v in self.scope))
        

class CSP:
    """A CSP problem instance

    Attributes:
        domains (dict): variable -> domain (iterable)
        constraints (list): list of all constraints

        variables (set): set of all variables
        var_to_const (dict): variable -> set of applicable constraints
    """
    def __init__(self, domains, constraints):
        self.domains = domains
        self.constraints = constraints

        self.variables = set(domains)
        self.var_to_const = {var: set() for var in self.variables}
        for const in constraints:
            for var in const.scope:
                self.var_to_const[var].add(const)
    
    def consistent(self, assignment):
        """Returns True if all applicable constraints are satisfied by the 
            assignment

        Args:
            assignment (dict): variable -> value
        """
        return all(
            const.holds(assignment)
            for const in self.constraints
            if all(v in assignment for v in const.scope)
        )
    
    @classmethod
    def from_words(word1, word2, target):
        """Create and return a CSP instance
        Represents the problem word1 + word2 = target
        """
        pass