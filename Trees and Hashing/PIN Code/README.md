A PIN code is hidden in a binary tree. The PIN code is the concatenation of sums of selected levels of the tree. The selected levels start at level 0 (root level) and continues down the tree by K steps every time. For a tree with 9 levels, if K=3, the selected levels will be 0, 3, 6. K is the minimum value of the Lth level % the tree height. L is the value of the root % the tree height. You are allowed to use unordered_map and unordered_set if needed. If K is 0, set to 1 instead.

Input Format

The first line will contain the number of nodes in the tree N.
The following N numbers will contain the data in each node.
The next line will contain the number of edges in the tree E.
The following E lines will contain 3 values:
L or R to represent if this is a left or right child
Index of the parent.
Index of the child.
Constraints

N is between 1 and 10^6
Node 0 is always the root
Root is in level 0
Node values are between 1 and 10^4
Output Format

The concatenation of the sums in one line.
