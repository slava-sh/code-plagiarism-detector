program p_1;
var
i, ch, n, k :integer;
begin
assign (input, 'chess.in');
assign (output, 'chess.out');
reset (input);
rewrite (output);
readln (n);
i:=0;
read (ch);
while (i<=n)and (i<=ch) do
begin

         i:=i+1;
        read (ch);


end;
writeln (i);
for k:=1 to i do
begin
        writeLn (k,' ',k);
end;
close (input);
close (output);
end.
