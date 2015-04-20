var i,j,n,z,q:integer;
a: array[1..1000] of integer;
m:array[1..1000, 1..1000] of integer;

BEGIN
assign(input, 'chess.in');
assign(output, 'chess.out');
reset(input);
rewrite(output);
 readln(n);
 for z:=1 to n do
  begin
      read(a[z]);
  end;

for i:=1 to n do
begin
  for j:=1 to a[i] do
  begin
  m[j,i]:=1;
  end;

end;
for i:=1 to n do
        if (m[i,i]=0) then begin  q:=i-1; break; end;
if q=0 then writeln(n) else
writeln(q);

for i:=1 to q do
writeln(i, ' ',i);
close(output);
close(input);
ENd.
