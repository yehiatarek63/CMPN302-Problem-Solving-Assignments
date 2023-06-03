You are playing a game as a wizard, who is currently staying in your home city. You have the ability to teleport to other cities using hidden portals. Each portal consumes a certain amount of health. There can be multiple portals between two cities in the same direction. Your goal is to find the minimum amount of health needed to reach the furthest city and the number of reachable cities. Given N cities and M portals, find the number of reachable cities and the minimum amount of health required to visit the furthest city. You are starting in city with index S. Use an adjacency list to represent the graph.

Input Format

One line containing N, M, S separated by spaces
For the next M lines, each line will contain 3 numbers representing the portal
Start city index
End city index
Amount of health needed for the teleport
Constraints

1<=N<=5000
1<=M<=10^5
0<=S<=N-1
1<=Wi<=1000
Where Wi is the amount of health needed for each portal.
Output Format

One line containing the number of reachable cities, and the minimum amount of health needed to reach the furthest city
Sample Input 0

5 10 0
0 1 10
0 2 5
1 2 2
1 3 1
2 1 3
2 4 2
3 4 4
2 3 9
4 0 7
4 3 6
Sample Output 0

5 9
