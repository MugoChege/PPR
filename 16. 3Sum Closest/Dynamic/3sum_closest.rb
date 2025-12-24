def absolute_value(number)
	return (number < 0) ? (number * -1) : (number * 1)
end

def sum_of_the_result(list)
	out = 0
	
	list.each do |i|
		i.each do |j|
			out += j
		end
	end
	
	return out
end

def sum_of_three_closest (list, target = 0)
	len_list = list.length
	out = []
	closest = nil
	
	for a in 0...len_list
		for b in 0...len_list
			if (b > a)
				for c in 0...len_list
					if (c > b)
						if (a != b) and (a != c) and (b != c)
							aa = list[a]
							bb = list[b]
							cc = list[c]
							##if (aa != bb) and (aa != cc) and (bb != cc) #Toggle this for no similarr value elements
							if true
								difference = absolute_value((aa + bb + cc) - target)
								if closest == nil
									closest = difference
								end
								
								if (difference == closest)
									#z = [a, b, c]
									z = [list[a], list[b], list[c]]
									out << z
								elsif (difference < closest)
									out = []
									#z = [a, b, c]
									z = [list[a], list[b], list[c]]
									out << z
									closest = difference
								end
							end
						end
					end
				end
			end
		end
	end
	
	return out
end

nums = [-1,2,1,-4]

closest = sum_of_three_closest(nums, 1)

puts(String(closest))
puts(sum_of_the_result(closest))
