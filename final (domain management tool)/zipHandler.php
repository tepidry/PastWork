<?php
	class zipHandler{
		public function unZip($file)
		{
			$zip = new ZipArchive;
			echo "new";
			if ($zip->open($file . '.zip') === true) {
			    $zip->extractTo('./');
			    $zip->close();
			    echo 'extracted';
			} else {
			    echo 'extract failed';
			}
		}

		public function arrayZip($fileArray, $destination)
		{
			$zip = new ZipArchive();
			if($zip->open($destination, true ? ZIPARCHIVE::OVERWRITE : ZIPARCHIVE::CREATE) !== true) {
				return false;
			}
			//add the files
			for($i = 0; $i < count($fileArray); $i++) {
				$zip->addFile($fileArray[$i],$fileArray[$i]);
			}
		}
	}
	

?>