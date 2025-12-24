#class Solution:
#	def twoSum(self, nums: List[int], target: int) -> List[int]:

def get_target (nums, target):
	len_nums = len (nums)
	out = None
	
	for a in range (len_nums):
		exitLoop = False
		for b in range (len_nums):
			if (b == a):
				continue
			else:
				if ((nums[a] + nums [b]) == target):
					out = [a,b]
					exitLoop = True
					break
		if (exitLoop):
			break
	
	return out

number_list = [1,2,3,4,5,6,7,8,9]
target = 16

indices = get_target(number_list, target)
print (indices)

if type(indices == list):
	print (number_list[indices[0]])
	print (number_list[indices[1]])

