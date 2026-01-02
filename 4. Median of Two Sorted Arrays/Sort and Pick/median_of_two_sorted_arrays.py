def get_median (array):
	len_array = len(array)
	even_length = (len_array % 2 == 0)
	median = None
	
	if even_length:
		median = (array[(len_array // 2) - 1] + array[len_array // 2]) / 2
	else:
		median = (array[(len_array // 2)])
		
	return median

#def get_combined_list (array_a, array_b):
def get_combined_list (array1, array2):
	#array1 and array2 have to be sorted for this to work
	
	array1.sort()
	array2.sort()
	
	len_array1 = len(array1)
	len_array2 = len(array2)
	
	array1_cursor = 0
	array2_cursor = 0
	
	out = []
	
	while (array1_cursor < len_array1) or (array2_cursor < len_array2):
		element_array1 = None
		element_array2 = None
		appending_element = None
		
		if (array1_cursor < len_array1):
			element_array1 = array1[array1_cursor]
		
		if (array2_cursor < len_array2):
			element_array2 = array2[array2_cursor]
		
		if (element_array1 != None and element_array2 != None):
			if element_array1 < element_array2:
				appending_element = element_array1
				array1_cursor += 1
			else:
				appending_element = element_array2
				array2_cursor += 1
		elif (element_array1 == None):
			appending_element = element_array2
			array2_cursor += 1
		elif (element_array2 == None):
			appending_element = element_array1
			array1_cursor += 1
			
		out.append(appending_element)
	
	return out
	
nums1 = [1,3]
nums2 = [2,4]

num_combined = get_combined_list(nums1, nums2)

print ("This is the handy work of Python.\n\n")
print (get_median(num_combined))
print ("\n\n\n")
