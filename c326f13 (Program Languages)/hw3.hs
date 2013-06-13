myMinL :: Ord a => [a] -> a
myMinL xs = 
	if (null (tail xs))
	then head xs
	else if head xs < (head (tail xs))
	then myMinL (head xs : (drop 2 xs))
	else myMinL (tail xs)

myRev :: [a] -> [a]
myRev xs = if null xs
	   then xs
	   else myRev (tail xs) ++ [head xs]

myLen :: Num a1 => [a] -> a1
myLen xs = 
	if null xs
	then 0
	else 1 + myLen (tail xs)

myElem :: Eq a => a -> [a] -> Bool
myElem x xs = if null xs
			then False
			else head xs == x || myElem x (tail xs) 
	
myElems :: Eq a => [a] -> [a] -> Bool    
myElems xs ys = if null xs 
				then False
				else if null (tail xs)
				then myElem (head xs) ys
				else myElems (tail xs) ys

myRemElem :: Eq a => a -> [a] -> [a]
myRemElem x xs = if not (myElem x xs)
				 then xs
				 else if x == (head xs)
				 then (myRemElem x (tail xs)) 
				 else (head xs) : (myRemElem x (tail xs)) 

myRepl :: Eq a => (a, a) -> [a] -> [a]
myRepl (x, y) xs = if not(myElem x xs)
				   then xs
				   else if x == (head xs)
				   then (y : myRepl (x,y) (tail xs))
				   else (head xs) : myRepl (x,y) (tail xs)

mySub :: Eq a => [(a, a)] -> [a] -> [a]
mySub as xs = if null as 
			  then xs
			  else myRepl (last as) (mySub (init as) xs) 
			  


myElemSum :: (Eq a, Num a) => a -> [a] -> a
myElemSum x xs = if null xs
				 then 0
				 else if head xs == x
				 then myElemSum x (tail xs) + x
				 else myElemSum x (tail xs)

myGet :: (Eq a, Num a1) => a -> [a] -> a1
myGet x xs = if not (myElem x xs)
			 then myLen xs
			 else (1 + myGet x (tail xs))

				 