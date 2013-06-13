<?php
	echo "<body bgcolor = '#F0F0F0'>";
	echo "<iframe height='80%' width='100%' src='index.html'></iframe>";
	echo "<form action='choiceProcess.php' method='post'>";
	echo "<input type='submit' name='newTemplate' value='New Template'/><br>";
	echo "<input type='submit' name ='transfer' value='Push to Domain'/>";
	echo "<select name='domainID'>";
		$link = mysql_connect('ada.gonzaga.edu', 'tweeks2', 'tweeks21234');
		if (!$link) {
			die('Could not connect: ' . mysql_error());
		}
		$db_selected = mysql_select_db('domainmgmttools', $link);
		if (!$db_selected) {
				die ('Can\'t use database : ' . mysql_error());
		}
		$result = mysql_query('SELECT id, name FROM domains ORDER BY name');
		if (!$result) {
				die('Invalid query: ' . mysql_error());
		}
		while ($row = mysql_fetch_assoc($result)) {
				echo '<option value="' . $row['id'] . '">' . $row['name'] . '</option>';
		}

		mysql_close($link);
	echo "</select>";
	echo "</form>";
?>