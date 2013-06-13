--Ryan Draper
--HW4
--Feb. 19 2013
--CS 326

minL :: (Ord a) => [a] -> a
minL [] = error "empty list"
minL [x] = x
minL (x : xs) 
	|x < minL xs = x
	|otherwise = minL xs

myRev :: [a] -> [a]
myRev [] = []
myRev (x:xs) = (myRev xs) ++ [x]

myLen :: Num a1 => [a] -> a1
myLen [] = 0
myLen (_:xs) = 1 + myLen xs

myElem :: Eq a => a -> [a] -> Bool
myElem n [] = False
myElem n (x:xs)
	|n == x = True
	|otherwise = myElem n xs

myElems :: Eq a => [a] -> [a] -> Bool    
myElems [] ys = False
myElems [x] ys = myElem x ys
myElems (x:xs) ys 
	|myElem x ys && myElems xs ys = True
	|otherwise = False

myRemElem :: Eq a => a -> [a] -> [a]
myRemElem y [] = []
myRemElem y (x:xs) 
	|not(myElem y (x:xs)) = x:xs
	|y == x = myRemElem y xs
	|otherwise = x : myRemElem y xs	

myRepl :: Eq a => (a, a) -> [a] -> [a]
myRepl (a,b) [] = []
myRepl (a, b) (x:xs) 
	|not(myElem a (x:xs)) = (x:xs)
	|a /= x = x : myRepl (a,b) xs
	|otherwise = b : myRepl (a,b) xs

mySub :: Eq a => [(a, a)] -> [a] -> [a]
mySub [] xs = xs
mySub (a:as) xs = mySub as  (myRepl a xs)

myElemSum :: (Eq a, Num a) => a -> [a] -> a
myElemSum y [] = 0
myElemSum y (x:xs) 
	|y == x = x + myElemSum y xs
	|otherwise = myElemSum y xs

myGet :: (Eq a, Num a) => a -> [t] -> t
myGet i [] = error "empty list"
myGet i (x:xs) 
	|i == 0 = x
	|otherwise = myGet (i-1) xs




