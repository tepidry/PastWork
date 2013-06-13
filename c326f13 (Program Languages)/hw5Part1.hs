
--Ryan Draper
--CS 326
--Feb 26 2013
--HW 5 Part 1 Linked List

data List a = Nil | Node a (List a) deriving(Show, Eq)

insert :: a -> List a -> List a
insert x Nil = Node x Nil
insert x al = Node x al

delete :: (Eq a) => a -> List a -> List a
delete x Nil = Nil
delete x (Node y al)
	|x == y = al 
	|otherwise = Node y (delete x al)

memberOf :: (Eq a) => a -> List a -> Bool
memberOf x Nil = False
memberOf x (Node y al)
	|x == y = True
	|otherwise = memberOf x al

size :: Integral b => List a -> b
size Nil = 0
size (Node y al) = 1 + size al

elementAt :: Integral a => a -> List b -> b
elementAt x Nil = error "Out Of Bounds"
elementAt x (Node y al)
	|x == 0 = y
	|otherwise = elementAt (x-1) al

insertAt :: Integral a => a -> b -> List b -> List b
insertAt 0 x Nil = (Node x Nil) 
insertAt i x Nil
	|i > 0 = error "No such index!"
insertAt i x (Node y al)
	|i == 0 = (Node x (Node y al))
	|otherwise = Node y (insertAt (i - 1) x al)

deleteAt :: Integral a => a -> List b -> List b
deleteAt i (Node y al)
	|i > ((size (Node y al)) - 1) = error "No such index!"
	|i == 0 = al
	|otherwise = Node y (deleteAt (i - 1) al)

appendTo :: List a -> List a -> List a
appendTo Nil bl = bl
appendTo al Nil = al
appendTo al (Node b bl) = appendTo (insertAt (size al) b al) bl    





