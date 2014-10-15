"""
	Generates 40 random numbers and writes them
	to a file. No number is repeated.

	~ Created by Elijah Wilson 2014 ~
"""

# used for generating random integers
from random import randint

# open the output file -> "in.data"
f = open("in.data", "w")

# create an empty list
succ = []

# loops through 40 times for generating numbers
for x in xrange(0,40):
	# generate random int between 1111 & 9999
	randNum = randint(1111, 9999)

	# check to see if it was already generated
	if randNum not in succ:
		# put the random number in the list
		succ.append(str(randNum))
	else:
		# while the randNum has already been generated
		# generate a new one
		while randNum in succ:
			randNum = randint(1111, 9999)
		# put the random number in the list
		succ.append(str(randNum))

# loops through 40 times for writing to file
for x in xrange(0,40):
	# makes sure it isn't the last line to be written
	# to write a new line char
	if x != 39:
		f.write(succ[x] + "\n")
	else:
		# if it is the last line to be written
		# don't write a new line char
		f.write(succ[x])

#close the file
f.close()