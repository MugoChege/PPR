def absolute(number)
	return (number < 0) ? (number * -1) : (number * 1)
end

def get_volume(height1, height2, width)
	height = (height1 < height2) ? (height1) : (height2)
	
	return (height * width)
end

def container_points(list)
	len_list = list.length;
	largest_volume = 0
	volume_indexes = []
	
	for a in 0...len_list
		for b in (len_list - 1).downto(1).to_a
			if (a == b)
				next
			elsif (b < a)
				break
			else
				interval = absolute(a -b)
				volume = get_volume(list[a], list[b], interval)
				
				if (largest_volume < volume)
					largest_volume = volume
					volume_indexes = [a, b]
				end
			end
		end
	end
	
	return (volume_indexes)
end

height_array = [1,8,6,2,5,4,8,3,7]
height_indices = container_points(height_array)
height1 = height_array[height_indices[0]]
height2 = height_array[height_indices[1]]
interval = absolute(height_indices[0] - height_indices[1]);

puts("This is the handy work of Ruby\n\n")
print(String(height_indices) + "\n")
print("The heights given the points is " + String(height1) + " on one end and " + String(height2) + " on the other end. The difference between the two points is " + String(interval) + " giving a total volume of " + String(get_volume(height1, height2, interval)) + "\n");
