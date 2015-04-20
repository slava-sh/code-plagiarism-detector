program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  cnt, n, r, sum, max1, max2, max2i, max1i: int64;
  i: integer;
  vis: array[0..300000] of boolean;
  a: array[0..300000] of int64;

begin
  reset(input, 'sochi.in');
  rewrite(output, 'sochi.out');

  readln(n, r);

  sum := 0;
  cnt := 0;
  for i := 1 to n do begin
    read(a[i]);
    if a[i] >= 3 * r then begin
      inc(cnt);
      sum := sum + a[i];
      vis[i] := true;
    end;
  end;

  max1 := 0;
  max2 := 0;

  for i := 1 to n do begin
    if not vis[i] then begin
      if (a[i] > max1) then begin
        max1 := a[i];
        max1i := i;
      end;

    end;
  end;

  vis[max1i]  := true;

  for i := 1 to n do begin
    if not vis[i] then begin
      if not (i = max1i) then begin
        max2 := a[i];
        max2i := i;
      end;

    end;
  end;

  vis[max2i] := true;

  if max1 <> 0 then inc(cnt);
  if max2 <> 0 then inc(cnt);

  sum := sum + max1 + max2;
  writeln(sum - 2 * r * (cnt - 1)); 

end.
