def get_target (nums, target)
	len_nums = nums.length()
	out = nil
	
	for a in 0...len_nums
		exit_loop = false
		for b in 0...len_nums
			if (b == a)
				next
			elsif
				if ((nums[a] + nums[b]) == target)
					out = [a,b]
					exit_loop = true
					break
				end
			end
		end
		if (exit_loop)
			break
		end
	end
	
	return out
end

number_list = [1,2,3,4,5,6,7,8,9]
target = 16

indices = get_target(number_list, target)
puts(String(indices))
puts("\n")

if (indices.class() == Array)
	puts(number_list[indices[0]])
	puts(number_list[indices[1]])
end
