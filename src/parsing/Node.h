#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node{
    private:
        int id;
        float x;
        float y;
    public:
        int getId();
        float getX();
        float getY();
        Node(int, float, float);
};

#endif