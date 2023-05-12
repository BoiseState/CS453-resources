// Elixir sum program
// https://hexdocs.pm/elixir/Kernel.html

proc sum(arr: var array[int]): int =
  var s=0
  for v in arr: 
    s=s+v
  return s

var arr=[5,6,1,8,3,7]
echo sum(arr)

# The Enum.each function can be used in place of a for-each loop
Enum.each([1, 2, 3], fn(s) -> IO.puts(s) end)
