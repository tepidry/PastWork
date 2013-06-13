<?php
require_once("mashape/MashapeClient.php");


class TextProcessing {
	const PUBLIC_DNS = "japerk-text-processing.p.mashape.com";
	private $authHandlers;

	function __construct($publicKey, $privateKey) {
		$this->authHandlers = array();
		$this->authHandlers[] = new MashapeAuthentication($publicKey, $privateKey);
		
	}
	public function phrases($text, $language = null) {
		$parameters = array(
			 
			
				"language" => $language,
				"text" => $text );

		$response = HttpClient::doRequest(
				HttpMethod::POST,
				"https://" . self::PUBLIC_DNS . "/phrases/",
				$parameters,
				$this->authHandlers,
				ContentType::FORM,
				true);
		return $response;
	}
	public function sentiment($text, $language = null) {
		$parameters = array(
			 
			
				"text" => $text,
				"language" => $language );

		$response = HttpClient::doRequest(
				HttpMethod::POST,
				"https://" . self::PUBLIC_DNS . "/sentiment/",
				$parameters,
				$this->authHandlers,
				ContentType::FORM,
				true);
		return $response;
	}
	public function stem($text, $language = null, $stemmer = null) {
		$parameters = array(
			 
			
				"language" => $language,
				"stemmer" => $stemmer,
				"text" => $text );

		$response = HttpClient::doRequest(
				HttpMethod::POST,
				"https://" . self::PUBLIC_DNS . "/stem/",
				$parameters,
				$this->authHandlers,
				ContentType::FORM,
				true);
		return $response;
	}
	public function tag($text, $language = null, $output = null) {
		$parameters = array(
			 
			
				"language" => $language,
				"output" => $output,
				"text" => $text );

		$response = HttpClient::doRequest(
				HttpMethod::POST,
				"https://" . self::PUBLIC_DNS . "/tag/",
				$parameters,
				$this->authHandlers,
				ContentType::FORM,
				true);
		return $response;
	}
	

	
}
?>