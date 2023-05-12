func sum(seq: [Int]) -> Int {
    var s=0
    for v in seq {
        s+=v
    }
    return s
}

let seq=[5,6,1,8,3,7]
print(sum(seq:seq))
