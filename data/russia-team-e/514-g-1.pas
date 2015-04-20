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
write((min(a,b)+1) div 4);
close(input);
close(output);
end.
