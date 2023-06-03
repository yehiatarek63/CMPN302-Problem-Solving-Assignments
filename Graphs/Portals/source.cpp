#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void Portals(vector<vector<pair<int,int>>> adjList, int s, vector<int>& distances, vector<bool>& visited_cities)
{
    while (visited_cities[s] == false)
    {
        for (int i = 0; i < adjList[s].size(); i++)
        {
            int toCity = adjList[s][i].first;
            int health = adjList[s][i].second;
            int newHealth = distances[s] + health;
            if (distances[toCity] > newHealth)
                distances[toCity] = newHealth;
        }
        visited_cities[s] = true;
        int minHealth = INT32_MAX;
        for (int i = 0; i < distances.size(); i++)
        {
            if (visited_cities[i] == true)
                continue;

            if (distances[i] < minHealth)
            {
                minHealth = distances[i];
                s = i;
            }
        }
    }
    //Portals(adjList, s, distances, visited_cities);
    return;
}

int main()
{
    int N;
    int M = 0;
    int S;
    cin >> N;
    cin >> M;
    cin >> S;
    vector<vector <pair<int, int>>> adjacency_list(N);
    for (int i = 0; i < M; i++)
    {
        int startCityIndex, endCityIndex, health;
        cin >> startCityIndex;
        cin >> endCityIndex;
        cin >> health;

        adjacency_list[startCityIndex].push_back(make_pair(endCityIndex, health));
    }

    vector<int> distances(N);
    for (int i = 0; i < distances.size(); i++)
    {
        distances[i] = INT32_MAX;
    }
    distances[S] = 0;
    vector<bool> visited_cities(N);
    for (int i = 0; i < N; i++)
    {
        visited_cities[i] = false;
    }
    Portals(adjacency_list, S, distances,visited_cities);
   
    int reachable_cities = 0;
    for (int i = 0; i < visited_cities.size(); i++)
    {
        if (visited_cities[i] == true)
            reachable_cities++;
    }
    //get max of distances
    int maxHealth = 0;
    for (int i = 0; i < distances.size(); i++)
    {
        if (distances[i] > maxHealth && distances[i] != INT32_MAX)
            maxHealth = distances[i];
    }
    cout << reachable_cities<< " " << maxHealth << endl;
    return 0;

}
