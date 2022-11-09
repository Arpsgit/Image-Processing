with open('panda.pgm', 'r') as picture:
    element = picture.readlines()

with open('temp.pgm', 'w') as out:
    out.writelines(element)