let _ =
  let w = 100000 in
  let h = 100 in
  let sb = Scanf.Scanning.stdib in
  let hl = Scanf.bscanf sb "%d " (fun s -> s) in
  let hr = Scanf.bscanf sb "%d " (fun s -> s) in
  let n = Scanf.bscanf sb "%d " (fun s -> s) in
  let v = Array.make n 0 in
  let b = Array.make n false in
  let u = Array.make w (-1) in
  let d = Array.make w (-1) in
  let res = ref 0 in
  let () =
    for i = 0 to n - 1 do
      let vv = Scanf.bscanf sb "%d " (fun s -> s) in
      let c = Scanf.bscanf sb "%s " (fun s -> s) in
      let a = Scanf.bscanf sb "%d " (fun s -> s) in
      let b = Scanf.bscanf sb "%d " (fun s -> s) in
      let aa = if c = "T" then u else d in
	v.(i) <- vv;
	for j = a to b - 1 do
	  aa.(j) <- i;
	done
    done;
  in
  let solve hl hr u d =
    for i = 1 to 100 do
      Array.fill b 0 n false;
      let y =
	(i - 1) * h +
	  if i mod 2 = 0
	  then h - hr
	  else hr
      in
      let r = ref 0 in
	try
	  for j = 0 to i - 1 do
	    let z = j * h in
	    let x =
	      float_of_int (z + hl) *. float_of_int w /. float_of_int (y + hl)
	    in
	      (*Printf.printf "asd %f  %d %d %d\n" x hl y z;*)
	    let x = int_of_float x in
	    let a = if j mod 2 = 0 then d else u in
	      if a.(x) < 0 || b.(a.(x))
	      then raise Not_found
	      else (
		(*Printf.printf "hit %d %d %d\n" i a.(x) v.(a.(x));*)
		b.(a.(x)) <- true;
		r := !r + v.(a.(x));
	      )
	  done;
	  res := max !res !r;
	with
	  | Not_found -> ()
    done;
  in
    solve hl hr u d;
    solve (h - hl) (h - hr) d u;
    Printf.printf "%d\n" !res
