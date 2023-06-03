There are a Kid trying to collect the maximum number of coins from a 3*3 grid that has: some cells containing coins (positive cells), some cells containing monsters that steal coins (negative cells), and zero cells do not take or give coins. In each jump, the kid can jump one step up, down, or in any of the four diagonals. The kid starts its journey from the top left cell and ends at the bottom left cell. The kid is forbidden to visit the same cell more than once in its journey. It is required to print the maximum number of coins it can collect in its journey. Note: assume that if our kid has, for example, 5 coins and passed by a cell of value -7, then the total coins so far will be -2 (a negative number not zero) indicating that the two will be taken from him later. Solve the problem using recursive brute force.

Input Format

3 lines, each line represents a row and contains 3 numbers separated by spaces
Constraints

cell values are from -1000 to 1000
Output Format

one line containing the maximum number of coins the kid can collect in its journey
Sample Input 0

5 -1 -6
7 8 -7
6 -9 -8
Sample Output 0

25
Explanation 0

the path: 5 > 7 > -1 > 8 > 6
