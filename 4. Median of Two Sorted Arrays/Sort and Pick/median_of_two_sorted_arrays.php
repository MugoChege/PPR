<?php
function get_median($list){
	$lenList = count($list);
	$evenLength = ($lenList % 2 == 0);
	$median = 0.0;
	
	if ($evenLength){
		$median = ((float)$list[$lenList / 2] + (float)$list[($lenList / 2) - 1]) / 2;
		//$median = ((float)$list[$len_list / 2] + (float)$list[($len_list / 2) - 1]) / 2;
	} else {
		$median = ((float)$list[$lenList / 2]);
	}
	
	return ($median);
}

function combine_list ($list1, $list2){
	Sort($list1);
	Sort($list2);
	
	$lenList1 = count($list1);
	$lenList2 = count($list2);
	
	$list1Cursor = 0;
	$list2Cursor = 0;
	
	$nje = [];
	
	while (($list1Cursor < $lenList1) || ($list2Cursor < $lenList2)){
		$elementList1 = null;
		$elementList2 = null;
		$appendingElement = null;
		
		if ($list1Cursor < $lenList1){
			$elementList1 = $list1[$list1Cursor];
		}
		
		if ($list2Cursor < $lenList2){
			$elementList2 = $list2[$list2Cursor];
		}
		
		if (($elementList1 !== null) && ($elementList2 !== null)){
			if ($elementList1 < $elementList2){
				$appendingElement = $elementList1;
				$list1Cursor += 1;
			} else {
				$appendingElement = $elementList2;
				$list2Cursor += 1;
			}
		} else if ($elementList1 == null){
			$appendingElement = $elementList2;
			$list2Cursor ++;
		} else if ($elementList2 == null){
			$appendingElement = $elementList1;
			$list1Cursor ++;
		}
		
		array_push ($nje, $appendingElement);
	}
	
	return ($nje);
}

$list1 = [1,3,5];
$list2 = [2,4];

$list_combined = combine_list($list1, $list2);

$median = get_median($list_combined);

echo ("This is the handy work of PHP.\n\n\n" . $median . "\n\n\n");
?>
