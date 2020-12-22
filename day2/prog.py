inp = open("input.txt", "r")

lines = inp.readlines()


valid = 0
valid1 = 0


for line in lines:
    line = line.strip()
    line = line.replace('-', ' ').replace(':', '')
    inputs = line.split(' ')

    count = inputs[3].count(inputs[2])

    if count >= int(inputs[0]) and count <= int(inputs[1]):
        valid += 1

    if (inputs[3][int(inputs[0]) - 1] == inputs[2]) != (inputs[3][int(inputs[1]) - 1] == inputs[2]):
        valid1 += 1


print(valid)
print(valid1)
