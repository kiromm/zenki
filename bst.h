/// bst.h
/// Medina, Fred
/// fmedina8
#ifndef BST_H_
#define BST_H_
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class BST{
private:
    class Node{
    public:
        ~Node();
        string data;
        Node *left;
        Node *right;
    };
    Node *root;
    int listCount;
    bool insert(string str, Node *&curr_root);
    bool find(string str, Node *&curr_root);
    void print_dft(vector<string> &value, Node *&curr_root);
    void print_breadth(vector<string> &value, Node *&curr_root);
    double distance(double dist, Node *&curr_root);
    int levels(Node *&curr_root);
    int balanced(Node *&curr_root);
//    bool balanced(Node *&curr_root); // Works
    void del_tree(Node *&curr_root);
    void insert_from_vector(vector<string> &value, int startIndex, int endIndex);

public:
    BST();
    ~BST();
//    void echo( string ); // Use if printing string in echo function
    string echo( string ); // Use if returning string
    bool insert(string str);
    int size();
    bool find(string str);
    void print_dft(vector<string> &value);
    void print_breadth(vector<string> &value);
    double distance();
    int balanced();
//    bool balanced(); // Works
    void rebalance(); // Same as line below, but defined and declared
//    void rebalance() {return rebalance(root); } // Declared and defined


};

void print_t(vector<string> &value);

#endif // BST_H_

/// Input/Output
// done in main.cpp
// BST functions returns and/or use reference parameters
// Use vector when passing multiple strings

/// No argument
// <command><newline>
/// With argument
// <command><space><string may contain spaces><newline>

/////////////////////////////////
/// Error Messages
///******************************
// If illegal command entered, print to std error
/// "Illegal command <cmd>.\n"
// After illegal command entered, skill all other
// characters on that line of input and continue program

// if insert is called on a string that is already in tree
// print to std error
/// "insert <str> failed. String already in tree.\n";

/////////////////////////////////
/// Commands from standard input
///******************************
/// Command, Argument, Error, Action

/// echo, string, none
// Write string to std output. Do not insert into tree.
// Used for commenting tests. Has nothing to do with tree

/// insert, string, print "error" if exist in tree
// Insert string into tree. Tree must maintain the BST
// property after insert

/// size, none, none ('0' if tree is empty)
// Print number of elements & number of nodes in the tree

/// find, string, none
// Print if the string is in or is not in the tree
// to stdout (both messages)

/// print, none, none (empty brackets if tree is empty)
// Use a depth-first traversal (dft) to print all
// elements in the tree

/// breadth, none, none (empty brackets if tree is empty)
// Use a breadth-first traversal (bft) to print all
// elements in the tree

/// distance, none, none ('0' if zero or one nodes)
// Print the average distance nodes are from the root
// Root's distance is 0.
// Root's children are distance == 1,
// Root's grandchildren are distance == 2 and so on...
// Calculate distance for ALL nodes and then take
// the average

/// balanced, none, none (balanced if empty)
// Print if the tree is balanced or not balanced.
// This type of balanced is called "height-balance"

/// rebalance, none, none
// Modify the tree so it's balanced


/////////////////////////////////
/// Output Formatting
///******************************
/// Command, output formatting
/// echo
// Print string argument to std output
// followed by newline

/// insert
// None unless there is an error

/// size
// Print the integer size of the tree to std output
// followed by a newline

/// find
// if target string is in tree, print to std output
// "<str> is in tree.\n"
// if NOT in tree, print to std output
// "<str> is not in tree.\n"

/// print
// Traverse the tree using a depth-first algorithm.
// Print all elements in {}, separate strings by
// a comma and space and terminate with a newline
/// {string one, string two, string three}
// There is no comma after the last string
/// "{}\n" if the tree is empty
// No space between the brackets

/// breadth
// Same format as print
// Helpful to use vector printing fn and use it for
// both print and breadth commands

/// distance
// Print
/// "Average distance of nodes to root = "
// followed by the average (double) of all the node's
// distances from root followed by a new line

/// balanced
// If the tree is balanced, print to std output
/// "Tree is balanced.\n";
// If not balanced, print to std output
/// "Tree is not balanced.\n";

/// rebalance
// none
