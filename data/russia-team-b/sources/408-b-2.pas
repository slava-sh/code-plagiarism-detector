var m:array[1..1000000] of longint;
        a,max,r,i,j,n,x:longint;
begin
assign(input,'che.in');
assign(output,'che.out');
reset(input); rewrite(output);
read(n,r);
max:=0;
for i:=1 to n do
        begin
        read(m[i]);
        end;
a:=0;
for i:=1 to n do
        for j:=i+1 to n do
                if m[j]-m[i]>r then inc(a);
writeln(a);
close(input); close(output);
end.
