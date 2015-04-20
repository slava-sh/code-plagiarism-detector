var l,r,x:array[1..1000]of longint; 
qi:longint;
answ:int64;
n,m,i,j:integer;
begin
assign(input, 'dunes.in');
assign(output, 'dunes.out');
reset(input);
rewrite(output);
readln(n,m);
for i:=1 to n do
 readln(l[i],r[i],x[i]);
for i:=1 to m do
begin
readln(qi);
answ:=0;
for j:=1 to n do
 if (l[j]<=qi)and(r[j]>=qi) then 
  if ((qi-l[j]) mod 2 = 0) then answ:=answ+x[j]
  else answ:=answ-x[j];
writeln(answ);
end;
close(input);
close(output);
end.