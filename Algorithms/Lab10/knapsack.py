
def knapsack(capacity: int, W: list[int], V: list[int]):
    N = len(W) # number of objects
    DP = [[0] * (capacity+1) for i in range(N+1)] # (N+1) x (capacity+1) matrix

    for i in range(1, N+1):
        w, v = W[i-1], V[i-1]

        for z in range(1, capacity+1):
            # consider not including the item
            DP[i][z] = DP[i-1][z]

            # consider including the item
            if z >= w:
                DP[i][z] = max(DP[i-1][z-w] + v, DP[i][z])

    # return DP[N][capacity]
    
    z = capacity 
    selected_items = []
    for i in range(N, 0, -1):
        if DP[i][z] != DP[i-1][z]:
            item_index = i - 1
            selected_items.append(item_index)
            z -= W[item_index]

    return selected_items


if __name__ == "__main__":
    W = [3, 1, 3, 4, 2]
    V = [2, 2, 4, 5, 3]
    print(knapsack(7, W, V))