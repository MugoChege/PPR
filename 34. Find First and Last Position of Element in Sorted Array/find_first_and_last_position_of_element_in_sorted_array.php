<?php
function firstAndLast ($element, $list){
	$findFirst = true;
	$out = [-1, -1];
	Sort($list);
	
	for ($i = 0; $i < count($list); $i++){
		$e = $list[$i];
		if ($e == $element){
			if ($findFirst){
				$out[0] = $i;
				$out[1] = $i;
				$findFirst = false;
			} else {
				$out[1] = $i;
			}
		}
	}
	
	return ($out);
}

$nums = [5,7,7,8,8,10,2];
$target = 8;

echo (json_encode(firstAndLast($target, $nums)). "\n\n\n\n");
?>
