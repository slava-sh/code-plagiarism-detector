var i,n,r,lo,hi,mid,ans:longint;
m:array [1..300000] of longint;
f1,f2:text;
begin
assign(f1,'che.in');
assign(f2,'che.out');
ans:=0;
reset(f1);
rewrite(f2);
read(f1,n,r);
for i:=1 to n do
read(f1,m[i]);
for i:=1 to n do
        begin
        lo:=0;
        hi:=n + 1;
        mid :=(lo+hi) div 2;
        while lo+1<>hi do
                begin
                if m[i]+r +1 <=m[mid] then
                hi:=mid
                else lo:=mid;
                mid := (lo+hi) div 2;
                end;
        ans:=ans+n-hi + 1;
        end;
writeln(f2,ans);
close(f1);
close(f2);
end.
