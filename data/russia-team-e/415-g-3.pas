var m,n,min,max:int64;
begin
assign(input,'prizes.in');
reset(input);
assign(output,'prizes.out');
rewrite(output);
readln(n,m);
if n<m then begin
                min:=n;
                max:=m;
                end
       else begin
                min:=m;
                max:=n;
                end;
if min=1 then
        if max>3 then writeln(((max-3) div 4)+1) else writeln(max div 3)else
if min>=2 then
        if min>3 then writeln(((min-3) div 4)+1) else writeln(min div 3) else
writeln('0');
end.
