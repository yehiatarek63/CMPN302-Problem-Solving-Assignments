A book shelf containing N consecutive books (B1, B2, .., BN) is given. Each book contains a number of pages. Count the number of book collections of size M books (M is either 2 or 3) such that the difference of pages between each two consecutive books in these collections is D. Note that the order of books in any book collection are the same as the original book collection (e.g., collection B5-B1 is not allowed, because B1 is before B5 in the original collection, but B1-B5 is allowed). Use hash tables to implement your solution. Hints: (i) use unordered_map, and (ii) handle only the two possible M values (2 or 3).

Input Format

One line containing the number of books N, the difference D, and the required number of books per collection M
One line containing the number of pages in each book (B1, B2, ... until BN), space separated
Constraints

N is between 3 and 10^7.
D is between 1 and 1000
M is either 2 or 3.
the number of pages in each book is between 1 and 100000
Output Format

The number of book collections of size M books that satisfy the condition
Sample Input 0

5 4 3
2 2 6 10 10
Sample Output 0

4
Sample Input 1

6 2 2
2 3 3 5 9 7
Sample Output 1

3
