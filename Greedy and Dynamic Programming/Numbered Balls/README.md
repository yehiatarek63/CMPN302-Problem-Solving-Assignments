This is a kids game for learning the mathematical addition. The kids have B unique balls, and each ball has a unique number/value written upon it. We give the kids a total value V, and it is required from them to find the minimum number of balls that can be used to get the total value V. Assume that there is an inifite number of balls of each ball value. If there is no possible way to get that total value from the given balls, print "no solution". Use DP solution to solve this problem. A manual grade penalty will be applied if you did not use a dp solution.

Input Format

one line contains two integers: the total value V then the number of unique balls B (space separated)
another line contains B integers space seperated representing the value written upon each unique ball
Constraints

1 <= V <= 10,000
1 <= B <= 100
1 <= the value written on any ball <= 100
Output Format

one line containing either the minimum number of balls to get the total value V or "no solution" if there is no possible solution
Sample Input 0

25 5
4 5 2 1 9
Sample Output 0

4
Explanation 0

we need minimum 4 balls (1 ball of value 5 + 2 balls of value 9 + 1 ball of value 2) = total value 25
Sample Input 1

9 3
7 6 8
Sample Output 1

no solution
