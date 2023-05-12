(* ML sum program *)

let rec sum seq =
    match seq with
    | []   -> 0
    | h::t -> h+sum t;;

let rec sum1 seq =
    if seq=[] then
        0
    else
        List.hd(seq)+sum(List.tl(seq));;

let seq=[5; 6; 1; 8; 3; 7] in
print_int(sum seq);
print_newline();
print_int(sum1 seq);
print_newline();;
