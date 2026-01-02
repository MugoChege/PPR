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

#def combine_list (list1, list2)
def combine_list (list1, list2)
	list1 = list1.sort()
	list2 = list2.sort()
	
	len_list1 = list1.length
	len_list2 = list2.length
	
	list1_cursor = 0
	list2_cursor = 0
	
	out = []
	
	while ((list1_cursor < len_list1) or (list2_cursor < len_list2))
		element_list1 = nil
		element_list2 = nil
		appending_element = nil
		
		if (list1_cursor < len_list1)
			element_list1 = list1[list1_cursor]
		end
		
		if (list2_cursor < len_list2)
			element_list2 = list2[list2_cursor]
		end
		
		if (element_list1 != nil and element_list2 != nil)
			if (element_list1 < element_list2)
				appending_element = element_list1
				list1_cursor += 1
			else
				appending_element = element_list2
				list2_cursor += 1
			end
		elsif (element_list1 == nil)
			appending_element = element_list2
			list2_cursor += 1
		elsif (element_list2 == nil)
			appending_element = element_list1
			list1_cursor += 1
		end
		
		out << appending_element
	end
	
	return (out)
end

list1 = [1,3]
list2 = [2,4]

list_combined = combine_list(list1, list2)

median = get_median(list_combined)

puts ("This is the handy work of Ruby.\n\n\n");
puts (median)
puts ("\n\n\n");
