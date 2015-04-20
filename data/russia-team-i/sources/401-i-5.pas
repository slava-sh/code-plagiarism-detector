var n,i,a,max1,max2,s,max:longint;
    d:integer;


begin
  assign(input,'sochi.in');
  assign(output,'sochi.out');
  reset(input);
  rewrite(output);
  readln(n,d);
  max1:=d;
  max2:=d;
  max:=0;
  s:=0;
  for i:=1 to n do
   begin
    read(a);
    if a>=3*d then s:=s+a-2*d;
    if (a<3*d) and (a>d) then if a>max1 then max1:=a
                                        else if a>max2 then max2:=a;
    if (a<=d)and (a>max) then max:=a;
   end;
  if max1>d then max:=max1;
 if s<>0 then
  begin
  if max1>2*d then s:=s+max1-d
            else s:=s+d;
  if max2>2*d then s:=s+max2-d
            else s:=s+d;
  end
  else if max1+max2-2*d>max then s:=max1+max2-2*d else s:=max;
 writeln(s);
end.
