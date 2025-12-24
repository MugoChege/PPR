<?php
function getTarget ($nums, $target){
	$lenNums = count($nums);
	$out = null;
	
	for ($a = 0; $a < $lenNums; $a++){
		$exitLoop = false;
		for ($b = 0; $b < $lenNums; $b++){
			if ($b == $a){
				continue;
			} else {
				if (($nums[$a] + $nums[$b]) == $target){
					$out = [$a,$b];
					$exitLoop = true;
					break;
				}
			}
		}
		
		if ($exitLoop){
			break;
		}
	}
	
	return ($out);
}

$numberList = [1,2,3,4,5,6,7,8,9];
$target = 16;

$indices = getTarget($numberList, $target);

echo(json_encode($indices));
echo("\n");

if (gettype($indices) == "array"){
	print(json_encode($numberList[$indices[0]]));
	echo("\n");
	print(json_encode($numberList[$indices[1]]));
	echo("\n");
}

?>
