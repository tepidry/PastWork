
<?php
require_once("mashape/TextProcessing.php");
require_once("articleMetrics.php");
//include ("translate/translator.php");
//session_start();
//$title = $_SESSION['title'];
//$article = $_SESSION['article'];




class thesaurusSpin
    {
        public function get_between ($string, $start, $end) {
            $string = " ". $string;
            $ini = strpos($string, $start);
            if ($ini == 0) return "";
            $ini += strlen($start);
            $len = strpos($string,$end,$ini) - $ini;
            return substr($string,$ini,$len);
        }

        public function strip_hidden_chars($str)
        {
            $chars = array("\r\n", "\n", "\r", "\t", "\0", "\x0B");

            $str = str_replace($chars," ",$str);

            return preg_replace('/\s+/',' ',$str);
        }


        //JJ adjective RB adverb
        public function createArraySentChunk($strRsp)
        {

            $trimmed = ltrim($strRsp, "(S  ");
            $trimmed = rtrim($trimmed, " ./.)");
            $strArray = explode("(S ", $trimmed);
            $string = implode("", $strArray);
            $strArray = explode(" ./.)", $string);
            
            $sentenceCount = count($strArray);
            
            for ($i = 0; $i < $sentenceCount; $i++)
            {
                if(strpos($strArray[$i], "JJ") || strpos($strArray[$i], "RB")){
                    $strArray[$i] = ltrim($strArray[$i], " ");
                    $wrdAry = articleMetrics::multiexplode($strArray[$i]);
                    // if ((($key = array_search("", $strArray))|| ($key = array_search(" ", $strArray))) !== false) {
                    //     unset($strArray[$key]);
                    // }
                    $strArray[$i] = $wrdAry;
                    // $wordCount = count($wrdAry);
                    // print_r($wrdAry);
                    // for($i = 0; $i < $wordCount; $i++)
                    // {

                    // }
                    // $tempStrg = $strArray[$i];

                    // $strArray[$i] = array;
                }
                
            }
            //return $wrdAry;
            return $strArray;
        }


        public function wordSpin($article)
        {
            // basic instantiation. TODO Put your authentication keys here.
            $client = new TextProcessing("hr0gmjioykawxynbiai7j3hbngodoe", "neb0dew6qacwtsfuzliq9sxwk9caym");
            $language = null;
            $text = $article;

            $sentences = explode(".", $article);
            $numSentences  = (count($sentences) - 1);

            $response = $client->tag($text, $language); //Calls the Chunking API
            
            echo($response->body->text . "<b>");

            // $response = $client->tag($sentences[0], $language); //Calls the Chunking API
               

            $stringResponse = $response->body->text;
            $arrayResponse = self::createArraySentChunk($stringResponse);
            echo("<br>"."HERE:"."<br>");
            print_r($arrayResponse);
            ///CHUNKING THESAURUS
            // echo( "here::: ");
            // print_r($sentences);
            // //goes through each sentence
            // for($i = 0; $i < $numSentences; $i++) {
            //     echo( "HERE". $numSentences."<br>");
            //     print_r($sentences);
            //     echo("BOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOm" . ($i) . "<br>");
            //     $wordArray = articleMetrics::multiexplode($sentences[$i]);
                

                
            // }
            // echo( "here::: " . "<br>");
            // print_r($sentences);

            // //goes through each sentence.
            // for ($i = 0;$i < count($wordArray); $i++)
            // {
            //     echo("<br>" . ($i) . ". " .$wordArray[$i] . "<br>");
            //     $wordIn = $wordArray[$i];

            //     $url = "http://words.bighugelabs.com/api/2/15488f9fd28f09df538092065810b7df/{$wordIn}/php";

            //     $check = get_headers($url);
            //     print_r($check);
            //     if($check[0] == "HTTP/1.1 404 Not Found")
            //     {
            //         echo "################not";
            //         $rsp_obj = null;
            //     }else{
            //         echo "######################got";
            //         $rsp = file_get_contents($url);
            //         $rsp_obj = unserialize($rsp);
            //         print_r($rsp_obj);
            //         if (array_key_exists("adjective",  $rsp_obj)){
                        
            //             //echo "<br/>";
            //             echo "<br/> Adjective: <br/>";
            //             //echo "<br/> Adjective: <br/>";
            //             if(!(empty($rsp_obj['adjective']['syn']))) 
            //             {
            //                 $stuff = $rsp_obj['adjective']['syn'][self::randomThesaurus('adjective', 'syn', $rsp_obj)];
            //                 if(strlen($wordArray[$i]) > 3)
            //                     $wordArray[$i] = $stuff;

            //             }else if (!(empty($rsp_obj['adjective']['sim']))) {
            //                 $stuff = $rsp_obj['adjective']['sim'][self::randomThesaurus('adjective', 'sim', $rsp_obj)];
            //                 $wordArray[$i] = $stuff;
            //             }else if (!(empty($rsp_obj['adjective']['rel']))) {
            //                 $stuff = $rsp_obj['adjective']['rel'][self::randomThesaurus('adjective', 'rel', $rsp_obj)];
            //                 $wordArray[$i] = $stuff;
            //             }
                        
            //             echo $wordArray[$i];
            //         } else if (array_key_exists("adverb",$rsp_obj)){

            //             echo "<br/> Adverb: <br/>";
            //             if(!(empty($rsp_obj['adverb']['syn']))){
            //                 $stuff = $rsp_obj['adverb']['syn'][self::randomThesaurus('adverb', 'syn', $rsp_obj)];
            //                 $wordArray[$i] = $stuff;
            //             }else if (!(empty($rsp_obj['adverb']['sim']))) {
            //                 $stuff = $rsp_obj['adverb']['sim'][self::randomThesaurus('adverb', 'sim', $rsp_obj)];
            //                 $wordArray[$i] = $stuff;
            //             }else if (!(empty($rsp_obj['adverb']['rel']))) {
            //                 $stuff = $rsp_obj['adverb']['rel'][self::randomThesaurus('adverb', 'rel', $rsp_obj)];
            //                 $wordArray[$i] = $stuff;
            //             }
                        
            //             echo $wordArray[$i];
            //         }
            //         //else {

            //           //  $wordArray[$i] = $stuff;

            //         //}
            //         //$wordArray[$i] = $stuff;
            //     }

                
            // }
            // $articleStuff = implode(" ", $wordArray);
            // return $articleStuff;
            // //header( 'Location: postSpin.php');
        }

        public function randomThesaurus($partOfSpeech, $typeOfPart, $rsp_obj){
                $arrayCount = (count($rsp_obj[$partOfSpeech][$typeOfPart])) - 1;
                return (rand(0, $arrayCount));
        }


    }
    //$_SESSION['spunArticle'] = thesaurusSpin::wordSpin($article);
?>
	
