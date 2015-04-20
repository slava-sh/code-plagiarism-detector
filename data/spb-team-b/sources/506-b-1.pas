program b;
var i,ai,k,n: integer;
begin
assign(input,'chess.in');
assign(output,'chess.out');
reset(input);
rewrite(output);
readln(n);
for i:=1 to n do begin
read(ai);
if ai>=i then inc(k);
end;
        writeln(k);
        for i:=1 to k do
        writeln(i,' ',i);
close(input);
close(output);
end.