with open('panda.pgm', 'r') as picture:
    element = picture.readlines()

frequency = {}
pdf = {}
cdf = {}
mapping = {}
for i in range(256):
    frequency[f'{i}'] = 0
    pdf[f'{i}'] = 0
    cdf[f'{i}'] = 0
    mapping[f'{i}'] = 0
    
for i in range(4, len(element)-4):
    frequency[element[i].replace('\n', '')] += 1

for i in range(256):
    pdf[f'{i}'] = round(frequency[f'{i}'] / (len(element)-4), 3)

cdf['0'] = pdf['0']
for i in range(1, 256):
    cdf[f'{i}'] = cdf[f'{i-1}'] + pdf[f'{i}']

for i in range(256):
    mapping[f'{i}'] = round(255 * cdf[f'{i}'])

with open('temp.pgm', 'w') as out:
    for i in range(4, len(element)-4):
        element[i] = str(mapping[element[i].replace('\n', '')]) + '\n'
    out.writelines(element)