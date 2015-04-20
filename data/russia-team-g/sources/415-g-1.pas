var m,n,min,max:longint;
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
if min=1 then writeln(max div 4);
if min=2 then writeln('0');
if min>2 then writeln(max div 4);
end.