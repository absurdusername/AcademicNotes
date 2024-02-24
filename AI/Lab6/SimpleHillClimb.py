def hill_climb_racing(f, d=0.025):
    x = 0
    while True:
        x1 = max((x - d, x, x + d), key=f)
        if x1 == x: return x
        x = x1
        
f = lambda x: x - x**2
x_max = hill_climb_racing(f)
print("max value", round(f(x_max), 2), "at x =", round(x_max, 2))