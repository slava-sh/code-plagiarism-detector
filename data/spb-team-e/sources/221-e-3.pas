var
  l1, l2, r1, r2: int64;
  n, m, i, count1, count2, count3, Ptime, Vtime: integer;
  t: boolean;
  f1: text;
  h: array[1..100000] of int64;

begin
  assign(f1, 'game.in');
  reset(f1);
  readln(f1, n, m);
  readln(f1, l1, r1);
  readln(f1, l2, r2);
  for i := 1 to n do 
    read(f1, h[i]);
  close(f1);
  for i := 1 to n do 
  begin
    if((h [i] <= r1) and (h[i] >= l1)) then count1 := count1 + 1;
    if((h [i] <= r2) and (h[i] >= l2)) then count2 := count2 + 1;
    if((h [i] <= r2) and (h[i] >= l2) and (h[i] <= r1) and (h[i] >= l1)) then count3 := count3 + 1;
  end;
  t := TRUE;
  for i := 1 to m do 
  begin
    if(count3 > 0) then begin
      count3 := count3 - 1;
      count1 := count1 - 1;
      count2 := count2 - 1;
      if(t = TRUE) then Ptime := Ptime + 1;
      if(t = FALSE) then Vtime := Vtime + 1;
    end
    else begin
      if(t = TRUE) and (count1 > 0) then begin count1 := count1 - 1; Ptime := Ptime + 1; end;
      if(t = FALSE) and (count2 > 0) then begin count2 := count2 - 1; Vtime := Vtime + 1; end;
    end;
    t := not t;  
  end;
  assign(f1, 'game.out');
  rewrite(f1);
  if(Ptime>Vtime)then writeln(f1,'Petya');
  if(Ptime<Vtime)then writeln(f1,'Vasya');
  if(Ptime=Vtime)then writeln(f1,'Draw');
  close(f1);
end.