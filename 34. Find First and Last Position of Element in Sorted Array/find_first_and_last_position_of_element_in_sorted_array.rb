def first_and_last (element, list)
	find_first = true
	out = [-1,-1]
	list = list.sort()
	
	for i in 0...list.length
		e = list[i]
		
		if (e == element)
			if (find_first)
				out[0] = i
				out[1] = i
				find_first = false
			else
				out[1] = i
			end
		end
	end
	
	return out
end

nums = [5,7,7,8,8,10,2]
target = 8

puts(String(first_and_last(target, nums)))
