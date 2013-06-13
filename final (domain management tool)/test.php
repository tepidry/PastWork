<?php
	echo "<form action='newTransfer.php' method='post'>";
	echo "<select multiple name='domains[]'>";

	$link = mysql_connect('ada.gonzaga.edu', 'tweeks2', 'tweeks21234');
	if (!$link) {
		//die('Could not connect: ' . mysql_error());
	}
	$db_selected = mysql_select_db('domainmgmttools', $link);
	if (!$db_selected) {
			//die ('Can\'t use database : ' . mysql_error());
	}
	$result = mysql_query('SELECT * FROM domains');
	if (!$result) {
			die('Invalid query: ' . mysql_error());
	}
	while ($row = mysql_fetch_assoc($result)) {
			echo '<option value="' . $row['id'] . '">' . $row['name'] . '</option>';
	}

	mysql_close($link);

	echo "</select><br>";
	
	echo "<input type='submit' value='Select Domain(s)'/>";	
?>
