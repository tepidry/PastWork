<?php
	include "randomTemplate.php";
	$domainArray = $_POST["domains"];
	$local_file = "test.txt";
	$local_style = 'templates/style.css';
	$fileHandle = fopen($local_file, 'w') or die("can't open file");
	fwrite($fileHandle, $_POST["title"] . "\n");
	fwrite($fileHandle, $_POST["article"]);
	fclose($fileHandle);
	$link = mysql_connect('ada.gonzaga.edu', 'tweeks2', 'tweeks21234');
	if (!$link) {
		die('Could not connect: ' . mysql_error());
	}
	$db_selected = mysql_select_db('domainmgmttools', $link);
	if (!$db_selected) {
    	die ('Can not use database : ' . mysql_error());
	}
	
	for ($i = 0; $i < count($domainArray); $i++)
	{

		$templateRandomizer = new randomTemplate;
		$templateRandomizer -> randomize();
		$result = mysql_query('SELECT * FROM domains WHERE id = ' . $domainArray[$i]);
		if (!$result) {
	    	die('Invalid query: ' . mysql_error());
		}
		$row = mysql_fetch_assoc($result);
	    $server = $row['ip_address']; //target server address or domain name
		$user = $row['username']; //username on target server
		$pass = $row['password']; //password on target server for Ftp
		$style_file = $row['name'] . "/templates/style.css";
		$destination_file = $row['name'] . "/test.txt";

		//================================
		$sessid = ftp_connect($server); //connect
		$login_ok = ftp_login($sessid, $user, $pass); //login
		ftp_pasv($sessid, true);
		if ((!$sessid) || (!$login_ok)):
			echo "failed to connect: check hostname, username & password";
			exit; //failed? Unable to connect!
		endif;

		//copy index.html
		if (ftp_put($sessid, $destination_file, $local_file, FTP_BINARY)) //Ftp get function which will download file
		{
			echo "<iframe style='visibility:hidden;display:none' onload = load() src ='http://" . $row['name'] . "/createHTML.php'></iframe>";
			echo "Successfully written to <a href = 'http://".$row['name']."/test'>".$row['name']."</a><br>";
		} else {
			echo "There was a problem<br>";
		}

		//copy createHTML.php
		if (ftp_put($sessid, $row['name'] . "/createHTML.php", "createHTML.php", FTP_BINARY)) //Ftp get function which will download file
		{} 
		else {
			echo "There was a problem<br>";
		}

		//copy htmlEditor.php
		if (ftp_put($sessid, $row['name'] . "/htmlEditor.php", "htmlEditor.php", FTP_BINARY)) //Ftp get function which will download file
		{} 
		else {
			echo "There was a problem<br>";
		}

		//copy languageSpin.php
		if (ftp_put($sessid, $row['name'] . "/languageSpin.php", "languageSpin.php", FTP_BINARY)) //Ftp get function which will download file
		{} 
		else {
			echo "There was a problem<br>";
		}

		//copy thesaurusSpin.php
		if (ftp_put($sessid, $row['name'] . "/thesaurusSpin.php", "thesaurusSpin.php", FTP_BINARY)) //Ftp get function which will download file
		{} 
		else {
			echo "There was a problem<br>";
		}

		//copy articleMetrics.php
		if (ftp_put($sessid, $row['name'] . "/articleMetrics.php", "articleMetrics.php", FTP_BINARY)) //Ftp get function which will download file
		{} 
		else {
			echo "There was a problem<br>";
		}

		//copy htmlEditor.php
		if (ftp_put($sessid, $row['name'] . "/zipHandler.php", "zipHandler.php", FTP_BINARY)) //Ftp get function which will download file
		{} 
		else {
			echo "There was a problem here<br>";
		}

		//copy translate.zip
		if (ftp_put($sessid, $row['name'] . "/translate.zip", "translate.zip", FTP_BINARY)) //Ftp get function which will download file
		{} 
		else {
			echo "There was a problem<br>";
		}

		//copy mashape.zip
		if (ftp_put($sessid, $row['name'] . "/mashape.zip", "mashape.zip", FTP_BINARY)) //Ftp get function which will download file
		{} 
		else {
			echo "There was a problem<br>";
		}

		//make templates directory
		$dir = $row['name'] . "/templates/";
		// try to create the directory $dir
		if (ftp_mkdir($sessid, $dir)) {
			//echo "successfully created $dir<br>";
		} else {
			//echo "There was a problem while creating template directory<br>";
		}

		//copy style.css
		if (ftp_put($sessid, $style_file, $local_style, FTP_BINARY)) //Ftp get function which will download file
		{
		 	//echo "Successfully written to $style_file<br>";
		} else {
		 	echo "There was a problem<br>";
		}

		ftp_close($sessid);

		mysql_query('UPDATE domains SET last_update = CURRENT_TIMESTAMP WHERE id =' . $domainArray[$i]);
	}
	mysql_close($link);
	//header( "refresh:2;url=http://" . $row['name'] );
?>