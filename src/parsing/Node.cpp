#include "Node.h"

Node::Node(int id, float x, float y){
    this->id = id;
    this->x = x;
    this->y = y;
}

int Node::getId(){
    return this->id;
}

float Node::getX(){
    return this->x;
}

float Node::getY(){
    return this->y;
}