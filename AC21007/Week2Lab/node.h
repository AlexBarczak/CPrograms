#ifndef SEARCH_INFRASTRUCTURE_NODE_H
#define SEARCH_INFRASTRUCTURE_NODE_H

#include "problem.h"

namespace search_infrastructure {


    template <typename DataStructure, typename Action>
    class Node
    {
    private:
        DataStructure state;
        Node<DataStructure> parentNode;
        Action action;
        int pathCost;
    public:
        static Node();
        static Node(DataStructure state);
        static ~Node();
    };

    template <class DataStructure, typename Action>
    Node<DataStructure, Action>::Node()
    {
    }    

    template <class DataStructure, typename Action>
    Node<DataStructure, Action>::~Node()
    {
    }
}

#endif