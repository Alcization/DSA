#include <bits/stdc++.h>
using namespace std;
class Point
{
private:
    double x, y;

public:
    Point()
    {
        this->x = 0;
        this->y = 0;
    }

    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    void setX(double x)
    {
        this->x = x;
    }

    void setY(double y)
    {
        this->y = y;
    }

    double getX() const
    {
        return x;
    }

    double getY() const
    {
        return y;
    }

    double distanceToPoint(const Point& pointA)
    {
        int length = pointA.x - this->x;
        int height = pointA.y - this->y;
        length = abs(length);
        height = abs(height);
        double result;
        result = sqrt(pow(length, 2) + pow(height, 2));
        return result;
    }
};

class Circle
{
private:
    Point center;
    double radius;

public:
    Circle()
    {
        center = Point(0, 0);
        this->radius = 0;
    }

    Circle(Point center, double radius)
    {
        this->radius = radius;
        this->center = center;
    }

    Circle(const Circle &circle)
    {
        this->center = circle.center;
        this->radius = circle.radius;
    }
    
    void setCenter(Point point)
    {
        this->center = point;
     }

    void setRadius(double radius)
    {
        this->radius = radius;
    }

    Point getCenter() const
    {
        return center;
    }

    double getRadius() const
    {
        return radius;
    }
    
    void printCircle()
    {
        printf("Center: {%.2f, %.2f} and Radius %.2f\n", this->center.getX(), this->center.getY(), this->radius);
    }
};

