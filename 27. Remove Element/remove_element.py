def remove_by_shifting (element, array):
	count = 0
	len_array = len(array)
	
	for i in range(len_array - 1, -1, -1):
		if (array[i] == element):
			count += 1
			#shift code
			holder = array[i]
			
			for j in range (i, (len_array - 1)):
				array[j] = array[j + 1]
				
			array[len_array - 1] = holder
			
	return count

nums = [0,1,2,2,3,0,4,2]
val = 2

#nums = [3,2,2,3]
#val = 3

rem = remove_by_shifting (val, nums)
print(rem)
print("\n\n\n\n")

print(nums)
print(nums[:-rem])
