--Ryan Draper
--CS326
--March 7 2013
--Home Work 6

-- file: main.hs
-- skeleton for implementing simple command-line programs
import System.Environment (getArgs)
import Data.Char (toUpper, isUpper)
-- read input file, apply function to input file, display result
interactWith function inputFile = do
	input <- readFile inputFile
	putStrLn (function input)
-- starting point of the program: call mainWith on myFunction
main = do
	args <- getArgs
	case args of
		[input] -> interactWith myFunction input
		_ -> putStrLn "error: exactly one argument needed"
-- replace "id" with the name of your function below
-- function must have type: String -> String
myFunction = 
	remWords
--	toUppercase
--	capitals
	

toUppercase x = map toUpper x

capitals x = unwords (filter (isUpper . head)(words x))

remWord x y = unwords (filter (/= y) (words x)) 

remWords x = foldl (remWord) (head(tail(lines x))) (words(head(lines x)))
