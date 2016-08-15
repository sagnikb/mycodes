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
		self.num = self.num - 1;
		self.increaseKey(1,y)
		return x
	def insert(self,x):
		self.num += 1
		self.items.append(9999)
		self.reduceKey(self.num, x)		
	def reduceKey(self, i, x):
		while (i >= 1):
			p = i/2
			if(self.items[p]>self.items[i]):
				swap(i, p)
				i = p
	def increaseKey(self, i, x):
		while (2*i <= self.num):
			if(2*i+1 <= self.num):
				if((self.items[i] > self.items[2*i])or(self.items[i] > self.items[2*i+1])):
					if(self.items[2*i]<self.items[2*i+1]):
						swap(i,2*i)
						i = 2*i
					else:
						swap(i,2*i+1)
						i = 2*i+1
			else:
				if(self.items[i] > self.items[2*i]):
					swap(i, 2*i)
					i = 2*i	
	def swap(self, i, j):
		temp = self.items[i]
		self.items[i] = self.items[j]
		self.items[j] = temp
	
heap1 = heap()

f = open('numbers.txt','r')
for line in f:
	number = int(line)
	#inputArray.append(number)
	heap1.insert(number)

while(heap.num != 1):
	print(heap1.deleteMin())
