var
a,b,x,y,m,xm,ym,i:integer;

function nod(a,b:integer):integer;
var
i,n:integer;
begin
  for i:=1 to (a*b div 2) do
  begin
   if(a mod i=0) and (b mod i=0) then
   begin
     n:=i;
   end;
  end;
  nod:=n;
end;

begin
  assign(input, 'gcm.in');
  assign(output, 'gcm.out');
  read(input, a);
  read(input, b);
  xm:=a;
  ym:=b;
  m:=abs(a-b);
  for i:=a to (a*b) div 2 do
  begin
    if(a*b mod i)=0 then
    begin
    if (a*b div i)<i then
    begin
     x:=a*b div i;
     y:=i;
    end
    else
    begin
     y:=a*b div i;
     x:=i;
    end;
   end;
   if (abs(x-y)<m) and (nod(x,y)=nod(a,b)) then
   begin
      m:=abs(x-y);
      ym:=y;
      xm:=x;
    end;
   end;
  write(output, xm, ' ', ym)
end.