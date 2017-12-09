/// main.cpp
/// Medina, Fred
/// fmedina8
#include"bst.h"
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

/// Function Prototype
int switch_choice(string);


int main(){
    string command, argument, line, echoed;
    bool inTree;
//    bool bal; // Use if returning bool in balanced fn
    int choice;
    BST bst;
    vector<string> dft;
    double avg;
    while( getline( cin, line ) )
    {
        istringstream ss( line );
        getline( ss, command, ' ');
        getline( ss, argument );

        // Returns switch case
        choice = switch_choice(command);
        switch(choice){
            /// ECHO - Print's comments
            ////////////////
            case 0:{
//                bst.echo(argument); // Use if echo function is void
                cout << bst.echo(argument) << endl; // Use if echo function is string
                break;
            } // -echo

            /// INSERT - Insert into tree
            ////////////////
            case 1:{
//                cout << "Getting the bool..\n";
                inTree = bst.insert(argument);
//                cout << "The bool is: " << inTree << endl;
                if(inTree){ // if true, string exists in tree
                    cerr << "insert <" << argument
                         << "> failed. String already "
                         << "in tree.\n";
                } // -if true
                break;
            } // -insert

            /// SIZE - Returns node count
            ////////////////
            case 2:{
                cout << bst.size() << endl;
                break;
            } // -size

            /// FIND - Find string in tree
            ////////////////
            case 3:{
                inTree=bst.find(argument);
                if(inTree){ // if true, string exists in tree
                    cout << "<" << argument << ">"
                         << " is in tree.\n";
                }
                else{ // false, not in tree
                    cout << "<" << argument << ">"
                         << " is not in tree.\n";
                }
                break;
            } // -find

            /// PRINT - Print in Depth Traversal (In Order)
            ////////////////
            case 4:{
                bst.print_dft(dft); // Passing vector to fn
                break;
            } // -print

            /// BREADTH - Print in Breadth Traversal (Level Order)
            ////////////////
            case 5:{
                bst.print_breadth(dft); // Passing vector to fn
                break;
            } // -breadth

            /// DISTANCE - Distance of nodes from root
            ////////////////
            case 6:{
                avg = bst.distance();
                cout << "Average distance of nodes to root = "
                     << avg;
                cout << endl;
                break;
            } // -distance

            /// BALANCED - Is tree balanced?
            ////////////////
            case 7:{
                /// FOR INT BALANCED
                /////////////////////
                // This block works
//                cout << "Test Returned: " << bst.balanced() << endl;
                if(bst.balanced() == -1){
                    cout << "Tree is not balanced.\n";
                }
                else{
                    cout << "Tree is balanced.\n";
                }
                /// ^ FOR INT BALANCED
                /////////////////////

                /*****************************************/

                /// FOR BOOL BALANCED
                /////////////////////
                // This block works
//                bal = bst.balanced();
//                cout << "Test Returned: " << bal << endl;
//                if(bal)
//                    cout << "Tree is balanced.\n";
//                else{
//                    cout << "Tree is not balanced.\n";
//                }
                ///  ^ FOR BOOL BALANCED
                /////////////////////
                break;

            } // -balanced

            /// REBALANCE - Rebalance tree
            ////////////////
            case 8:{
                bst.rebalance();

                break;
            } // -rebalance
            case 9:{
                cerr << "Illegal command <" << command
                     << ">.\n";
                break;
            }
        } // -switch
    } // -while( std::getline( cin, line ) )
    return 0;
} // -main

/// DECIDES WHICH SWITCH CASE
///*************************************
int switch_choice( string command ){
    int choice;
        if(command=="echo"){
            choice=0;
        }
        else if(command=="insert"){
            choice=1;
        }
        else if(command=="size"){
            choice=2;
        }
        else if(command=="find"){
            choice=3;
        }
        else if(command=="print"){
            choice=4;
        }
        else if(command=="breadth"){
            choice=5;
        }
        else if(command=="distance"){
            choice=6;
        }
        else if(command=="balanced"){
            choice=7;
        }
        else if(command=="rebalance"){
            choice=8;
        }
        /// Illegal command
        else{
            choice = 9;
        }
    return choice;

} // -switch_choice



