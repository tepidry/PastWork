type KeyType = String
type ValueType = Integer
data KVPairType = KVPair KeyType ValueType deriving(Show,Eq)

mystery x [] = []
mystery x (y:ys) 
	|null y = mystery x ys
	|otherwise = (y++x) : mystery x ys