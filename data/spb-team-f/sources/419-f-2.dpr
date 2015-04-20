program letsgobowling;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
 s,s1,a,b,x,y,nok,nod,q,nod1,x1,y1:int64;
  i,j:integer;
begin
  assign(input, 'gcm.in');
  assign(output, 'gcm.out');
  read(a,b);
  nok:=a*b;
   x1:=a;
 y1:=b;
    s:=abs(a-b);
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
      s1:=abs(x-y) ;

 repeat
 if x>=y then x:=x- y*(x div y)
 else
 y:=y-x*(y div x);
 until (x=0)or (y=0) ;
 nod1:=x+y;

 if (nod1=nod) and(  s1<s) then begin
 s:=s1;
 x1:=q;
 y1:=nok div q;
 end;

end;

q:=q+1;
until q>=nok div 2;
if x1<=y1 then write(x1,' ',y1)
else
write(y1,' ',x1);

end.








