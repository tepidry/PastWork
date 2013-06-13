<?php
	include("zipHandler.php");
	include ("htmlEditor.php");
	include ("languageSpin.php");
	include ("thesaurusSpin.php");

	//zipHandler::unZip("mashape");
	//zipHandler::unZip("translate");
	//require_once('db.php');
    //ini_set(’session.gc_maxlifetime’, 30*60);
    // your code here

	$myFile = "test.txt";
	$fh = fopen($myFile, 'r');

	$title = fgets($fh);

	while (!feof($fh)) {
	   $text .= fgets($fh) . "<br>";
	}
	fclose($fh);
	$randLang = array('es', 'ar', 'de', 'fi', 'fr', 'it', 'uk');
	
	set_time_limit(600);
	$text = languageSpin::chunkSpin($text, $randLang[rand(0, count($randLang) - 1)], 6);
	echo ("t1:" . $text);
	//$text = thesaurusSpin::wordSpin($text);
	echo ("t2:" . $text);

	
	//Page being created
	$outputName = "test.html";

	htmlEditor::skeletonHtmlCreator($outputName, $title, $text);

	//ex. of what is happening in htmlEditor.
	// $meta = htmlEditor::buildMeta($title, $text);
	// //This is the strings that make up the skeleton of the html page
	// htmlEditor::skeletonHtmlHeader($outputHandle, $title, $open);
	// htmlEditor::skeletonHtmlMiddle($outputHandle, $title, $middleTop, $middleMiddle, $middleBottom,$meta);
	// htmlEditor::skeletonHtmlTail($outputHandle, $text, $tail);


	//close index
	// fclose($outputHandle);
	// $templateRandomizer = new randomTemplate;
	// $templateRandomizer -> randomize();
	//header( 'Location: test.html' ) ;
	
?>