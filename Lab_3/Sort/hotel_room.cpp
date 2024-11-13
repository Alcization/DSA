#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maxNumberOfPeople(vector<int>& rooms, vector<int>& people, int k) 
{
    sort(rooms.begin(), rooms.end());
    sort(people.begin(), people.end());
    int maxPeople = 0;
    int i = 0; // Pointer for rooms
    int j = 0; // Pointer for people
    while (i < rooms.size() && j < people.size()) 
    {
        int roomSize = rooms[i];
        int desiredSize = people[j];
        if (abs(roomSize - desiredSize) <= k) 
        {
            maxPeople++;
            i++; 
            j++; 
        } 
        else if (roomSize < desiredSize) i++;
        else j++;
    }
    return maxPeople;
}

