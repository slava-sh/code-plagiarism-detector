program p_1;
var
i: integer;
a, b, c, x, y, d, k: int64;
begin
assign (input, 'gcm.in');
assign (output, 'gcm.out');
reset (input);
rewrite (output);
read (a);
read (b);
d:=321768;
c:=b;
x:=a;
y:=b;
while (b mod d <>0) and (a mod d <> 0) do
begin
        if (a>c) then
        begin
                if (a mod c = 0) then
                        d:=c
                else
                        a:=a mod c;
        end
        else
        begin
                if (c mod a = 0) then
                        d:=a
                else
                c:=c mod a;
        end;
end;
k:=a*(b div d);
if (a>b) then
begin
        c:=b;
        b:=a;
        a:=c;
end;

if (b-a > 1) then
begin
        if (b mod a = 0) and (a>1) then
        begin
                b:=b div d;
                a:=a div d;
        end;

         begin

         i:=a;

         while(x < y) do
         begin
                if (b mod i = 0) then
                        begin
                                x:=a*i;
                                y:=b div i;
                        end;
                i:=i+1;
         end;
         end;
end;
if x < y then
writeln (x,' ',y)
else
writeln (y,' ',x);
close (input);
close (output);
end.



