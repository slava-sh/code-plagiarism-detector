program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
  var
  a:array[1..100393] of integer;
  b:array[1..100393] of boolean;
  c:array[1..100393] of boolean;
i,m,n,j,l1,r1,l2,r2,op,ov:longint;
begin
  read(n); read(m);
  read(l1); read(r1);
  read(l2); read(r2);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    if (a[i]<=r1) and(a[i]>=l1) then b[i]:=true else b[i]:=false;
  for i:=1 to n do
    if (a[i] <= r2) and(a[i] >= l2) then
      c[i] := true
    else
      c[i] := false;
  i:=1;
  for i:=1 to n do begin
    for j:=1 to n do
    if (b[j]=c[j]) and (b[j]=true) then begin
      if j mod 2 = 1 then inc(op) else inc(ov);
      dec(m);
      b[j] := False;
      c[j] := False; end;
      if b[i] then begin
       inc(op);
        b[i] := false;
        dec(m);
      end else
       if c[i] then begin
       inc(ov); c[i] := false;dec(m);
       end;
       if (m = 0) then
         break;
   end  ;
       if op > ov then writeln('Petya') else if ov > op then writeln('Vasya') else
       writeln('Draw');

end.
