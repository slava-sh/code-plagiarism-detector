type 'a heap = {mutable heap : (int * 'a) array;
		mutable heap_len : int;
	       }

let heap_new size el = {heap = Array.make size (0, el);
			heap_len = 0;
		       }

let heap_reset heap =
  heap.heap_len <- 0

let heap_insert heap p el =
  if Array.length heap.heap = heap.heap_len then (
    let new_size = heap.heap_len * 2 in
    let new_heap = Array.make new_size heap.heap.(0) in
      Array.blit heap.heap 0 new_heap 0 heap.heap_len;
      heap.heap <- new_heap;
  );
  let h = heap.heap in
  let pos = ref heap.heap_len in
    while !pos > 0 && fst h.((!pos - 1) / 2) > p do
      let parent = (!pos - 1) / 2 in
	h.(!pos) <- h.(parent);
	pos := parent
    done;
    h.(!pos) <- (p, el);
    heap.heap_len <- heap.heap_len + 1

let heap_get_min heap =
  if heap.heap_len > 0 then
    snd heap.heap.(0)
  else
    raise Not_found

let heap_extract_min heap =
  if heap.heap_len > 0 then
    let h = heap.heap in
    let res = h.(0) in
    let len = heap.heap_len - 1 in
      h.(0) <- h.(len);
      heap.heap_len <- len;
      if len > 0 then (
	let p = fst h.(0) in
	let i = ref 0 in
	let b = ref true in
	  while !b do
	    let l = !i * 2 + 1 in
	    let r = !i * 2 + 2 in
	    let smallest =
	      if l < len && p > fst h.(l)
	      then l
	      else !i
	    in
	    let smallest =
	      if r < len && fst h.(smallest) > fst h.(r)
	      then r
	      else smallest
	    in
	      if smallest <> !i then (
		let tmp = h.(!i) in
		  h.(!i) <- h.(smallest);
		  h.(smallest) <- tmp;
		  i := smallest;
	      ) else
		b := false
	  done
      );
      res
  else
    raise Not_found

let heap_is_empty heap =
  heap.heap_len = 0

let _ =
  let sb = Scanf.Scanning.stdib in
  let n = Scanf.bscanf sb "%d " (fun s -> s) in
  let ht = Hashtbl.create n in
  let _ =
    for i = 0 to n - 1 do
      let x = Scanf.bscanf sb "%d " (fun s -> s) in
	try
	  Hashtbl.replace ht x (Hashtbl.find ht x + 1)
	with
	  | Not_found ->
	      Hashtbl.replace ht x 1
    done;
  in
  let heap = heap_new n (-1) in
    Hashtbl.iter
      (fun r c ->
	 heap_insert heap (-c) r
      ) ht;
  let res = ref [] in
    (try
       while true do
	 let (c1, r1) = heap_extract_min heap in
	 let (c2, r2) = heap_extract_min heap in
	 let (c3, r3) = heap_extract_min heap in
	   let [r1'; r2'; r3'] = List.sort compare [r1; r2; r3] in
	     res := (r3', r2', r1') :: !res;
	     let c1 = c1 + 1 in
	     let c2 = c2 + 1 in
	     let c3 = c3 + 1 in
	       if c1 <> 0 then heap_insert heap c1 r1;
	       if c2 <> 0 then heap_insert heap c2 r2;
	       if c3 <> 0 then heap_insert heap c3 r3;
       done
     with
       | Not_found -> ()
    );
    Printf.printf "%d\n" (List.length !res);
    List.iter
      (fun (a, b, c) ->
	 Printf.printf "%d %d %d\n" a b c
      ) !res
