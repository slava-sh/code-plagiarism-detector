program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils, math;
var
  cur1, cur2, cur3, argx : integer;
  n, m, i, x: integer;
  a1, a2, b1, b2 : integer;
  p, v : integer;
  mass, cur: array of integer;
  flag : boolean;
begin
  assignfile(input,'game.in');
  assignfile(output,'game.out');
  flag:= true;
  read(n, m);
  read(a1, b1);
  read(a2, b2);
  setlength(mass, n+1);
  setlength(cur, n+1);
  for i := 1 to n do
    read(mass[i]);
 for i:= 1 to n do
  begin
   if (mass[i] >= a1) and (mass[i] <= b1) then
    cur[i] := 1;
   if (mass[i] >= a2) and (mass[i] <= b2) and (cur[i] = 1) then
    cur[i] := 3;
   if (mass[i] >= a2) and (mass[i] <= b2) and (cur[i] = 0) then
    cur[i] := 2;
  end;
 for i := 1 to n do
  begin
   if cur[i] = 1 then
    inc(cur1);
   if cur[i] = 2 then
    inc(cur2);
   if cur[i] = 3 then
    inc(cur3);
  end;
  if (cur3 <= m) then
    begin
    if cur3 mod 2 = 0 then
      begin
        p:= cur3 div 2;
        v:= cur3 div 2;
      end
      else
      begin
        p:= cur3 div 2 + 1;
        v:= cur3 div 2;
      end;
    end
    else
     begin
        if m mod 2 = 0 then
          begin
            p:= m div 2;
            v:= m div 2;
          end
          else
          begin
            p:= m div 2 + 1;
            v:= m div 2;
          end;
          flag := false;
     end;

  if (flag) then
    if m - cur3 >= cur1 + cur2 then
    begin
      if cur1 > cur2 then
      begin
        inc(p, (cur1 + cur2) div 2);
        inc(v, cur2);
      end
      else
      begin
        inc(p, cur1);
        inc(v, (cur1 + cur2) div 2);
      end;

    end else
    begin
      x:= (m - cur3) div 2;
      if p = v then
      begin
        if cur1 > x + (m - cur3) mod 2 then
          inc(p, x + (m - cur3) mod 2)
        else
          inc(p, cur1);

         if cur2 > x then
          inc(v, x)
        else
          inc(v, cur2);
      end else
      begin
        if cur1 > x then
          inc(p, x)
        else
          inc(p, cur1);

         if cur2 > x + (m - cur3) mod 2 then
          inc(v, x + (m - cur3) mod 2)
        else
          inc(v, cur2);
      end;

    end;


  if p > v then
    writeln('Petya')
  else
    if p < v then
      writeln('Vasya')
    else
      writeln('Draw');









        




end.
