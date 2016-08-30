import random
f = open('number.txt', 'w')

for i in range(0,1000000):
	num = random.randint(0,500000)
	string = str(num)
	f.write('{}\n'.format(string))
	i = i + 1

