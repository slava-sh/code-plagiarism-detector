var
  f1:text;
  a, N, i, count:integer; 
begin
assign(f1,'chess.in');
reset(f1);
readln(f1, N);
for i:=1 to N do begin 
  read(f1, a);
  if(a<i) then break;
  count:=count+1;
end;
close(f1);
assign(f1,'chess.out');
rewrite(f1);
writeln(f1, count);
for a:=1 to count do 
  writeln(f1, a,' ', a);
close(f1);
end.