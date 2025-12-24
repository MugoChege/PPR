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
	$combined_list = [];
	
	foreach ($list1 as $i){
		array_push($combined_list, $i);
	}
	
	foreach ($list2 as $i){
		array_push($combined_list, $i);
	}
	
	Sort($combined_list);
	
	return ($combined_list);
}

$list1 = [1,3,5];
$list2 = [2,4];

$list_combined = combine_list($list1, $list2);

$median = get_median($list_combined);

echo ($median . "\n\n\n");
?>
