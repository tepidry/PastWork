<html>
<head>
<title>Domain Management Tool</title>
<style type="text/css">
            body,
            div {
                margin: 0;
                padding: 0;
            }

            body {
                /* Disable scrollbars and ensure that the body fills the window */
                overflow: hidden;
                width: 100%;
                height: 100%;
            }

            #logo {
                /* Provide scrollbars if needed and fix the header dimensions */
                /*overflow: auto;*/
                position: absolute;
                width: 50%;
                height: 100px;
                background-color:#77AAFF;
            }

            #buttons {
                /* Provide scrollbars if needed and fix the header dimensions */
                overflow: auto;
                position: absolute;
                left : 50%;
                width: 50%;
                height: 100px;
                background-image:url('gradient.jpg');
                background-color:#77AAFF;
            }

            #main {
                /* Provide scrollbars if needed, position below header, and derive height from top/bottom */
                overflow: auto;
                position: absolute;
                width: 100%;
                top: 100px;
                bottom: 0;
            }
        </style>
</head>
<body>
	<div id="logo">
		<img src = 'logo.png' height = 100%></img>
	</div>
	<div id="buttons">
		<br><br>
		<form action='index.php' method='post'>
			<input type='submit' name='edit' value='Edit Domains'/>
			<input type='submit' name='single' value='Push Single'/>
			<input type='submit' name='multiple' value='Push Multiple'/>
		</form>
	</div>
	<div id="main">
		<?php
			if (isset($_POST['edit']))
			{
			    echo "<iframe src = 'edit.php' width = 100% height = 100% seamless></iframe>";
			}
			if (isset($_POST['single']))
			{
			    echo "<iframe src = 'single.php' width = 100% height = 100% seamless></iframe>";
			}
			if (isset($_POST['multiple']))
			{
			    echo "<iframe src = 'multiple.php' width = 100% height = 100% seamless></iframe>";
			}
		?>
	</div>
</body>
</html>