var n,i,a,max1,max2,s:longint;
    d:integer;


begin
 assign(input,'sochi.in');
 assign(output,'sochi.out');
 reset(input);
 rewrite(output);
  readln(n,d);
  max1:=d;
  max2:=d;
  s:=0;
  max:=0;
  for i:=1 to n do
   begin
    read(a);
    if a>=3*d then s:=s+a-2*d;
    if (a<3*d) and (a>d) then
                                        if a>max1 then begin
                                                 max2:=max1;
                                                 max1:=a;
                                             end

                                        else if a>max2 then max2:=a ;
    if (a<=d)and(a>max)then max:=a;
   end;
  if s<>0 then  begin
                 if max1>2*d then s:=s+max1-d
                           else s:=s+d;
                 if max2>2*d then s:=s+max2-d
                           else s:=s+d;
                end
  else  if (s+max1+max2-2*d>max)then s:=s+max1+max2-2*d else s:=max;
 writeln(s);

end.
