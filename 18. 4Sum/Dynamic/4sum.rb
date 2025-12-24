def not_equal_list(list)
	len_list = list.length()
	out = true
	
	for i in 0...len_list
		for j in i...len_list
			if (i != j)
				if (list[i] == list[j])
					out = false
				end
			end
		end
	end
	
	return out
end

def sum_of_four (list, target = 0)
	len_list = list.length()
	out = []
	
	for a in 0...len_list
		for b in 0...len_list
			if (b > a)
				for c in 0...len_list
					if (c > b)
						for d in 0...len_list
							if (d > c)
								if (not_equal_list([a, b, c, d]))
									aa = list[a]
									bb = list[b]
									cc = list[c]
									dd = list[d]
									
									#if (not_equal_list([aa, bb, cc, dd]))
									if (true)
										if ((aa + bb + cc + dd) == target)
											#z = [a, b, c, d]
											z = [list[a], list[b], list[c], list[d]]
											
											out << z
										end
									end
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

nums = [1,0,-1,0,-2,2]
puts (String(sum_of_four(nums)))
