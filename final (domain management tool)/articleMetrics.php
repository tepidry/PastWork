<?php
	class articleMetrics {
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		public static $spacersArray = array(".",",","?","!",";",":","&amp;#xD;", "    ","   ","  ", " ", "<br>");

		//explodes a string by all common spacers as described by $spacersArray
		public function multiexplode ($string) 
		{
			$i = 0;
			$ary = explode(self::$spacersArray[$i], $string);
			$strg = implode(" ", $ary);
		    for($i; $i < count(self::$spacersArray); ++$i)
		    {
		        $ary = explode(self::$spacersArray[$i], $strg);
		        $strg = implode(" ", $ary);
		    }
		    $ary = explode(" ",$strg);
		    return $ary;
		}

		//creates a array of elements that are sentences
		public function sentenceExplode($string)
		{
			return explode(".", $string);
		}

		//this is going to change
		public function printStringDiff($newArray, $oldArray)
		{
			$tempArry = array_diff_assoc( $newArray , $oldArray );
			foreach($tempArry as $value) {
			  echo $value;
			}
		}

		//returns the words in a $string.
		public function wordCount($string)
		{
			$wordArray = self::multiexplode($string);
			return count($wordArray);
		}

		//returns a string of words that are in the $newArray not present in the $oldArray
		public function returnStringNewWordsFound($newArray, $oldArray)
		{
			$lowerCaseNewArray = array_map('strtolower', $newArray);
			$lowerCaseOldArray = array_map('strtolower', $oldArray);
			$lowerNewSting = implode(" ", $lowerCaseNewArray);
			$loweroldString = implode(" ", $lowerCaseOldArray);
			$newArray = self::multiexplode($lowerNewSting);
			$oldArray = self::multiexplode($loweroldString);
			return implode(", ", array_diff($newArray, $oldArray));
		}

		public function returnNumberNewWordsFound($newArray, $oldArray)
		{
			$lowerCaseNewArray = array_map('strtolower', $newArray);
			$lowerCaseOldArray = array_map('strtolower', $oldArray);
			$lowerNewSting = implode(" ", $lowerCaseNewArray);
			$loweroldString = implode(" ", $lowerCaseOldArray);
			$newArray = self::multiexplode($lowerNewSting);
			$oldArray = self::multiexplode($loweroldString);
			return count(array_diff($newArray, $oldArray));
		}

		public function returnLowerString(&$num1, &$num2)
		{
			
		}
	}
?>
