#queue implementation of bucket sort in python

class Queue:
	def __init__(self):
		self.items = []
	def isEmpty(self):
		return self.items == []
	def size(self):
		return len(self.items)
	def enqueue(self, item):
		self.items.insert(0, item)
	def dequeue(self):
		return self.items.pop()

limit = 500001
limit = int(limit)
array = []

for num in range(1,limit+1):
	array.append(Queue())

f = open('number.txt', 'r')
for line in f:
	number = int(line)
	array[number-1].enqueue(number)

for queue in array:
	while (queue.size() != 0):
		print(queue.dequeue())
