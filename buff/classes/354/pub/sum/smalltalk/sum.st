"gst sum.st"

"Smalltalk sum program"

Object subclass: Sum [
    |s|

    "A constructor (e.g., new) must be a class method."
    Sum class [
        new [
            ^super new init
        ]
    ]

    "An initializer (e.g., init) must be an instance method."
    init [
        s:=0
    ]

    sum: seq [
        seq do: [ :v | s:=s+v ].
        ^s
    ]

]

|seq| seq:=#(5 6 1 8 3 7).
|sum| sum:=Sum new.
(sum sum: seq) printNl
