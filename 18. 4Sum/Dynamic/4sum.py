def sum_of_four (array, target = 0):
	len_array = len(array)
	out = []
	
	
	for a in range (len_array):
		# add code to minimize the sample space
		for b in range (len_array):
			if (b > a):
				for c in range (len_array):
					if (c > b):
						for d in range (len_array):
							if (d > c):
								if (a != b != c != d):
									aa = array[a]
									bb = array[b]
									cc = array[c]
									dd = array[d]
									#if (aa != bb != cc != dd):
									if True:
										#print (str(aa) + "\t" + str(bb) + "\t" + str(cc) + "\t" + str(aa + bb + cc) +  "\t" + str((aa + bb + cc) == target))
										if ((aa + bb + cc + dd) == target):
											#z = [a, b, c, d]
											z = [array[a], array[b], array[c], array[d]]
											#z.sort()
											#if not(z in out):
											out.append(z)
	
	return out
	
nums = [1,0,-1,0,-2,2]
print(sum_of_four(nums))
