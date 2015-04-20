program p_1;
var
a, b, k, n, i :integer;
begin
assign (input, 'abcd.in');
assign (output, 'abcd.out');
reset (input);
rewrite (output);
readln (k);
for i:=1 to k do
begin
readln (n);
a:=n div 100;
b:=n mod 100;
if (((a*a + b*b)mod 7)=1) then
writeln ('YES')
else writeln ('NO');
end;
close (input);
close (output);
end.
