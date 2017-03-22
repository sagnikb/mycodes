'''age = 20
name = 'Sagnik'

print('{0} was {1} years old when he saw this book'.format(name, age))
print('why is {0} playing with that python?'.format(name))

print ('why is {name} playing with that python?'.format(name = name))
print(r"newlines are indicated by \n")

print(age)
age = age*2
print(age)
'''

def printList (mylist):
	for items in mylist:
		print(items, end=' ')
	print('\n')
shoplist = ['apple', 'mango', 'carrot', 'banana']
print('I have', len(shoplist), 'items to purchase')
print('these items are:', end=' ')
printList(shoplist)
shoplist.append('rice')
printList(shoplist)
shoplist.sort()
printList(shoplist)
del shoplist[0]
printList(shoplist)
shoplist.remove('banana')
printList(shoplist)

