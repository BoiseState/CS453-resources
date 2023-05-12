// Javascript sum program

function sum(seq) {
    var s=0
    for (var i=0; i<seq.length; i++) 
	s+=seq[i]
    return s
}

var seq=[5,6,1,8,3,7]
console.log(sum(seq))
