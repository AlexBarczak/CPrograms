#ifndef SEARCH_INFRASTRUCTURE_PROBLEM_H
#define SEARCH_INFRASTRUCTURE_PROBLEM_H

#include "node.h"

namespace search_infrastructure {
    
    template<typename DataStructure, typename Action>
    class Problem
    {
    private:
        Node<DataStructure, Action> initialState;
    public:
        Problem(/* args */);
        ~Problem();
        Node<DataStructure, Action> Result(Node<DataStructure, Action> state, Action action);
        bool GoalTest(Node<DataStructure, Action> state);
        int StepCost(Node<DataStructure, Action>, Action action);
    };

    template<typename DataStructure, typename Action>
    Problem<DataStructure, Action>::Problem(/* args */)
    {
    }
    
    template<typename DataStructure, typename Action>
    Problem<DataStructure, Action>::~Problem()
    {
    }

}

#endif