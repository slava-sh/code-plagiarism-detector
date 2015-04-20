var n, i, s: integer;
a: array [1..100] of integer;
begin
assign(input,'chess.in');
reset(input);
assign(output,'chess.out');
rewrite(output);
readln(n);
for i := 1 to n do
read(a[i]);
s:=0;
for i := 1 to n do
if(a[i]>s) then
s:=s+1
else
break;
writeln(s); 
for i:= 1 to s do
writeln(i,' ',i);
end.