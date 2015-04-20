{$mode delphi}
var
a,b:integer;
function min(a,b:integer):integer;
        begin
        if a<b then min:=a
        else min:=b;
        end;
begin
assign(input,'prizes.in');
assign(output,'prizes.out');
reset(input);
rewrite(output);
read(a,b);
if min(a,b)=1 then
     write((a+b) div 4)
else
        begin
        if min(a,b)=2 then
                write(0)
                else
                        if min(a,b)>2 then
                                write(1);
        end;

close(input);
close(output);
end.
