<?php 
include "randomTemplate.php";

	class htmlEditor {
		//Here we build the Meta Data~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		public static $open = "<html>\n<head>\n<title>\n";
		public static $middleTop = "\n</title>\n";
		public static $middleMiddle = "</head>\n<link rel=\"stylesheet\" type=\"text/css\" href=\"templates/style.css\">\n<body>\n<h1>\n";
		public static $middleBottom = "\n</h1>\n<p>\n";
		public static $tail =  "\n</p>\n</body>\n</html>";

		public function buildMeta($title, $text){
			$descName = self::findKeyWords($title);
			$descContent = self::findDescriptionContent($text, $title);
			$metaData = "<META NAME=\"description\" content=\"{$descContent}\">\n";
			$metaData = $metaData . "<META NAME=\"keyword\" content=\"{$descName}\">\n";
			$metaData = $metaData . "<META NAME=\"ROBOTS\" CONTENT=\"index, follow\">\n";
			$metaData = $metaData . "<META http-equiv=\"content-type\" content=\"text/html; charset=iso-8859-1\">\n";
			return $metaData;
		}

		public function findKeyWords($varTitle){
			$tempTitle = rtrim($varTitle, "\r\n");
			$tempExplodeAry = explode(" ", $tempTitle);
			$tempExplodeStrg = implode(",",$tempExplodeAry);
			$tempExplodeStrg = rtrim($tempExplodeStrg);
			return ($tempExplodeStrg);
		}

		//need to figure out how to find a word in a string other than strpos
		public function findDescriptionContent($varText,$varTitle){

			$tempExplodeTitleAry = explode(".", $varTitle);
			$tempExplodeTitleStg = implode(" ", $tempExplodeTitleAry);
			$tempExplodeTitleAry = explode(" ", $tempExplodeTitleStg);
			$tempExplodeText = explode(".", $varText);
			$tempExplodeText = array_map('strtolower', $tempExplodeText);
			$tempExplodeTitle = array_map('strtolower', $tempExplodeTitleAry);
			$descriptionNumber = array_fill(0, count($tempExplodeText), 0);

			for($i = 0; $i < count($tempExplodeText); $i++){
			  for($j = 0; $j < count($tempExplodeTitle); $j++){
			    if (strpos($tempExplodeText[$i],$tempExplodeTitle[$j]) ) {
			      $descriptionNumber[$i] = $descriptionNumber[$i] + 1;
			    }
			  }
			}

			$key = array_search(max($descriptionNumber), $descriptionNumber);
			$tempExplodeText[$key] = rtrim($tempExplodeText[$key]);
			$tempExplodeText[$key] = rtrim($tempExplodeText[$key], '<br>');
			return $tempExplodeText[$key];
		}

		

		//End Meta Data~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		//Here we build the HTML page~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		

		public function skeletonHtmlCreator($outputName, $title, $text){

			$file = fopen($outputName, 'w') or die("can't openP");
			$meta = self::buildMeta($title, $text);

			
			self::skeletonHtmlHeader($file, $title);
			self::skeletonHtmlMiddle($file, $title, $meta);
			self::skeletonHtmlTail($file, $text);

			fclose($file);
			$templateRandomizer = new randomTemplate;
			$templateRandomizer -> randomize();
		}

		public function skeletonHtmlHeader($file, $title){

			fwrite($file, self::$open);
			fwrite($file, $title);
		}

		public function skeletonHtmlMiddle($file, $title, $meta){

			fwrite($file, self::$middleTop);
			fwrite($file, $meta);
			fwrite($file, self::$middleMiddle);
			fwrite($file, $title);
			fwrite($file, self::$middleBottom);
		}

		public function skeletonHtmlTail($file, $text){

			fwrite($file, $text);
			fwrite($file, self::$tail);

		}

		
		//end build the HTML page~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	}

?>