<?php
	class randomTemplate {

		public function randomize(){
				$files = glob("templates" . '/*.*');
    			$file = array_rand($files);
    			copy($files[$file],"templates/style.css");
		}
	}
?>