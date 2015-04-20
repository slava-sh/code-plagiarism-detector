//program gcm;

//{$APPTYPE CONSOLE}

{uses
  SysUtils;

type vector2 = record
u, v : Integer;
end;

var
 a, b, x, y,  i, count, first, second, nod, nok, max, min, curX, curY: Integer;
 current: vector2;
 flag : boolean;


function Evklid(m, n : Integer);
begin
  repeat
  if(m>n) then
   m:=m-n
  else
  if n>m then
  n:=n-m;

  if flag = true then
    if n * m div nod = nok then
     begin
      writeln(n, ' ', m);
      Halt;
    end;

 until m=n;
 nod:=m;
end;

begin
 reset(input, 'gcm.in');
 rewrite(output, 'gcm.out');
 read(a,b);
 first:=a;
 Second:=b;
 Evklid(a, b);
 flag:=true;
 Evklid(a, b);

 {repeat
  if(a>b) then
  begin
   a:=a-b;

  else
  if b>a then
  b:=b-a;
 until a=b; }
 {nod:=a;
 nok:=(first*second) div nod;

 if first >= second then
 begin
    max:=first;
    min:=second;
 end else
 begin
  max:=second;
  min:=first;
 end;

 x:=nod;
 y:=nod;
 i:=1;
 count:=1;

 if min = 1 then
  repeat
    repeat
      i:=i+1;
      x:=i*nod;
      if x * y div nod = nok then
      begin
        writeln(y, ' ', x);
        Halt;
     end;
    until (x * y div nod > nok) or ((x - y) > nod);
    count:=count+1;
    x:=nod*count;
    y:=nod*count;
    i:=1;
  until 2 > 3;

 x:=nod;
 y:=nod;
 i:=1;
 count:=1;
 if nod = nok then
 begin
  writeln(x, ' ', y);
  Halt;
 end;

  repeat
    repeat
      i:=i+1;
      x:=i*nod;
      if x * y div nod = nok then
      begin
        writeln(y, ' ', x);
        Halt;
     end;
    until (x * y div nod > nok) or (x > max);
    count:=count+1;
    x:=nod*count;
    y:=nod*count;
    i:=1;
  until 2 > 3;  }
  //close(output);
//end.}



program gcm;
 
{$APPTYPE CONSOLE}
 
uses
  SysUtils;
var
 a, b, x, y,  i, count, first, second, nod, nok, max, min: Integer;
begin
 reset(input, 'gcm.in');
 rewrite(output, 'gcm.out');
 read(a,b);
 first:=a;
 Second:=b;
 repeat
  if(a>b) then a:=a-b
  else if b>a then b:=b-a;
 until a=b;
 nod:=a;
 nok:=(first*second) div nod;
 
 if first >= second then
 begin
    max:=first;
    min:=second;
 end else
 begin
  max:=second;
  min:=first;
 end;
 
  x:=nod;
 y:=nod;
 i:=1;
 count:=1;
 
 if min = 1 then
  repeat
    repeat
      i:=i+1;
      x:=i*nod;
      if x * y div nod = nok then
      begin
        writeln(y, ' ', x);
        Halt;
     end;
    until (x * y div nod > nok) or ((x - y) > nod);
    count:=count+1;
    x:=nod*count;
    y:=nod*count;
    i:=1;
  until 2 > 3;
 
 x:=nod;
 y:=nod;
 i:=1;
 count:=1;
 if nod = nok then
 begin
  writeln(x, ' ', y);
  Halt;
 end;
 
  repeat
    repeat
      i:=i+1;
      x:=i*nod;
      if x * y div nod = nok then
      begin
        writeln(y, ' ', x);
        Halt;
     end;
    until (x * y div nod > nok) or (x > max);
    count:=count+1;
    x:=nod*count;
    y:=nod*count;
    i:=count;
  until 2 > 3;
  close(output);
end.