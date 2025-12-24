<?php
function numberFromList ($list){
	$out = 0;
	$lenList = count($list);
	$base = 10;
	
	for ($i = 0; $i < $lenList; $i++){
		$out += ($list[$i] * pow($base,($lenList - (1 + $i))));
	}
	
	return $out;
}

function numberToList ($number, $originalListLen = 0){
	$out = [];
	$base = 10;
	$running_number = $number;
	
	while ($running_number > 0){
		$modulo = $running_number % $base;
		$running_number -= $modulo;
		$running_number /= $base;
		array_push($out, $modulo);
	}
	
	if ($originalListLen != 0){
		while (count($out) < $originalListLen){
			array_push($out, 0);
		}
	}
	
	$out = array_reverse($out);
	
	return ($out);
}

function listComparison ($list1, $list2){
	$out = false;
	$lenList1 = count($list1);
	$lenList2 = count($list2);
	
	if ($lenList1 != $lenList2){
		return ($out);
	}
	
	$list1BoolMap = [];
	$list2BoolMap = [];
	
	for ($i = 0; $i < $lenList1; $i++){
		array_push($list1BoolMap, false);
		array_push($list2BoolMap, false);
	}
	
	for ($i = 0; $i < $lenList1; $i++){
		for ($j = 0; $j < $lenList1; $j++){
			if (($list1BoolMap[$i] == false) && ($list2BoolMap[$j] == false)){
				if ($list1[$i] == $list2[$j]){
					$list1BoolMap[$i] = true;
					$list2BoolMap[$j] = true;
					break;
				}
			}
		}
	}
	
	$boolCounter = 0;
	
	for ($i = 0; $i < $lenList1; $i++){
		if ($list1BoolMap[$i] && $list2BoolMap[$i]){
			$boolCounter += 1;
		}
	}
	
	return (count($list1BoolMap) == $boolCounter);
}

function appears ($element, $list){
	$out = -1;
	$lenList = count($list);
	
	for ($i = 0; $i < $lenList; $i++){
		if ($element == $list[$i]){
			$out += 1;
		}
	}
	
	return ($out);
}

$nums = [1,2,3];
$lenNums = count($nums);
sort($nums);
$lowestValueNumsNumber = numberFromList($nums);
$nums = array_reverse($nums);
$highestValueNumsNumber = numberFromList($nums);

echo ($lowestValueNumsNumber . "\n");
echo ($highestValueNumsNumber . "\n");

$permutations = [];

$runningNumber = $lowestValueNumsNumber;

while ($runningNumber <= $highestValueNumsNumber){
	$tempNumsList = numberToList($runningNumber, $lenNums);
	if (listComparison($tempNumsList, $nums)){
		array_push($permutations, $tempNumsList);
	}
	
	$runningNumber++;
}

echo(json_encode($permutations));

echo("\n\n\n");

?>
