#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
//make number key for color

//write the instructions to a text file, pass the text file to the python script and use the line in the lab to run the python script

//draw a triangle using these points
void drawtriangle(int x1, int y1, int x2, int y2, std::vector<int> &vertexpoints, int order){
    //store these next points into vertexpoints vector, by accessing the indexes directly we are overwriting the previous call's data with this call's
    vertexpoints[0] = x1;
    vertexpoints[1] = y1;
    vertexpoints[2] = x2;
    vertexpoints[3] = y2;
    vertexpoints[4] = order;


}

void triangle( int x1, int y1, int x2, int y2, int x3, int y3, std::vector<int> vertexpoints, std::vector<std::vector<int>> &lines , int order){
	//create four index's in vertexpoints so that they may be addressed directly in the drawtriangle function
    vertexpoints.push_back(0);
    vertexpoints.push_back(0);
    vertexpoints.push_back(0);
    vertexpoints.push_back(0);
    vertexpoints.push_back(0);

	/* Base case. */
	if(abs(x2-x1) < 10 ){
	    return;
	}

	/* Drawing step. */
	//pass in the x and y values for each line into the drawtriangle function, then push each completed line (stored in the vertexpoints vector)
	//into the vector of vectors "lines" - each row in "lines" will be a completed set of instructions for one line to be produced off of
	drawtriangle(x1, y1, x2, y2, vertexpoints, order); // pass in order so the correct order number or "color" num will be passed for this level
	lines.push_back(vertexpoints);
	drawtriangle(x1, y1, x3, y3, vertexpoints, order);
	lines.push_back(vertexpoints);
	drawtriangle(x2, y2, x3, y3, vertexpoints, order);
	lines.push_back(vertexpoints);

	/* Recursive step. */
	//call recursively with the new vertex points

	triangle(x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2, vertexpoints, lines, (order + 1)); //increment order with each call so the appropriate order val will exist so

	triangle((x1+x3)/2,(y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3, vertexpoints, lines, (order + 1));

	triangle((x1+x2)/2,(y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2, vertexpoints, lines, (order + 1));
}


int main(int argc, char *argv[]){
	//enter vertex points for original triangle, will be an x and a y coordinate for all 3 and will be passed in by user
    int x1 = std::stoi(argv[1]);
    int y1 = std::stoi(argv[2]);
    int x2= std::stoi(argv[3]);
    int y2 =std::stoi(argv[4]);
    int x3 = std::stoi(argv[5]);
    int y3 = std::stoi(argv[6]);
    //create initial vector
    std::vector<int> vertexpoints = {};
    //create the multidimensional vector to hold all of the coordinates of where lines will draw
    //each row of lines will be a set of 4 numbers (an x and a y for each point) coorisponding to
    //the coordinates the lines will be produced off of, as well as a number for color val used in coloring the fractal by order

    //pass it by reference so it can be continuously added to
    std::vector<std::vector<int>> lines;
        //create an order varaible starting at 0 that will be incrimented as the recursion calls in the traingle function
        int order = 0;
    //call triangle function
    triangle(x1, y1, x2, y2, x3, y3, vertexpoints, lines, order);

	//writing to an outfile
	std::ofstream myfile;
    myfile.open("sier.txt");
    if (myfile.is_open())
    {
        //push on the vector backwards so that the inner step lines do not print over the outer ones, protecting the order the colors should be layed down
        for(int index1 = lines.size() - 1; index1 >= 0; index1 --){
            for(int index2 = 0; index2 < lines[0].size(); index2++){
                myfile << lines[index1][index2];
                myfile << " ";
            }
            myfile << "\n";
        }
        myfile.close();
  }

}
