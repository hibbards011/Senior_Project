/***********************************************************************
* Program:
*   node.h
* Author:
*   Samuel Hibbard
* Summary:
*   This will be the node class that will hold all the pointers to it's
*       inputs with their weights. There is a STRUCT that will
*       hold the input pointer and weight. There is a class called NODE
*       that does exactly what was described in the first sentence.
***********************************************************************/

#ifndef NODE_H
#define NODE_H

#include <vector>

class Node; // Need to declare before LINK so that is can use NODE

/***********************************************************************
* Link
*   This STRUCT holds a pointer to a node with the weight that it is
*       associated with.
***********************************************************************/
struct Link
{
    Link(Node * pointer, double w)
    {
        input = pointer;
        weight = w;
    }

    Node * input;
    double weight;
};

/***********************************************************************
* Node
*   This is the class that will hold all the inputs of weights. This
*       class has an update function that will grab all the inputs
*       and do a summation of all of them and give an output for the
*       other nodes that have the current node as input.
***********************************************************************/
class Node
{
public:
    //
    // Constructors & Destructor
    //
    Node(int i, int t) : inputs(), id(i), type(t), output(0) {}
    ~Node() { deleteLinks(); }

    //
    // Methods
    //
    void update();                            // This feeds forward the inputs
                                              // and sets the output.
    void deleteLinks()                        // This deletes all the inputs.
    {
        inputs.clear(); // This won't worry about deleting the pointers
                        // the class network will take care of that.
                        // Whatever uses this class must delete the node.
                        // pointers so as to not cause a memory leak.
    }

    void addInput(Node * node, float weight)  // This adds a new input for the NODE.
    {
        Link link(node, weight);
        inputs.push_back(link);
    }

    //
    // Getters
    //
    std::vector<Link> getInputs() const { return inputs; }
    int getId()                   const { return id;     }
    int getType()                 const { return type;   }
    double getOutput()            const { return output; }

    //
    // Setter
    //
    void setOutput(double o)            { output = o;    }
private:
    std::vector<Link> inputs; // This holds all the STRUCTs with the
                              // inputs to this node.
    int id;                   // The id of this node.
    int type;                 // What type of node this is. Can be SENSOR,
                              // OUTPUT, or HIDDEN.
    double output;            // This holds the output value.
};

#endif // NODE_H