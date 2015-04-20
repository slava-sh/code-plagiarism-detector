program gr;
var n,m,ans:longint;

procedure chap(var x,y:longint);
var b:longint;
begin
b:=y;
y:=x;
x:=b;
end;

begin
{assign(input, 'input.txt');
assign(output, 'output.txt');
reset(input);
rewrite(output);}
assign(input, 'prizes.in');
assign(output, 'prizes.out');
reset(input);
rewrite(output);
readln(n,m);
if n>m then chap(n,m);
if n=1 then ans:=(m+1) div 4
else ans:=(n +1) div 4;
writeln(ans);
end.