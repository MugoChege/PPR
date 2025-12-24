def duplicates_shifting_remove (array):
	counter = 0
	len_array = len(array)
	
	array.sort()
	
	for i in range ((len_array - 1), -1, -1):
		element = array[i]
		unique = True
		
		for j in range (i):
			if element == array[j]:
				unique = False
				break
		
		if (unique == False):
			counter += 1
			holder = array[i]
			
			for j in range (i, (len_array - 1)):
				array[j] = array[j + 1]
				
			array[len_array - 1] = holder
			
	#array_a = array[:-counter].sort()
	#array[:-counter].sort()
	#array_b = array[-counter:].sort()
	#array[-counter:].sort()
	#array = array_a + array_b
	
	return counter

nums = [0,0,1,1,1,2,2,3,3,4]
val = duplicates_shifting_remove(nums)
print (val)
print ("\n\n\n")
print (nums)
print (nums[:-val])
print (nums[-val:])
