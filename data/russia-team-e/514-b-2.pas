{$mode delphi}
var
n,mind,i,j,na,nb:integer;
an:int64;
a:array[1..400000] of integer;
begin
assign(input,'che.in');
assign(output,'che.out');
reset(input);
rewrite(output);

read(n,mind);
for i:=1 to n do

        read(a[i]);
na:=1;
nb:=1;
for na:=1 to n do
        begin
        while (a[nb]-a[na]<=mind) and (nb<=n) do inc(nb);
        an:=an+n-(nb)+1;
        end;
write(an);
close(input);
close(output);
end.
