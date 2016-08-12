from __future__ import print_function
print("hello world")
#this is a comment
age = 20
name = "sagnik"
#(^) to 11 width 'hello'
print('{0:_^11}'.format('hello'))
#formatting string outputs
print("{0} is {1} years old.".format(name, age))
#to stop newline from being printed at the end
print('a', end='')
print('b')
for i in range(1,9,1):
	print(i)
	if i%2:
		print("Number is odd")
	else:
		print("Number is even")
def returnMax(x,y):
	if x > y:
		return x
	elif x == y:
		return -1
	else:
		return y

print(returnMax(3,7))
