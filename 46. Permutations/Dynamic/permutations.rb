def number_from_list (list)
	out = 0
	len_list = list.length()
	base = 10
	
	for i in 0...len_list
		out += (list[i] * (base ** (len_list - 1 - i)))
	end
	
	return out
end

def number_to_array (number, original_list_len = 0)
	out = []
	base = 10
	running_number = number
	
	while running_number > 0
		modulo = running_number % base
		running_number -= modulo
		running_number /= base
		out << (modulo)
	end
	
	if original_list_len != 0
		while (out.length < original_list_len)
			out << 0
		end
	end
	
	out = out.reverse()
	
	return out
end

def list_comparison (list1, list2)
	out = false
	len_list1 = list1.length
	len_list2 = list2.length
	
	if (len_list1 != len_list2)
		return out
	end
	
	list1_bool_map = []
	list2_bool_map = []
	
	for i in 0...len_list1
		list1_bool_map << false
		list2_bool_map << false
	end
	
	for i in 0...len_list1
		for j in 0...len_list2
			if (list1_bool_map[i] == false) and (list2_bool_map[j] == false)
				if (list1[i] == list2[j])
					list1_bool_map[i] = true
					list2_bool_map[j] = true
					break
				end
			end
		end
	end
	
	bool_counter = 0
	for i in 0...len_list1
		if (list1_bool_map[i] and list2_bool_map[i])
			bool_counter += 1
		end
	end
	
	return (list1_bool_map.length == bool_counter)
end

def appears (element, list)
	out = -1
	
	for i in 0...list.length
		if (element == list[i])
			out += 1
		end
	end
	
	return out
end

nums = [1,2,3]
len_nums = nums.length
nums = nums.sort()
lowest_value_nums_number = number_from_list(nums)
nums = nums.reverse()
highest_value_nums_number = number_from_list(nums)

puts(lowest_value_nums_number)
puts(highest_value_nums_number)

permutations = []

running_number = lowest_value_nums_number

while (running_number <= highest_value_nums_number)
	temp_nums_list = number_to_array(running_number, len_nums)
	if (list_comparison(temp_nums_list, nums))
		permutations << temp_nums_list
	end
	
	running_number += 1
end

puts(String(permutations))
