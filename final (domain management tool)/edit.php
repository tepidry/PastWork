<html>
<head>
	<title>
		Domain Management Tool
	</title>
</head>
<body bgcolor = F0F0F0>

<?php
	echo "<body bgcolor = 'gray'>";
	echo "Select a Domain:";
	$link = mysql_connect('ada.gonzaga.edu', 'tweeks2', 'tweeks21234');
	if (!$link) {
		die('Could not connect: ' . mysql_error());
	}
	$db_selected = mysql_select_db('domainmgmttools', $link);
	if (!$db_selected) {
		die ('Can\'t use database : ' . mysql_error());
	}
	if (isset($_POST['delete'])) {
		mysql_query('DELETE FROM domains WHERE name = "'.$_REQUEST['name'].'"');
	}
	if (isset($_POST['update'])) {
		$result = mysql_query('SELECT name FROM domains ORDER BY name');
		if (!$result) {
			die('Invalid query: ' . mysql_error());
		}
		$exists = False;
		while ($row = mysql_fetch_assoc($result)) {
			if ($row['name'] == $_REQUEST['url']) {
				$exists = True;
			}
		}
		if ($exists) {
			mysql_query("UPDATE domains SET ip_address ='".$_REQUEST['ip']."', username ='".$_REQUEST['username']."', password='".$_REQUEST['password']."' WHERE name ='".$_REQUEST['url']."'");
		} else {
			mysql_query("INSERT INTO domains VALUES (null,'".$_REQUEST['url']."','".$_REQUEST['ip']."','".$_REQUEST['username']."','".$_REQUEST['password']."',null,null,null)");
		}
	}



	$result = mysql_query('SELECT name, ip_address, username, password, last_update FROM domains ORDER BY name');
	//$row = mysql_fetch_assoc($result);
	$row = mysql_query('SELECT name, ip_address, username, password, last_update FROM domains ORDER BY name');
	$name = $row['name'];
	$ip = $row['ip_address'];
	$username = $row['username'];
	$password = $row['password'];
	$last_update = $row['last_update'];

	if (!$result) {
		die('Invalid query: ' . mysql_error());
	}
	echo "<form action='edit.php' method='post'>";
	echo "<select name='name'>";
	while ($row = mysql_fetch_assoc($result)) {
		echo '<option value="' . $row['name'] . '">' . $row['name'] . '</option>';
	}
	echo "</select>";
	echo "<input type='submit' name='select' value='Select'/>";
	echo "<input type='submit' name='delete' value='Delete'/><br>";
	if (isset($_POST['select'])) {
		$result = mysql_query('SELECT name, ip_address, username, password, last_update FROM domains ORDER BY name');
		while ($row = mysql_fetch_assoc($result)) {
			if ($row['name'] == $_REQUEST['name']) {
				$name = $row['name'];
				$ip = $row['ip_address'];
				$username = $row['username'];
				$password = $row['password'];
				$last_update = $row['last_update'];
			}
		}
	}
	echo "Name<br><input type='text' size='75' name='url' value='".$name."'><br>";
	echo "IP Address<br><input type='text' size='75' name='ip' value='".$ip."'><br>";
	echo "Username<br><input type='text' size='75' name='username' value='".$username."'><br>";
	echo "Password<br><input type='password' size='75' name='password' value='".$password."'><br>";
	echo "Last Update: ".$last_update."<br><br>";
	echo "<input type='submit' name='update' value='Update/Add'/><br>";
	echo "<iframe style = 'border-style:solid;border-color:lightgray' height='50%' width='80%' src='http://". $name . "'></iframe>";
	echo "</form>";
	mysql_close($link);
	// if ($_POST['goHome']) {
	//     header( 'Location: index.php' ) ;
	// }
?>
</body>
</html>