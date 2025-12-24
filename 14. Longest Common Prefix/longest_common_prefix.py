def longest_common_prefix (array):
	out = ""
	shortest_word = 0
	for a in range(len(array)):
		if (a == 0):
			shortest_word = len (array[a])
		
		if ((0 - len(array[a])) > (-1 * shortest_word)):
			shortest_word = len(array[a])
	
	
	for e in range(shortest_word):
		letter = ""
		common = True
		for a in range(len(array)):
			if (a == 0):
				letter = array[a][e]
			else:
				if letter != array[a][e]:
					#make sure it is not appended
					common = False
					break
				
		if common:
			out += letter
			common = True
			
	return out
	
strs = ["flower","flow","flight"]
print(longest_common_prefix(strs))
