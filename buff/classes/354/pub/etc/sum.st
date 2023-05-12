"gst sum.st"

"Smalltalk sum program"

Object subclass: Sum [

    Sum class [
        sum: seq [
            |s| s:=0.
            seq do: [ :v | s:=s+v ].
            ^s
        ]
    ]

]

|seq| seq:=#(5 6 1 8 3 7).
(Sum sum: seq) printNl
