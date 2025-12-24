def first_and_last (element, array):
	find_first = True
	
	out = [-1,-1]
	array.sort()
	
	for i in range(len(array)):
		e = array[i]
		if (e == element):
			if (find_first):
				out[0] = i
				out[1] = i
				find_first = False
			else:
				out[1] = i
				
	return out

nums = [5,7,7,8,8,10,2]
target = 8

print(first_and_last(target, nums))
