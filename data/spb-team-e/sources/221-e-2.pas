var
  l1, l2, r1, r2: int64;
  n, m, i, count1, count2, count3: integer;
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
  assign(f1, 'game.out');
  rewrite(f1);
  if (m mod 2 = 0) then begin
    if((m <= count1) and (m <= count2)) then writeln(f1, 'Draw')
    else begin
      count1 := count1 - (count3 div 2);
      count2 := count2 - (count3 - (count3 div 2));
      if(count1 = count2) then writeln(f1, 'Draw');
      if(count2 > count1) then writeln(f1, 'Vasya');
      if(count1 > count2) then writeln(f1, 'Petya');
    end;
  end
  else begin
    if((m <= count1) and (m <= count2)) then writeln(f1, 'Petya')
    else begin
      count1 := count1 - (count3 div 2);
      count2 := count2 - (count3 - (count3 div 2));
      if(count1 >= count2) then writeln(f1, 'Petya');
      if(count2 - count1 = 1) then writeln(f1, 'Draw');
      if(count2 - count1 >= 2) then writeln(f1, 'Vasya');
    end;
  end;
  close(f1);
end.