def get_median (array):
	len_array = len(array)
	even_length = (len_array % 2 == 0)
	median = None
	
	if even_length:
		median = (array[(len_array // 2) - 1] + array[len_array // 2]) / 2
	else:
		median = (array[(len_array // 2)])
		
	return median

def get_combined_list (array_a, array_b):
	# it would be faster to concatenate the two arrays
	# then sort them then get the median
	# the more code is for translation to differnt languages
	a = array_a.copy()
	b = array_b.copy()
	a.sort()
	b.sort()
	
	len_a = len(a)
	len_b = len(b)
	shorter_array = len_a if (len_a < len_b) else len_b
	longer_array = len_a if (len_a > len_b) else len_b
	
	merged = []
	
	merged = a + b
	merged.sort()
	
	return merged
	
nums1 = [1,3]
nums2 = [2,4]

num_combined = get_combined_list(nums1, nums2)
print(num_combined);
print (get_median(num_combined));
