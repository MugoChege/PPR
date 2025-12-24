def remove_by_shifting (element, list)
	count = 0
	len_list = list.length
	
	for i in (len_list - 1).downto(0).to_a
		if (list[i] == element)
			count += 1
			holder = list[i]
			
			for j in i...(len_list - 1)
				list[j] = list[j + 1]
			end
			
			list[len_list - 1] = holder
		end
	end
	
	return count
end

nums = [0,1,2,2,3,0,4,2]
val = 2

#nums = [3,2,2,3]
#val = 3

rem = remove_by_shifting(val, nums)
puts(rem)
puts("\n\n\n\n")

puts(String(nums))
puts(String(nums[0...(nums.length - rem)]))
#puts(nums[:-rem])
