program letsgobowling;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  n, m, i, p, v, pv, ps, vs: longint;
  pa, va: array [1..2] of int64;
  k: int64;
begin
  assign(input, 'game.in');
  assign(output, 'game.out');
  readln(n, m);
  readln(pa[1], pa[2]);
  readln(va[1], va[2]);
  for i := 1 to n do begin
    read(k);
    if not((k >= va[1]) and (k <= va[2])) and (k >= pa[1]) and (k <= pa[2]) then
      p := p + 1;
    if not((k >= pa[1]) and (k <= pa[2])) and (k >= va[1]) and (k <= va[2]) then
      v := v + 1;
    if (k >= pa[1]) and (k <= pa[2]) and (k >= va[1]) and (k <= va[2]) then
      pv := pv + 1;
  end;
  for i := 1 to m do
    if pv <> 0 then
      if i mod 2 <> 0 then begin
        ps := ps + 1;
        pv := pv - 1;
      end
      else begin
        vs := vs + 1;
        pv := pv - 1;
      end
    else
      if (i mod 2 <> 0) and (p <> 0) then begin
        ps := ps + 1;
        p := p - 1;
      end
      else
        if v <> 0 then begin
        vs := vs + 1;
        v := v - 1;
      end;

   if ps > vs then writeln('Petya');
   if ps = vs then writeln('Draw');
   if ps < vs then writeln('Vasya');
end.
