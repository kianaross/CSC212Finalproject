#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

//L-system rules
//F : Move forward
//- : Turn left by some degree
//+: Turn right by some degree

//starter code given in lab
//2 functions in program
std::string koch_snowflake(int order);
void snowflake(int order, std::string &commands);

//main function
int main(int argc, char *argv[]){
    //save to outfile koch.txt
    std::ofstream of("koch.txt");
    //order as command line argument
    int order = std::stoi(argv[1]);
    //write to output, result from snowflake function
    of << koch_snowflake(order);
}

//function to draw all sides of snowflake (3 sides)
std::string koch_snowflake(int order){
    //initialize string to empty
    std::string commands = "";
	// This handles generating the 3 'sides' of the snowflake.
    for(int i = 0; i < 4; i++){
        //call snowflake function with order and commands passed in
        snowflake(order, commands);
        //draw line
        commands.append("F");
        commands += "+ + ";
    }
    //return the final string
    return commands;
}

//snowflake function to draw one side of snowflake
void snowflake(int order, std::string &commands){
    //base case (order 0 draws triangle)
    if(order == 0){
        return;
    }
    //recursion here  each time called with order-1
    else{
        //recursive call
        snowflake(order - 1, commands);
           //draw line
        commands.append("F");
        // add - (left turn)
        commands.append("-");
        //recursive call
        snowflake(order-1, commands);
        //draw line
        commands.append("F");
        // add + (right turn)
        // add + (right turn
        commands.append("+");
        commands.append("+");
        snowflake(order-1, commands);
        //draw line
        commands.append("F");
        //add - (left turn)
        commands.append("-");
        snowflake(order-1, commands);
    }
}
