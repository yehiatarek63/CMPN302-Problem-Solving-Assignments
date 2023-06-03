Anna wants to buy a list of items from the supermarket, such as milk, juice, eggs, etc. For each item type, there are many alternatives to choose from (e.g., many types of milks, etc.). She has a specific budget B. You are required to help her to buy 1 alternative from each item type such that she does not exceed the budget and, at the same time, maximize the total money she spent from the budget (i.e., the maximum total money less than or equal the budget to buy 1 alternative of each item type). If there is no way to buy 1 alternative from each item type using the given budget, then "no solution" should be printed. Use a dp solution, otherwise a manual penalty will be applied.

Hint: your dp table could be 2D representing: the remaining budget & the index of the item type. Imagine the recursive tree and how many branches are going out of each node such that each level represents the alternatives of one item type.

Input Format

the first line contains 2 integers: B (the budget) and T (the number of item types)
In the next T lines, each line represents one type and contains: N (the number of alternatives of this item type), then N integers representing the price of each alternative.
Constraints

1 <= B <= 200
1 <= T <= 20
1 <= N <= 20
1 <= any price <= B
Output Format

one integer representing the maximum total amount of money that is below or equal the budget and buys 1 alternative from each item type.
if no solution is found, "no solution" is printed.
Sample Input 0

20 3
3 4 6 8
2 5 10
4 1 5 5 3
Sample Output 0

19
Explanation 0

from item type 1: choose price 8
from item type 2: choose price 10
from item type 3: choose price 1
(total = 19)
Note: there is no unique solution from that problem (for example: (6+10+3) and (4+10+5) are also optimal and sum = 19)
Sample Input 1

5 3
3 6 4 8
2 10 6
4 7 3 1 7
Sample Output 1

no solution
