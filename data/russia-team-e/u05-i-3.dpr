program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
 var n,d,c,s,i:integer;
begin
assign(input,'sochi.in');
reset(input);
assign(output,'sochi.out');
rewrite(output);
s:=0;
read(n,d);
if (n<>1) then
begin
read(c);
s:=s+c-d;
for i:=2 to n-1 do
begin
read(c);
s:=s+c-2*d;
end;
read(c);
s:=s+c-d;
end else begin
read(c);
s:=c;
end;

writeln(s);

end.
 