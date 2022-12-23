with open('mypic.pgm') as picture: # provide the image path here
    elements = picture.readlines()

elements[3] = elements[3].replace('255', '1')

def bit_plane(pixel, plane):
    for i in range(plane-1):
        pixel = pixel // 2
    return pixel % 2

with open('msbmypic.pgm', 'w') as out: # provide the output file name here
    for i in range(len(elements)-4):
        elements[i+4] = str( bit_plane(int(elements[i+4].replace('\n', '')), 8)) + '\n' # change the second argument of the bit_plane function according to bit plane
    out.writelines(elements)