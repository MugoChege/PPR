def sum_of_three (array, target = 0):
	len_array = len(array)
	out = []
	
	
	for a in range (len_array):
		# add code to minimize the sample space
		for b in range (len_array):
			if (b > a):
				for c in range (len_array):
					if (c > b):
						if (a != b) and (a != c) and (b != c):
							aa = array[a]
							bb = array[b]
							cc = array[c]
							if (aa != bb) and (aa != cc) and (bb != cc):
								#print (str(aa) + "\t" + str(bb) + "\t" + str(cc) + "\t" + str(aa + bb + cc) +  "\t" + str((aa + bb + cc) == target))
								if ((aa + bb + cc) == target):
									z = [array[a], array[b], array[c]]
									#z = [a, b, c]
									#z.sort()
									#if not(z in out):
									out.append(z)
	
	return out
	
nums = [-1,0,1,2,-1,-4]

print(sum_of_three(nums))
