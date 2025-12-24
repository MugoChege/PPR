def sum_of_three(list, target = 0)
	len_list = list.length()
	out = []
	
	for a in 0...len_list
		for b in 0...len_list
			if (b > a)
				for c in 0...len_list
					if(c > b)
						if (a != b) and (a != c) and (b != c)
							aa = list[a]
							bb = list[b]
							cc = list[c]
							if (aa != bb) and (aa != cc) and (bb != cc)
								if ((aa + bb + cc) == target)
									#z = [a, b, c]
									z = [list[a], list[b], list[c]]
									out << z
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

nums = [-1,0,1,2,-1,-4]

puts(String(sum_of_three(nums)))
