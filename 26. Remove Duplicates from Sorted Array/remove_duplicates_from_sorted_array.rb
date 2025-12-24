def duplicates_shifting_remove (list)
	counter = 0
	len_list = list.length
	
	list.sort();
	
	for i in (len_list - 1).downto(0)
		element = list[i]
		unique = true
		
		for j in 0...i
			if element == list[j]
				unique = false
				break
			end
		end
		
		if (unique == false)
			counter += 1
			holder = list[i]
			
			for j in i...(len_list - 1)
				list[j] = list[j + 1]
			end
			
			list[len_list - 1] = holder
		end
	end
	
	#puts(String(list))
	
	return counter
end

nums = [0,0,1,1,1,2,2,3,3,4]
val = duplicates_shifting_remove(nums)

puts("This is the handy work of Ruby.\n\n");
puts(val)
puts("\n\n\n")

puts(String(nums))
puts(String(nums[0...(nums.length - val)]))
puts("\n\n\n")
