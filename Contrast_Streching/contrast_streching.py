with open('low_contrast_image.pgm', 'r') as picture:
    element = picture.readlines()

pixel = []
for i in range(len(element) - 4):
    pixel.append(int(element[i+4].replace('\n', '')))

max_pixel = max(pixel)
min_pixel = min(pixel)

with open('high_contrast_image.pgm', 'w') as out:
    for i in range(len(element) - 4):
        element[i+4] = str(round(((pixel[i] - min_pixel)/(max_pixel - min_pixel)*255), 0)) + '\n'
    out.writelines(element)