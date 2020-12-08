# CSC212Finalproject
How to Run Programs

Sierpinski Triangle
(the image/txt file included is for x1-250 y-0 x2-0 y2-500 x3-500 y3-500)

Our code for the Sierpinski Triangle is composed of 4 files.  
The necessary files are those titled sierpinski.cpp, sierpinski.txt, sierpinski.pdf, and python.py.  
To run the code you must first compile sierpinski.cpp program (using the line “g++ sierpinski.cpp –o sierpinski”).  
You will next run the sierpinski program by entering “./sierpinski x1 y1 x2 y2 x3 y3” , 
where the the xs and ys are your points (x and y values) for the equilateral triangles 3 vertices.   
where the # is the order you would like to generate for the fractal.  
This will create a .txt file called sierpinski.txt.  
Then run the python code using the .txt file to generate a pdf with the image of the fractal.  
To do this enter “python3 python.py sierpinski.txt sierpinski.pdf”.  
The drawing will be stored in the sierpinski.pdf file. 


Koch Snowflake
(image/txt file included is for order 4)

Our code for the Koch Snowflake is composed of 4 files.  
The necessary files are those titled koch.cpp, koch.txt, koch.pdf, and l-systemplotter.py.  
In this program we created the image using l-systems.  
To run the code you will first compile the .cpp file using the line “g++ koch.cpp –o koch”.  
Once the code has been compiled, then run the code using the line “./koch #”, 
where the # is the order of the fractal you would like to generate.  
This will create a .txt file called koch.txt.  
To create the image, we will have to use the l-systemplotter.py.  
Enter “python3 l-systemplotter.py koch.txt koch.pdf” and the drawing will be stored in the koch.pdf file.

Hilbert Curve (same as snowflake, but hilbert instead of koch)
(image/txt file is for order 4)

Our code for the Hilbert Curve is composed of 4 files.  
The necessary files are those titled hilbert.cpp, hilbert.txt, hilbert.pdf, and l-systemplotter.py.  
In this program we created the image using l-systems.  
To run the code you will first compile the .cpp file using the line “g++ hilbert.cpp –o hilbert”.  
Once the code has been compiled, then run the code using the line “./hilbert #”, 
where the # is the order of the fractal you would like to generate.  
This will create a .txt file called hilbert.txt.  
To create the image, we will have to use the l-systemplotter.py.  
Enter “python3 l-systemplotter.py hilbert.txt hilbert.pdf” and the drawing will be stored in the hilbert.pdf file.
