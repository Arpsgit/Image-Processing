import numpy as np

with open('mypic.pgm', 'r') as picture:
	element = picture.readlines()

row= int(element[2].split()[1])
col= int(element[2].split()[0])
noise_matrix = np.random.randint(low=0,high=20, size= row*col)

with open('noise.pgm', 'w') as out:
	for i in range(len(element) - 4):
		if noise_matrix[i] == 0:
			element[i+4] = '0\n'
		elif noise_matrix[i] == 19:
			element[i+4] = '255\n'
	out.writelines(element)