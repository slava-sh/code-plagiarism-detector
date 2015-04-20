program DD;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var

  a:array[1..100000] of longint;
  b:array[-1..100000] of longint;
  n,k,i,min: longint;

procedure qsort(l, r: longint);
  var
    i, j, m, x: longint;
  begin
    i := l;
    j := r;
    m := a[(l + r) div 2];
    while i <= j do begin
      while (a[i] < m) and (i < r) do inc(i);
      while (a[j] > m) and (j > l) do dec(j);
      if i <= j then begin
        x := a[i];
        a[i] := a[j];
        a[j] := x;
        inc(i);
        dec(j);
      end;
    end;
    if i < r then qsort(i, r);
    if j > l then qsort(l, j);
  end;

begin
  assign(input, 'fence.in'); reset(input);
  assign(output, 'fence.out'); rewrite(output);
  readln(n,k);
  for i := 1 to n do read(a[i]);
  qsort(1, n);
  b[-1]:=a[1];
  b[0]:=trunc(k/n);
  for i:=1 to n-1 do
  begin
    b[i]:=trunc((k-a[i])/(n-i));
  end;
  min:=b[-1];
  for i:=0 to n-1 do
  begin
    if b[i]<min then min:=b[i];
  end;
  writeln(min);
end.
 