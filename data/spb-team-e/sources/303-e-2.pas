var a,b,x,l1,l2,r1,r2:int64;
    n,i:longint;
    c1,c2,c:int64;
    m1,m2,m:int64;  
begin
   assign(input,'game.in');
   assign(output,'game.out');
   reset(input);
   rewrite(output);
   read(n,m);
   read(l1,r1,l2,r2);
   for i:=1 to n do begin
                       read(x);
                       if (x >= l1) and (x <=r1) and (x>=l2) and(x<=r2) then inc(c)
                       else if (x >= l1) and (x <=r1) then inc(a)
                            else if (x >= l2) and (x <=r2)then inc(b);
                    end;
   if c mod 2 = 1 then c1:=c div 2 + 1
   else c1:=c div 2;
   c2:=c div 2;
   if m mod 2 = 1 then m1:=m div 2 + 1
   else m1:=m div 2;
   m2:=m div 2;
   if (c1 + a >= m1 ) and (c2 + b >= m2) and (m1=m2) then writeln('Draw')
  else  if (c1 + a >= m1 ) and (c2 + b >= m2) and (m1>m2) then writeln('Petya')
   else begin
    if (c1 + a > c2 + b) then writeln ('Petya');
    if (c1 + a < c2 + b) then writeln('Vasya');
    if (c1 + a = c2 + b) then writeln('Draw');    
   end;
   close(input);
   close(output);
end.

