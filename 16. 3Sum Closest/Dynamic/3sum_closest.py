def sum_of_the_result(array):
	out = 0
	
	for i in array:
		for j in i:
			out += j
	
	return out

def sum_of_three_closest (array, target = 0):
	len_array = len(array)
	out = []
	closest = None
	
	
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
							#if (aa != bb) and (aa != cc) and (bb != cc): #toggle this for no similar value elements
							if True:
								#print (str(aa) + "\t" + str(bb) + "\t" + str(cc) + "\t" + str((aa + bb + cc)) +  "\t" + str(abs((aa + bb + cc) - target)) + "\t" + str(abs(0 - (abs((aa + bb + cc) - target)))))
								throw = abs((aa + bb + cc) - target)
								if (closest == None):
									closest = throw
								#print(closest)
								
								if (throw == closest):
									#z = [a, b, c]
									z = [array[a], array[b], array[c]]
									out.append(z)
									#z.sort()
									#if not(z in out):
									#	out.append(z)
								elif (throw < closest):
									out = []
									#z = [a, b, c]
									z = [array[a], array[b], array[c]]
									out.append(z)
									closest = throw
	
	return out
	
nums = [-1,2,1,-4]

closest = sum_of_three_closest(nums, 1)
print(closest)
print(sum_of_the_result(closest))
