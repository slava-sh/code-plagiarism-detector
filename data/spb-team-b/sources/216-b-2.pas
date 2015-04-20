var i,j,n,z,sum,w,e,q:integer;
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
  m[i,j]:=1;
  end;

end;
q:=0;
sum:=1;
  while (sum>0) do begin
  q:=q+1;
  for i:=1 to n do begin
  m[i,q]:=0;
  m[q,i]:=0;
  sum:=0;
  for w:=1 to n do
    for e:=1 to n do
      sum:=sum+m[w,e];
  end;
  end;
writeln(q);
i:=0;
for i:=1 to q do
writeln(i, ' ',i);
close(input);
close(output);
ENd.
