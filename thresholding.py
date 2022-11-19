with open('panda.pgm', 'r') as picture:
    element = picture.readlines()

with open('temp.pgm', 'w') as out:
    for i in range(len(element) - 4):
        if int(element[i+4].replace('\n', '')) > 130: # you can give any threshold value here
            element[i+4] = '255\n'
        else:
            element[i+4] = '0\n'
    out.writelines(element)