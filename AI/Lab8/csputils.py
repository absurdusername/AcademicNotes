import itertools

class CSP:
    """A CSP problem instance

    Attributes:
        variables (set): set of all variables
        domain (dict): variable -> domain (iterable)

        word1 (str): first word
        word2 (str): second word
        target (str): word1 + word2 := target defines the problem
    """
    def __init__(self, word1, word2, target):
        self.word1 = word1
        self.word2 = word2
        self.target = target

        self.variables = set(word1).union(word2).union(target)
        self.domain = {v: range(10) for v in self.variables}

        if len(target) > max(len(word1), len(word2)):
            self.domain[target[0]] = (1,)
    
    def is_consistent(self, assignment):
        """Returns True if the assignment is not inconsistent so far

        Args:
            assignment (dict): variable -> value
        """
        a = reversed(self.word1)
        b = reversed(self.word2)
        t = reversed(self.target)

        carry = 0
        for x, y, z in itertools.zip_longest(a, b, t):
            vx, vy, vz = assignment[x], assignment[y], assignment[z]
            if None in (vx, vy, vz):
                return True
            if vz != (vx + vy + carry) % 10:
                return False
            carry = 1 if (vx + vy + carry) >= 10 else 0
        return True
