#Implementing heap sort
#Assume positive integers being sorted and maximum integer being 9999

class heap:
	def __init__(self):
		self.items = [0]
		self.num = 0
	def findMin(self):
		return self.items[1]
	def deleteMin(self):
		x = self.items[1]
		y = self.items[self.num]
		self.items[1] = -1
		self.increaseKey(1,y)
		return x
	def insert(self,x):
		self.num += 1
		self.items.append(9999)
		reduceKey(self.num, x)		
	def reduceKey(self, i, x):
		c = i
		while c >= 1:

	def increaseKey(self, i, x):
		pass
	def swap(self, i, j):
		temp = self.items[i]
		self.items[i] = self.items[j]
		self.items[j] = temp
	

inputArray = []

f = open('numbers.txt','r')
for line in f:
	number = int(line)
	inputArray.append(number)

