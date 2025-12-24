<?php
function duplicatesShiftingRemove(&$list){
	$counter = 0;
	$lenList = count($list);
	
	Sort($list);
	
	for ($i = ($lenList - 1); $i >= 0; $i--){
		$element = $list[$i];
		$unique = true;
		
		for ($j = 0; $j < $i; $j++){
			if ($element == $list[$j]){
				$unique = false;
				break;
			}
		}
		
		if ($unique == false){
			$counter += 1;
			$holder = $list[$j];
			
			for ($j = $i; $j < ($lenList - 1); $j++){
				$list[$j] = $list[$j + 1];
			}
			
			$list[$lenList - 1] = $holder;
		}
	}
	
	return ($counter);
}

$nums = [0,0,1,1,1,2,2,3,3,4];
$val = duplicatesShiftingRemove($nums);

echo(strval($val). "\n\n\n");
echo(json_encode($nums). "\n" . json_encode(array_slice($nums, 0, (count($nums) - $val))). "\n\n\n");
?>
