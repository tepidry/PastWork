--Ryan Draper
--CS 326
--Feb 26 2013
--HW 5 Part 2 Heap

data Heap a = Nil | Node a (Heap a) (Heap a) deriving(Show, Eq)

isEmpty :: Heap a -> Bool
isEmpty Nil = True
isEmpty _ = False

size :: Num a => Heap t -> a
size Nil = 0
size (Node _ l r) = 1 + (size l) + (size r)

height :: (Num a, Ord a) => Heap t -> a
height Nil = 0
height (Node _ l r) = 1 + max(height l)(height r)

find :: (Ord a) => a -> Heap a -> Bool
find x Nil = False
find x (Node y l r)
	|x == y = True 
	|x<y = find x l 
	|otherwise = find x r

insert :: (Ord a) => a -> Heap a -> Heap a
insert x Nil = Node x Nil Nil
insert x (Node y l r) 
	|(2^(height l)) - 1 == size l && size l > size r = trickleUp (Node y l (insert x r))  
	|otherwise = trickleUp (Node y (insert x l) r)
  	where 
		trickleUp Nil = Nil
		trickleUp (Node x Nil Nil) = (Node x Nil Nil)
		trickleUp (Node par (Node chl Nil Nil) Nil) 
			|par > chl = (Node chl (Node par Nil Nil) Nil) 
			|otherwise = (Node par (Node chl Nil Nil) Nil)
		trickleUp (Node par (Node chl chll chlr) (Node chr chrl chrr)) 
			|par > chl =  (Node chl (Node par chll chlr) (Node chr chrl chrr))
			|par > chr = (Node chr (Node chl chll chlr) (Node par chrl chrr))
			|otherwise = (Node par (Node chl chll chlr) (Node chr chrl chrr)) 

getMin :: Heap a -> a
getMin Nil = error "Empty Heap!"
getMin (Node ah _ _) = ah

trickleDown :: Ord a => Heap a -> Heap a
trickleDown (Node par Nil Nil) = Node par Nil Nil
trickleDown (Node par (Node chl Nil Nil) Nil)
	| chl < par = (Node chl (Node par Nil Nil) Nil)
	| otherwise = (Node par (Node chl Nil Nil) Nil)
trickleDown (Node par (Node chl chll chlr) (Node chr chrl chrr))
	| chl <= chr && chl < par =  (Node chl (trickleDown (Node par chll chlr)) (Node chr chrl chrr))
	| chr <= chl && chr < par = (Node chr (Node chl chll chlr) (trickleDown (Node par chrl chrr)))
    | otherwise = (Node par (Node chl chll chlr) (Node chr chrl chrr))

deleteMin :: Ord a => Heap a -> Heap a
deleteMin Nil = Nil
deleteMin (Node ah Nil Nil) = Nil
deleteMin ah = trickleDown (rootSwapDelete ah) 
	where rootSwapDelete (Node ah ahl ahr) = deleteLeaf (Node (getLeaf (Node ah ahl ahr)) ahl ahr)

deleteLeaf :: Heap t -> Heap t
deleteLeaf (Node ah Nil Nil) = Nil
deleteLeaf (Node a ahl Nil) = Node a Nil Nil
deleteLeaf (Node a ahl ahr)
    | height ahl > height ahr = Node a (deleteLeaf ahl) ahr
    | otherwise = Node a ahl (deleteLeaf ahr)
    
getLeaf :: Heap t -> t
getLeaf (Node ah Nil Nil) = ah
getLeaf (Node _ ahl ahr)
    | height ahl > height ahr = getLeaf ahl
    | otherwise = getLeaf ahr

buildHeap :: (Ord a) => [a] -> Heap a -> Heap a
buildHeap [] Nil = Nil
buildHeap [] ah = ah
buildHeap (x:xs) ah = buildHeap xs (insert x ah)


heapSort :: Ord a => [a] -> [a]
heapSort [] = []
heapSort (x:xs) = (heapSortHelper [] ah)
	where ah = (buildHeap (x:xs) Nil)

heapSortHelper :: Ord a => [a] -> Heap a -> [a]
heapSortHelper xs Nil = xs
heapSortHelper xs (Node a Nil Nil) = xs ++ [a]
heapSortHelper (xs) ah = heapSortHelper (xs ++ [getMin ah]) (deleteMin ah)


