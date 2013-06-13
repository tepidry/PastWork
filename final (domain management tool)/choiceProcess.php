<?php
require_once("articleMetrics.php");
require_once("htmlEditor.php");
require_once "randomTemplate.php";
require_once("languageSpin.php");
require_once("thesaurusSpin.php");
// check which button was clicked;
// take user to correct page
	session_start();
	$_SESSION['title'] = $_REQUEST['title'];
	$_SESSION['article'] = $_REQUEST['article'];
	$_SESSION['spunArticle'] = $_REQUEST['spunArticle'];
	if ($_POST['generatePreHTML']) {
		htmlEditor::skeletonHtmlCreator("index.html", $_SESSION['title'], $_SESSION['article']);
	    header( 'Location: preview.php' ) ;
	}
	else if ($_POST['generatePostHTML']) {
		htmlEditor::skeletonHtmlCreator("index.html", $_SESSION['title'], $_SESSION['spunArticle']);
	    header( 'Location: preview.php' ) ;
	}
	else if ($_POST['transfer']) {
		$_SESSION['domainID'] = $_REQUEST['domainID'];
		header( 'Location: transfer.php' ) ;
	}
	else if ($_POST['newTemplate']) {
		require_once "randomTemplate.php";
  		$templateRandomizer = new randomTemplate;
  		$templateRandomizer->randomize();
	    header( 'Location: preview.php' ) ;
	}
	else if ($_POST['languageSpin']) {
		$_SESSION['spunArticle'] = languageSpin::chunkSpin($_SESSION['article'], $_REQUEST['lang'], $_REQUEST['chunkLength']);
	    header( 'Location: single.php' ) ;
	}
	else if ($_POST['thesaurusSpin']) {
	    header( 'Location: thesaurusSpin.php' ) ;
	}
	else if ($_POST['wordReplace']) {
		$_SESSION['spunArticle'] = $_SESSION['article'];
		$_SESSION['article'] = str_replace($_REQUEST['replaceWord'],$_REQUEST['replacementWord'],$_SESSION['article']);
	    header( 'Location: single.php' ) ;
	} 
	else if ($_POST['selectDomains']) {
		header( 'Location: newTransfer.php' ) ;
	}
	// else if($_POST['single']) {
	// 	$_SESSION['article'] = "Pre";
	// 	$_SESSION['spunArticle'] = "Post";
	// 	$_SESSION['title'] = "Title";
	// 	header('Location: single.php');
	// }
	// else if ($_POST['multiple']) {
	// 	$_SESSION['article'] = "";
	// 	$_SESSION['title'] = "Title";
	// 	header('Location: multiple.php');
	// }

?>