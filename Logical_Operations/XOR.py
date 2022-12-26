with open('panda.pgm', 'r') as picture:
    element1 = picture.readlines()

with open('mypic.pgm', 'r') as picture:
    element2 = picture.readlines()

with open('output-3.pgm', 'w') as out:
    element = ['P2\n','# Made by Arpan\n']
    element.append(element1[2])
    element.append('255\n')
    for i in range(4, len(element1)):
        if int(element1[i].replace('\n', '')) < int(element2[i].replace('\n', '')):
            if int(element2[i].replace('\n', '')) < 128:
                element.append(element1[i])
            elif int(element1[i].replace('\n', '')) >= 128:
                element.append(element1[i])
            else:
                element.append(element2[i])
        else:
            if int(element1[i].replace('\n', '')) < 128:
                element.append(element2[i])
            elif int(element2[i].replace('\n', '')) >= 128:
                element.append(element2[i])
            else:
                element.append(element1[i])

    out.writelines(element)