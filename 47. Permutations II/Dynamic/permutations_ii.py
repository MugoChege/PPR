def number_from_array (array):
	out = 0
	len_array = len(array)
	base = 10
	
	for i in range(len_array):
		out += (array[i] * (base ** (len_array - 1 - i)))
		
	return out
	
def number_to_array (number, original_array_len = 0):
	out = []
	base = 10
	running_number = number
	
	while running_number > 0:
		modulo = running_number % base
		running_number -= modulo
		running_number //= base
		out.append (modulo)
		
	#code that adds the zeros
	
	if original_array_len != 0:
		while len(out) < original_array_len:
			out.append(0)
			
	out.reverse()
	
	return out
	
def array_comparison (array1, array2):
	#compares if two arrays have similar values with facilitation for repeat characters
	out = False
	len_array1 = len(array1)
	len_array2 = len(array2)
	
	if (len_array1 != len_array2):
		return out
	
	array1_bool_map = []
	array2_bool_map = []
	for i in range(len_array1):
		array1_bool_map.append(False)
		array2_bool_map.append(False)
	
	for i in range(len_array1):
		for j in range (len_array1):
			if (array1_bool_map[i] == False) and (array2_bool_map[j] == False):
				if (array1[i] == array2[j]):
					array1_bool_map[i] = True
					array2_bool_map[j] = True
					break
				
	#sum of the array_bool_map
	bool_counter = 0
	for i in range (len_array1):
		if array1_bool_map[i] and array2_bool_map[i]:
			bool_counter += 1
			
	return (len(array1_bool_map) == bool_counter)
	
#def repeat_elements:
def appears (element, array):
	out = -1
	
	for i in range (len(array)):
		if (element == array[i]):
			out += 1
			
	return out
	
nums = [1,2,3]
len_nums = len(nums)
nums.sort()
low_value_nums_number = number_from_array(nums)
nums.reverse()
high_value_nums_number = number_from_array(nums)

print(low_value_nums_number)
print(high_value_nums_number)

permutations = []
running_number = low_value_nums_number

while running_number <= high_value_nums_number:
	temp_nums_array = number_to_array(running_number, len_nums)
	if (array_comparison(temp_nums_array, nums)):
		permutations.append(temp_nums_array)
		
	running_number += 1

print (permutations)
