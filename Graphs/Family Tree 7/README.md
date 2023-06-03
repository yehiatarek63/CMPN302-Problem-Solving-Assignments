You are given N persons were each person has two parents. You are required to print all persons such that no person appears before any of his ancestors. For some generations we do not know the parents. There are multiple solutions. To get similar solution to the judge, when implementing your algorithm iterate on person 0 first. Use an adjacency list to represent the graph.

Input Format

The first line contains the integer N.
For the next N lines,
Each line represents the parent of one person
First line will contain parents of person with index 0, and last line will contain parents of person with index N-1.
Each line will contain two number representing the indices of the parents. If any parent is unknown a -1 is present
Constraints

1<=N<=10^6
Output Format

One line containing the indices of all people in the order defined by the constraints.
Sample Input 0

9
-1 -1
0 -1
1 3
0 6
-1 -1
-1 -1
-1 5
-1 -1
7 6
Sample Output 0

7 5 6 8 4 0 3 1 2
