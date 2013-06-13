
<?php
    include ("translate/translator.php");
    class languageSpin
    {
        public function chunkSpin($article, $lang, $chunkLength)
        {
        	//session_start();
        	//include ("translate/translator.php");
        	//$article = $_SESSION['article'];
        	//$lang = $_SESSION['lang'];
            //$chunkLength = $_SESSION['chunkLength']; 
        	
            require_once("mashape/TextProcessing.php");
            //echo "hello";
            // basic instantiation. TODO Put your authentication keys here.
            $client = new TextProcessing("hr0gmjioykawxynbiai7j3hbngodoe", "neb0dew6qacwtsfuzliq9sxwk9caym");
            $language = null;
            $text = $article;

            $sentences = explode(".", $article);
            $numSentences  = count($sentences);

            if($chunkLength != Null)
            {
            //loops through each sentence in the article
                for($j=0; $j < $numSentences; $j++)
                {
                	//do the work here....
                	$maxString = "";
                	$response = $client->phrases($sentences[$j], $language); //Calls the Chunking API
                    var_dump($response);
                	echo($j . "->" . $sentences[$j] . "<br>");
                	$numberofNP = 0;
                	$numberofVP = 0;
                	if(!(empty($response->body->NP))) //check if any NP's exist
                    	$numberofNP = count($response->body->NP);

                	if(!(empty($response->body->VP))) //check if any VP's exist
                    	$numberofVP = count($response->body->VP);

                    if($numberofNP != 0)
                    {
                        $maxLength = 0;
                        $maxString = "";
                        for($i = 0; $i < $numberofNP; $i++)
                        {
                            if ($chunkLength < (strlen($response->body->NP[$i])))
                            {
                                //$maxLength = strlen($response->body->NP[$i]);
                                $maxString = $response->body->NP[$i];
                            }
                                 $translate = new translator;
                        $replaceString = ($translate->translate($maxString, $lang));
                        echo("Replace" . "->" . $replaceString . "<br>");
                        //echo($article . "<br>");
                        $article = str_replace($maxString, $replaceString, $article);


                        }
                	}
                	
                    echo($maxString . "<br>"); // test echo
                	
              
            		$article = $article;

                }
            echo("ORIGINAL" . "<br>" . $text . "<br>");
            
            //xdiff_string_diff($text, $article);
           
            }
            else
            {
                $translate = new translator;
                $article = $translate->translate($article, $lang);
            }
            echo("NEW" . "<br>" . $article); 
            return $article;
            //header( 'Location: postSpin.php' ) ;

        /*
            $maxString = "";
            //$text = "Come rent a apartment with us here at apartment rental spokane. We have what you are looking for; covered parking, dishwasher and on site laundry. One or two bedroom rentals with pets welcome with a pet deposit. Rentals starting as low as 400 dollars and up not including utilities. Sign up this month and get 50 dollars off your first monthâ€™s rent. If you are currently renting with us and are referring someone when they sign a 6 month lease get 50 and with a year lease expect up to a year.";
           
            // A sample function call. These parameters are not properly filled in.
            // See TextProcessing.php to find all function names and parameters.
            $response = $client->phrases($text, $language);

            // now you can do something with the response.
            //print ("Body $response->rawBody");
            //var_dump($response);
            $numberofNP = 0;
            $numberofVP = 0;
            if(!(empty($response->body->NP)))
                $numberofNP = count($response->body->NP);

            if(!(empty($response->body->VP)))
                $numberofVP = count($response->body->VP);

           // echo("SIZE OF NP" . $numberofNP . "\n");
           // echo("THIS IS THE LENGTH" . strlen($response->body->NP[0]));
           //finding the longest string in the NP array
            if($numberofNP != 0){
                $maxLength = 0;
                $maxString = "";
                for($i = 0; $i < $numberofNP; $i++)
                {
                    if ($maxLength < (strlen($response->body->NP[$i]))){
                        $maxLength = strlen($response->body->NP[$i]);
                        $maxString = $response->body->NP[$i];
                    }

                }
                //echo($maxLength); //test echo
                //echo($maxString); // test echo
            }
        	echo($maxString . "<br>");


        	$translate = new translator;
        	$replaceString = ($translate->translate($maxString, $lang));
        	echo($article . "<br>");
        	$article = str_replace($maxString, $replaceString, $article);
        	echo($article . "<br>");
        	echo($replaceString);
        	$_SESSION['article'] = $article;  //'$translate->translate($maxString, $lang);
        	*/
        }
    }
	

?>
	
