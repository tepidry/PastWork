<!--takes the old text and passes it into the translator api
gets the translated text back and displays the old and new text-->
<?php
	require_once ("articleMetrics.php");
	session_start();
	$title = $_SESSION['title'];
	$article = $_SESSION['article'];
	$spunArticle = $_SESSION['spunArticle'];


	articleMetrics::returnLowerString($num1, $num2);

	$newWordCout = articleMetrics::wordCount($article);
	$oldWordCout = articleMetrics::wordCount($spunArticle);

	$newArray = articleMetrics::multiexplode($article);
	$oldArray = articleMetrics::multiexplode($spunArticle);

	$newWords = articleMetrics::returnStringNewWordsFound($newArray, $oldArray);
	$oldWords = articleMetrics::returnStringNewWordsFound($oldArray, $newArray);

	$newNumDiff = articleMetrics::returnNumberNewWordsFound($newArray, $oldArray);
	$oldNumDiff = articleMetrics::returnNumberNewWordsFound($oldArray, $newArray);

	echo "<body bgcolor = 'F0F0F0'>";
	echo "<form action='choiceProcess.php' method='post'>";
	echo "Title<br><input type='text' style='resize: none; width: 100%; height: 30' type='text' name='title' value='" . $title . "'/><p>";

	echo "<table cellspacing = '2' cellpadding='2' bgcolor= 'white' border='1'>";

	echo "<tr>";
	echo "<td>";
	echo "<input type='submit' name='generatePreHTML' value='Create HTML'/>";
	echo "</td>";
	echo "<td>Word Count = " .$newWordCout.  "</td>";
	echo "<td>Number Of Different Words From 'Previous':" . $newNumDiff . "</td>";
	echo "<td>New Words:" . $newWords . "</td>";
	
	//echo "<td>New Test:" . $newWords . "</td>";
	

	
	echo "</tr>";
	echo "</table>";

	echo "Pre-Spin:<br><textarea style='resize: none; width: 100%; height: 30%' type='text' name='article'>" . $article . "</textarea><p>";
	
	

	echo "<table cellspacing = '2' cellpadding='2' bgcolor= 'white' border='1'>";
	echo "<tr>";
	echo "<td>";
	echo "<input type='submit' name='generatePostHTML' value='Create HTML'/>";
	echo "</td>";
	echo "<td>Word Count = " . $oldWordCout. "</td>";
	echo "<td>Number Of Different Words From 'New':" . $oldNumDiff . "</td>";
	echo "<td>Old Words Out:" . $oldWords . "</td>";
	echo "</tr>";
	echo "</table>";

	
	

	echo "Post_Spin:<br><textarea style='resize: none; width: 100%; height: 30%' type='text' name='spunArticle'>" . $spunArticle . "</textarea>";

	echo "<table>";
	echo "<tr>";
	echo "<td><input type='submit' name='languageSpin' value='Language Spin'/></td>";
	echo "<td>";
	echo "Language<select name='lang'>";

	$link = mysql_connect('ada.gonzaga.edu', 'tweeks2', 'tweeks21234');
	if (!$link) {
		//die('Could not connect: ' . mysql_error());
	}
	$db_selected = mysql_select_db('domainmgmttools', $link);
	if (!$db_selected) {
			//die ('Can\'t use database : ' . mysql_error());
	}
	$result = mysql_query('SELECT * FROM spinner_languages');
	if (!$result) {
			//die('Invalid query: ' . mysql_error());
	}
	while ($row = mysql_fetch_assoc($result)) {
			echo '<option value="' . $row['abbreviation'] . '">' . $row['language'] . '</option>';
	}

	mysql_close($link);

	echo "</select></td>";
	echo "<td>";
	echo "Chunk Length<select name='chunkLength'>";
	echo "<option value='".NULL."'>None</option>";
	for($i = 6; $i <= 20; $i += 2)
		echo '<option value="'.$i.'">'.$i.'</option>';
	echo "</select></td>";
	echo "</tr>";
	echo "<tr>";
	echo "<br>";
	echo "<td><input type='submit' name='wordReplace' value='Replace Word'/></td>";
	echo "<td>Replace<input type = 'text' style ='resize: none; width: 150; height 30' type='text' name='replaceWord'/></td>";
	echo "<td>With<input type = 'text' style ='resize: none; width: 150; height 30' type='text' name='replacementWord'/></td>";
	echo "</tr>";
	echo "<br>";
	echo "<tr>";
	echo "<td><input type='submit' name='thesaurusSpin' value='Thesaurus Spin'/></td>";
	echo "</tr>";
	echo "</table>";
		
	echo "</form>";



?>
