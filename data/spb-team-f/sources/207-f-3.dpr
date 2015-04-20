program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var a,b,z,x,y,i,j,d:int64;   {111111111111111111111111111111111111111}
sq,zz :extended;

{
function nod(n,k:int64):int64;
var i: int64;
Begin
  if n<k then begin a:=n; b:=k; end
  else begin b:=n; a:=k; end;        // a < b
  i:=a;
  while i>1 do
  begin
  if (b mod i= 0)and (a mod i= 0) then break;
  i:=i-1;
  end;

  nod := i;
End;
}


function nod(n,k:int64):int64  ;
Begin
  while (n>0)and(k>0) do
  begin
    if n<k then k:=k mod n
    else n:= n mod k;
  end;
  if n=0 then nod:=k
  else nod:=n;
End;


{
function nok(n,k:int64):int64;
var i: int64;
Begin
  nok:=(n div nod(n,k) )*k;
End;
}



begin
  assignfile (input, 'gcm.in');
  assignfile (output, 'gcm.out');

  readln(a,b);
  d:= nod(a,b);
  z:=(a div d)*(b div d);
  zz:=z;
  sq:=sqrt(zz);
  i:=round(sq);
  while true do
  begin
    if (z mod i = 0)and(nod(i,z div i)= 1) then break;
    i:=i-1;
  end;

  j:=z div i;

  x:=d*i;
  y:=d*j;

  writeln(x,' ',y);

  close (input);
  close (output);
end.
