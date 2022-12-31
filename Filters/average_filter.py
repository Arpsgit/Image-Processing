import numpy as np

input_image = input("File name: ") # enter the name of the image file without extension and that png file should be in the same folder
with open(f'{input_image}.pgm', 'r') as picture:
    element = picture.readlines()

def avg_filter(pixel, start, filter_size):
    new_pixel = np.zeros((pixel.shape[0],pixel.shape[1]))
    for i in range(start, pixel.shape[0]-start):
        for j in range(start, pixel.shape[1]-start):
            new_pixel[i][j] = int(pixel[i-start:i+filter_size-start, j-start:j+filter_size-start].mean())

    return new_pixel

filter_size = int(input("Enter the filter size: "))
row = int(element[2].replace('\n', '').split()[1])
col = int(element[2].replace('\n', '').split()[0])
pixel = np.zeros((row + filter_size - 1, col + filter_size - 1))
a = 4
start = (filter_size - 1)//2
for i in range(start, pixel.shape[0]-start):
    for j in range(start, pixel.shape[1]-start):
        pixel[i][j] = int(element[a].replace('\n', ''))
        a += 1

new_pixel = avg_filter(pixel, start, filter_size)
b = 4
for i in range(start, new_pixel.shape[0]-start):
        for j in range(start, new_pixel.shape[1]-start):
            element[b] = str(int(new_pixel[i][j]))+'\n'
            b += 1
name = input("Save file as: ")
with open(f'{name}.pgm', 'w') as out:
    out.writelines(element)


