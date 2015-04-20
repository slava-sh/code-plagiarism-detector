Var
  m, n: integer;
  lp, rp, lv, rv: integer;
  a: array[1..100000] of integer;
  pos:  array[1..100000] of -1..3;//possibilities
                                  //-1 если уже кидали и попали
                                  //0 никто не может попасть
  x: integer;
  typ: -1..1;// 1 - Petya
             //-1 - Vasya
  to_shout: -1..3;           
  to_find: integer;
  pointPetya, pointVasya: integer;
begin
  assign(input, 'game.in');
  assign(output, 'game.out');
  reset(input);
  rewrite(output);
  readln(input, n, m);
  readln(input, lp, rp);
  readln(input, lv, rv); 
  for x:=1 to n do
  begin
    read(input, a[x]);
    pos[x] := 0;  
    if ((a[x] >= lp) and (a[x] <= rp)) then
    begin
      pos[x] := pos[x] + 1;
    end;
    if ((a[x] >= lv) and (a[x] <= rv)) then
    begin
      pos[x] := pos[x] + 2;
    end;  
  end;
  typ := -1;
  while m > 0 do
  begin
    typ := typ*(-1);
    to_shout:=0;
    for x:=1 to n do//первая обработка, двойное совпадение
    begin
      if pos[x] = 3 then
      begin
        to_shout:=x;
        pos[x] := -1;
        break;
      end;
    end;
    if to_shout = 0 then //вторая обработка, только своё совпадение
    begin
      if typ = 1 then to_find := 1;
      if typ = -1 then to_find := 2;
      for x:=1 to n do
      begin
        if pos[x] = to_find then
        begin
          to_shout:=pos[x];
          pos[x] := -1;
          break;
        end;
      end;
    end;
    if to_shout <> 0 then 
    begin
      if typ = 1 then pointPetya := pointPetya + 1;
      if typ = -1 then pointVasya := pointVasya + 1;
    end;
    m:=m-1;
    if(abs(pointPetya-pointVasya)>((m div 2)+1)) then break;
  end;
  
  close(input);
  if pointPetya > pointVasya then write(output, 'Petya');
  if pointPetya = pointVasya then write(output, 'Draw');
  if pointPetya < pointVasya then write(output, 'Vasya');
  close(output);
  //writeln(pointPetya, pointVasya);
end.