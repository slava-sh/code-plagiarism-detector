
program letsgobowlingf;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
 s,s1,a,b,x,y,nod,q,nod1,x1,y1, e:int64;
  i,j:integer;
  nok : longint;
begin
  assign(input, 'gcm.in');
  assign(output, 'gcm.out');
  read(a,b);
  nok:=a*b;
   x1:=a;
 y1:=b;
    s:=abs(b-a);
 repeat
 if a>=b then a:=a- b*(a div b)
 else
 b:=b-a*(b div a);
 until (a=0)or (b=0) ;
 nod:=a+b;
 q:=1;


 repeat

   if nok mod q=0 then begin
      x:=q;
      y:=nok div q;
      s1:=y-x ;
   if ((x mod q=0)or(y mod q=0)) and(  s1<s) then begin
 s:=s1;
 x1:=q;
 y1:=nok div q;
 end;

end;

q:=q+1;
e := round(sqrt(nok));
until q> e;
if x1<=y1 then write(x1,' ',y1)
else
write(y1,' ',x1);

end.
