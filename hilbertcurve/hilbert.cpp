#include <iostream>
#include <vector>
#include <string>
#include <fstream>

//L-systems rules
//F : Move forward
//- : Turn left by some degree
//+: Turn right by some degree

//have 3 functions in program
void astring(int order, std::string &commands);
void bstring(int order, std::string &commands);
std::string hilbertcurve(int order);

//main function
int main(int argc, char *argv[]){
    //write to outfile titled hilbert.txt
    std::ofstream of("hilbert.txt");
    //order as command line argument
    int order = std::stoi(argv[1]);
    //call hilbertcurve function and write result to txt file
    of << hilbertcurve(order);

}

//hilbert curve function.  Will need 2 strings
//A->"+BF-AFA-FB"
//B-> "-AF+BFB+FA-"
//We will always return A, but will use recursion to substitute in appropriate strings
std::string hilbertcurve(int order){
    //create an empty string to store commands
    std::string commands = "";
    //add right turn
    commands.append("+");
    //call bstring to get B
    bstring(order, commands);
    //draw line
    commands.append("F");
    //add left turn
    commands.append("-");
    //call astring to get A
    astring(order, commands);
    //draw line
    commands.append("F");
    //call astring to get A
    astring(order, commands);
    //left turn
    commands.append("-");
    //draw line
    commands.append("F");
    //call bstring to get B
    bstring(order, commands);
    //add right turn
    commands.append("+");

    //return the string of commands
    return commands;
}

//Function to find A
void astring(int order, std::string &commands){
    //base case
    if(order == 1){
        return;
    }

    //recursive call for order>1
    else{
        //right turn
        commands.append("+");
        //call bstring to get B
        bstring(order-1, commands);
        //draw line
        commands.append("F");
        //left turn
        commands.append("-");
        //call astring to get A
        astring(order-1, commands);
        //draw line
        commands.append("F");
        //call astring to get A
        astring(order-1, commands);
        //left turn
        commands.append("-");
        //draw line
        commands.append("F");
        //call bstring to get B
        bstring(order-1, commands);
        //right turn
        commands.append("+");
    }
}

//Function to find B
void bstring(int order, std::string &commands){
    //base case
    if(order == 1){
        return;
    }

    //recursive calls when order>1
    else{
        //left turn
        commands.append("-");
        //call astring to get A
        astring(order-1, commands);
        //draw line
        commands.append("F");
        //right turn
        commands.append("+");
        //call bstring to get B
        bstring(order-1, commands);
        //draw line
        commands.append("F");
        //call bstring to get B
        bstring(order-1, commands);
        //right turn
        commands.append("+");
        //draw line
        commands.append("F");
        //call astring to get A
        astring(order-1, commands);
        //left turn
        commands.append("-");
    }
}
