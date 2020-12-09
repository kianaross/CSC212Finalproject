from PIL import Image, ImageDraw
import numpy as np
import sys
# load data
fname = sys.argv[1]
mat = np.loadtxt(fname, dtype=int)
# create an image in memory
img = Image.new('L', size=(1000,1000),color=255)
draw = ImageDraw.Draw(img)
# iterate all rows in the matrix
for i in range(mat.shape[0]):
    # draw the line
    draw.line([(mat[i][0],mat[i][1]), (mat[i][2],mat[i][3])], fill=0)
    # save file
    img.save(fname + '.pdf')
