<?php
	class translator {
		
		public function translate($text, $to){
			require_once('config.inc.php');
			require_once('class/ServicesJSON.class.php');
			require_once('class/MicrosoftTranslator.class.php');
			$translator = new MicrosoftTranslator(ACCOUNT_KEY);
			$text_to_translate = $text;
			$from = "en";
			$translator->translate($from, $to, $text_to_translate);

			$data = json_decode($translator->response->jsonResponse);

			$parse = explode(">", $data->translation);
			$parse = explode("<", $parse[1]);
			$translation = $parse[0];

			//back to english
			$translator->translate($to, $from, $translation);

			$data = json_decode($translator->response->jsonResponse);

			$parse = explode(">", $data->translation);
			$parse = explode("<", $parse[1]);
			$translationBack = $parse[0];
			return $translationBack;
		}

	}
?>


