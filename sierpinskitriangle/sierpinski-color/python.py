from PIL import Image, ImageDraw, ImageColor
import numpy as np
import sys

#create a pallet array of colors, this will be used to access different colors to print in depending on the order or step in recursion
colorarray = ["red", "salmon", "blue", "green", "purple", "orange", "white", "turquoise", "tan", "plum"] # Yes salmon is a valid color, if you want to see a full list search X11 color names, 
                                                                              #the software engineers had fun

# load data
fname = sys.argv[1]
mat = np.loadtxt(fname, dtype=int)
# create an image in memory
img = Image.new("RGB", (1000,1000), (255,255,255))
draw = ImageDraw.Draw(img)
# iterate all rows in the matrix
for i in range(mat.shape[0]):
    # draw the line by specifying the x and y coordinates as well as what color to color the line (found in the colorarray)
    #mat is housing the x and y of two points as well as the coorisponding "order" number
    draw.line([(mat[i][0],mat[i][1]), (mat[i][2],mat[i][3])], fill = colorarray[mat[i][4]] ) #fill = colorarray[mat[i][4]]
    # save file
    img.save(fname + '.pdf')

#No color cababilites
# load data
#fname = sys.argv[1]
#mat = np.loadtxt(fname, dtype=int)
# create an image in memory
#img = Image.new('L', size=(1000,1000),color=255)
#draw = ImageDraw.Draw(img)
# iterate all rows in the matrix
#for i in range(mat.shape[0]):
    # draw the line
    #draw.line([(mat[i][0],mat[i][1]), (mat[i][2],mat[i][3])], fill = 128) #fill = colorarray[mat[i][4]]
    #draw.line([(mat[i][0],mat[i][1]), (mat[i][2],mat[i][3])], fill=0)
    # save file
    #img.save(fname + '.pdf')
