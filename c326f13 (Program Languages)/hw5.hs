
data List a = Nil | Node a (List a) deriving(Show, Eq)

insert :: a -> List a -> List a
insert x Nil = Node x Nil
insert x (Node y al) = Node y (insert x Nil)