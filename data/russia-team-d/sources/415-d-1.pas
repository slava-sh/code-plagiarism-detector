var min,p:longint;
    k,i,j,n:longint;
begin
assign(input,'fence.in'); reset(input);
assign(output,'fence.out'); rewrite(output);
readln(n,k);
p:=k div n;
read(j); min:=j;
for i:=2 to n do begin
    read(j);
    if j<min then min:=j;
    end;
if p<min then write(p)
         else write(min);
end.
