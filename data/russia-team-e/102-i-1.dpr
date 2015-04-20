program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  cnt, n, r, sum, max1, max2: int64;
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
      if max1 < a[i] then begin
        max2 := max1;
        max1 := a[i];
        inc(cnt);
      end else begin
        if max2 < a[i] then begin
          max2 := a[i];
          inc(cnt);
        end;
      end;
    end;
  end;

  sum := sum + max1 + max2;
  writeln(sum - 2 * r * (cnt - 1)); 

end.
