// Nim sum program
// https://nim-lang.org/documentation.html

proc sum(arr: var array[int]): int =
  var s=0
  for v in arr: 
    s=s+v
  return s

var arr=[5,6,1,8,3,7]
echo sum(arr)
