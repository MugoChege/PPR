<?php
function removeByShifting ($element, &$list){
	$count = 0;
	$lenList = count($list);
	
	for ($i = ($lenList - 1); $i >= 0; $i--){
		if ($list[$i] == $element){
			$count += 1;
			$holder = $list[$i];
			
			for ($j = $i; $j < ($lenList - 1); $j++){
				$list[$j] = $list[$j + 1];
			}
			
			$list[$lenList - 1] = $holder;
		}
	}
	
	return ($count);
}

$nums = [0,1,2,2,3,0,4,2];
$val = 2;

$rem = removeByShifting($val, $nums);

echo ($rem . "\n\n\n" . json_encode($nums) . "\n" . json_encode(array_slice($nums, 0, (count($nums) - $rem))) . "\n\n\n");
?>
