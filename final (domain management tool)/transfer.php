<?php
	session_start();
	$link = mysql_connect('ada.gonzaga.edu', 'tweeks2', 'tweeks21234');
	if (!$link) {
		die('Could not connect: ' . mysql_error());
	}
	$db_selected = mysql_select_db('domainmgmttools', $link);
	if (!$db_selected) {
    	die ('Can\'t use database : ' . mysql_error());
	}
	$result = mysql_query('SELECT * FROM domains WHERE id = ' . $_SESSION['domainID']);
	if (!$result) {
    	die('Invalid query: ' . mysql_error());
	}
	$row = mysql_fetch_assoc($result);
    	$server = $row['ip_address']; //target server address or domain name
	$user = $row['username']; //username on target server
	$pass = $row['password']; //password on target server for Ftp
	$html_file = $row['name'] . "/index.html";
	$style_file = $row['name'] . "/templates/style.css";  

	$local_html = 'index.html';
	$local_style = 'templates/style.css';
	//================================
	$sessid = ftp_connect($server); //connect
	$login_ok = ftp_login($sessid, $user, $pass); //login
	ftp_pasv($sessid, true);
	if ((!$sessid) || (!$login_ok)):
		echo "failed to connect: check hostname, username & password";
		exit; //failed? Unable to connect!
	endif;

	//copy index.html
	if (ftp_put($sessid, $html_file, $local_html, FTP_BINARY)) //Ftp get function which will download file
	{
		echo "Successfully written to $html_file<br>";
	} else {
		echo "There was a problem<br>";
	}

	//make templates directory
	$dir = $row['name'] . "/templates/";
	// try to create the directory $dir
	if (ftp_mkdir($sessid, $dir)) {
		echo "successfully created $dir<br>";
	} else {
		//echo "There was a problem while creating $dir<br>";
	}

	//copy style.css
	if (ftp_put($sessid, $style_file, $local_style, FTP_BINARY)) //Ftp get function which will download file
	{
	 echo "Successfully written to $style_file<br>";
	} else {
	 echo "There was a problem<br>";
	}

	ftp_close($sessid);

	mysql_query('UPDATE domains SET last_update = CURRENT_TIMESTAMP WHERE id ='.$_SESSION['domainID']);
	mysql_close($link);
	header( "refresh:2;url=http://" . $row['name'] );
?>