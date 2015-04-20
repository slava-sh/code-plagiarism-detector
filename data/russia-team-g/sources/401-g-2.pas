uses math;
var a,b:longint;

begin
 assign(input,'prizes.in');
 assign(output,'prizes.out');
 reset(input);
 rewrite(output);
   readln(a,b);
  if (a=2)or(b=2) then writeln(0)
   else if (a=1) or (b=1) then write((max(a,b)+1)div 4)
     else write(1);
end.

