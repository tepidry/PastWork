<html>
<head>
	<title>
		Domain Management Tool
	</title>
</head>
<body bgcolor = "F0F0F0">

<?php
	
	session_start();

	$title = $_SESSION['title'];
	$article = $_SESSION['article'];
	//$title = "title";

	echo "<form action='newTransfer.php' method='post'>";
		echo "Title<br>";
		echo "<input type='text' style='resize: none; width: 100%; height: 30' type='text' name='title' value='" . $title . "'/><p>";
		echo "Article<br>";
		echo "<textarea style='resize: none; width: 100%; height: 60%' type='text' name='article'>" . $article . "</textarea><p>";
		
		echo "<select multiple name='domains[]'>";

		$link = mysql_connect('ada.gonzaga.edu', 'tweeks2', 'tweeks21234');
		if (!$link) {
			//die('Could not connect: ' . mysql_error());
		}
		$db_selected = mysql_select_db('domainmgmttools', $link);
		if (!$db_selected) {
				//die ('Can\'t use database : ' . mysql_error());
		}
		$result = mysql_query('SELECT * FROM domains ORDER BY name');
		if (!$result) {
				die('Invalid query: ' . mysql_error());
		}
		while ($row = mysql_fetch_assoc($result)) {
				echo '<option value="' . $row['id'] . '">' . $row['name'] . '</option>';
		}

		mysql_close($link);

		echo "</select><br>";
		
		echo "<input type='submit' value='Select Domain(s)'/>";	
	
	echo "</form>";
	?>
</body>
</html>