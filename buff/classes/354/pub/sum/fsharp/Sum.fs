/// F# sum program

let rec sum seq =
    match seq with
    | [] -> 0
    | h::t -> h + sum t

let seq=[5;6;1;8;3;7]
printfn "%i" (sum seq)
