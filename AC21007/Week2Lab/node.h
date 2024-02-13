#ifndef SEARCH_INFRASTRUCTURE_NODE_H
#define SEARCH_INFRASTRUCTURE_NODE_H

#include "problem.h"

namespace search_infrastructure {

    template <typename DataStructure, typename Action>
    class Node
    {
    private:
        DataStructure *state;
        Node<DataStructure, Action> *parentNode;
        Action *action;
        int pathCost;
    public:
        Node();
        Node(DataStructure *state);
        ~Node();
    };

    template <class DataStructure, typename Action>
    Node<DataStructure, Action>::Node()
    {
        state = nullptr;
        parentNode = nullptr;
        action = nullptr;
        pathCost = 0;
    }    

    template <class DataStructure, typename Action>
    Node<DataStructure, Action>::~Node()
    {
    }
}

#endif