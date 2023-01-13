from math import pow

name = input("Enter the name of the image file: ")

with open(f'{name}.pgm', 'r') as picture:
    element = picture.readlines()

gamma = float(input("Enter the gamma value: "))
C = float(input("Enter the C value: "))

out_image = input("Enter the name of the output file: ")
with open(f'{out_image}.pgm', 'w') as out:
    for i in range(len(element) - 4):
        pix = int(C * pow(int(element[i+4].replace('\n', '')), gamma))
        if pix > 255:
            element[i+4] = '255\n'
        elif pix < 0:
            element[i+4] = '0\n'
        else:
            element[i+4] = str( int(C * pow(int(element[i+4].replace('\n', '')), gamma))) + '\n'
    out.writelines(element)