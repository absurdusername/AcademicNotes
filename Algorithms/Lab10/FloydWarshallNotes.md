### Floyd-Warshall
AKA floyd's algorithm

#### Representation
- `G[i][j] = 0` if i = j. The distance from every node to itself will now remain 0.

- `G[i][j] = inf` if there is no edge from node i to node j. Use some large integer as `inf`.

- `G[i][j] = some_integer` otherwise


#### Implementation
```python
def floyd(G):
    n = len(G)
    for k in range(n):
        for i in range(n):
            for j in range(n):
                G[i][j] = min(G[i][j], G[i][k] + G[k][j])
```

### Warshall's algorithm
Modification of Floyd-Warshall for transitive closure

#### Representation
- `G[i][j] = 1` if there is an edge from node i to node j (non-trivial)
- `G[i][j] = 0` otherwise

#### Implementation
```python
def warshall(G):
    n = len(G)
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if not G[i][j]:
                    G[i][j] = G[i][k] and G[k][j]
```