
H(leaf_node) = 0

H(null) = -1

BF(node) = H(node.right) - H(node.left)

Rotate the nodes with BF = +/- 2. Start with the nodes closest to the new node, work upwards.
