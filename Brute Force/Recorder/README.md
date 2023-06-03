You are given a recorder that can record up to M minutes maximum, and you have S songs you can record. You are required to choose some songs from S to record such that the total recorded time is as much as possible and does not exceed M. You cannot record the same song more than once. Use recursive brute force to solve this problem.

Input Format

one line contains the following integers space separated: M (maximum total minutes), S (number of songs to choose from), and then S integers representing the duration of each song.
Constraints

1 <= S <= 20
1 <= M <= 1000
1 <= any song duration <= M
Output Format

one integer representing the total recorded time that is as much as possible and does not exceed M
Sample Input 0

10 4 9 8 4 2
Sample Output 0

10
Sample Input 1

20 4 10 5 7 4
Sample Output 1

19
Explanation 1

Choose to record songs with duration 10+5+4 = 19 the maximum possible that does not exceed 20.
