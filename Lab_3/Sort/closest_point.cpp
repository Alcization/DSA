#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Point{
   public:
   int x, y;
   Point(int x = 0, int y = 0){
      this->x = x;
      this->y = y;
   }
   void display(){
      cout << "("<<x<<", "<<y<<")";
   }
};

/* Your helping functions go here */
float distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}
void closestKPoints(Point points[], int n, Point &des_point, int k){
   //TODO
   vector<pair<float, int> > des;
   for (int i = 0; i < n; i++) {
      des.push_back(make_pair(distance(points[i].x, points[i].y, des_point.x, des_point.y), i));
   }
   sort(des.begin(), des.end());
   for (int i = 0; i < k && i < n; i++) {
      points[des[i].second].display();
      cout << endl; 
   }
}
