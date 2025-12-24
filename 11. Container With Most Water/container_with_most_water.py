def absolute (number):
	return (number * -1) if (number < 0) else (number * 1)
	
def get_volume (height1, height2, width):
	height = (height1) if (height1 < height2) else (height2);
	
	return height * width

def container_points (array):
	len_array = len(array)
	largest_volume = 0
	volume_indexes = []
	
	for a in range(len_array):
		for b in range (len_array - 1, 0, -1):
			#print(str(a) + "\t\t" + str(b) + "\t|\t" + str(array[a]) + "\t" + str(array[b]))
			if (a == b):
				#no volume
				continue
			elif (b < a):
				break
			else:
				#smaller_element = array[a] if (array[a] < array[b]) else array[b]
				interval = absolute(a - b)
				#volume = smaller_element * interval
				volume = get_volume (array[a], array[b], interval)
				
				if (largest_volume < volume):
					largest_volume = volume
					volume_indexes = [a,b]
	
	return volume_indexes
	
height_array = [1,8,6,2,5,4,8,3,7]
height_indices = container_points(height_array)
height1 = height_array[height_indices[0]]
height2 = height_array[height_indices[1]]
interval = absolute(height_indices[0] - height_indices[1]);

print("This is the handy work of Python\n\n");
print(height_indices);
print("The heights given the points are: " + str(height1) + " on one end and " + str(height2) + " on the other end. The difference between the two points is " + str(interval) + " giving a total volume of " + str (get_volume(height1, height2, interval)))


