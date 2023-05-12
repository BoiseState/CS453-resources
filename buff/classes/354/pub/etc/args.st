"gst args.st"

"Smalltalk multi-argument class/static sum method"

Object subclass: Sum [

    Sum class [
        sum: seq count: n [
            |s i|
	    s:=0.
	    i:=n.
            seq do: [ :v |
	       (i>0)
	           ifTrue: [ s:=s+v. i:=i-1 ]
	    ].
            ^s
        ]
    ]

]

|seq| seq:=#(5 6 1 8 3 7).
(Sum sum: seq count: 3) printNl
