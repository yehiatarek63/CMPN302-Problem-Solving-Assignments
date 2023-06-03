You are playing a video game, you have one ship to defend against N enemy ships. Each enemy ship has it's own initial health. You have M different types of weapons on your ship, each of which have it's own firepower. Your objective is to provide the minimum number of shots that would minimize each enemy’s health (0) without making it negative using dynamic programming.

Input Format

An integer N representing the number of enemy ships in the game.
The next line will contain N numbers representing the initial health for each enemy ship.
The following line is an integer M representing the number of weapons available.
The following line contain M numbers representing the firepower for each weapon.
Constraints

N is between 1 and 10^5
Health is between 0 and 10^4
M is between 1 and 10^3
Firepower of each weapon is between 0 and 10^3
Output Format

N lines (line for each enemy ship) where each line consists of two numbers
Final enemy ship health
Minimum number of shots required
Sample Input 0

5
43 39 12 26 16
3
9 8 7
Sample Output 0

0 5
0 5
3 1
0 3
0 2
