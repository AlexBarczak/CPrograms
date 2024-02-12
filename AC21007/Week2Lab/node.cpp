#include "node.h"

namespace search_infrastructure{

    template <class DataStructure, typename Action>
    Node<DataStructure, Action>::Node(DataStructure state)
    {
        this.state = state;
        this.parent = NULL;
        this.action = NULL;
        this.pathCost = 0; 
    }

    template <class DataStructure, typename Action>
    Node<DataStructure, Action> ChildNode(Problem<DataStructure, Action> problem, Node<DataStructure, Action> parent, Action action){
        Node<DataStructure, Action> childNode = new Node<DataStructure, Action>();
        childNode.state = Problem.Result(parent.state, action);
        childNode.parent = parent;
        childNode.action = action;
        childNode.pathCost = parent.pathCost + problem.StepCost(parent.state, action); 
    }

}