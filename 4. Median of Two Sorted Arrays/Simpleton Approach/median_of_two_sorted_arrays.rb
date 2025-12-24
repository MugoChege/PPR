def get_median (list)
	len_list = list.length
	even_length = (len_list % 2 == 0)
	median = 0.0
	
	if (even_length)
		median = (Float(list[len_list / 2]) + Float(list[(len_list / 2) - 1])) / 2
	else
		median = list[len_list / 2]
	end
	
	return (median)
end

def combine_list (list1, list2)
	combined_list = []
	for i in list1
		combined_list << i
	end
	
	for i in list2
		combined_list << i
	end
	
	combined_list = combined_list.sort()
	
	return combined_list
end

list1 = [1,3]
list2 = [2,4]

list_combined = combine_list(list1, list2)

median = get_median(list_combined)

puts (median)
puts ("\n\n\n");
