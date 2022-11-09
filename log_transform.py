from math import log10
with open('mypic.pgm', 'r') as picture:
    element = picture.readlines()

with open('temp.pgm', 'w') as out:
    for i in range(len(element) - 4):
        element[i+4] = str( int(104 * log10(1 + int(element[i+4].replace('\n', ''))))) + '\n'
    out.writelines(element)