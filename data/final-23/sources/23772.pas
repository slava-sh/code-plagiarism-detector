program signchange;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  rmq: array[0..400000] of integer;
  n, i, j, k, l, m, x: integer;

procedure add(i, x: integer);
var l, r, m, id: integer;
begin
  l := 1;
  r := n;
  id := 1;
  while l < r do begin
    m := (l + r) shr 1;
    if i > m then begin
      id := (id shl 1) or 1;
      l := m + 1;
    end else begin
      id := id shl 1;
      r := m;
    end;
  end;
  rmq[id] := x;
  if i and 1 = 0 then
    rmq[id] := -rmq[id];
  id := id shr 1;
  while id >= 1 do begin
    rmq[id] := rmq[id shl 1] + rmq[(id shl 1) or 1];
    id := id shr 1;
  end;
end;

function getsum(i, l, r, nl, nr: integer): integer;
var m: integer;
begin
  if (l = nl) and (r = nr) then
    result := rmq[i]
  else begin
    m := (l + r) shr 1;
    if nl > m then
      result := getsum((i shl 1) or 1, m + 1, r, nl, nr)
    else if nr <= m then
      result := getsum((i shl 1), l, m, nl, nr)
    else
      result := getsum((i shl 1) or 1, m + 1, r, m + 1, nr) +
                getsum((i shl 1), l, m, nl, m);
  end;
end;

begin
  reset(input, 'signchange.in');
  rewrite(output, 'signchange.out');


  readln(n);
  for i := 1 to n do begin
    read(x);
    add(i, x);
  end;
  readln(m);
  for i := 1 to m do begin
    read(l, j, x);
    if l = 0 then
      add(j, x)
    else if j and 1 = 0 then
      writeln(-getsum(1, 1, n, j, x))
    else
      writeln(getsum(1, 1, n, j, x));
  end;


  close(input);
  close(output);
end.
