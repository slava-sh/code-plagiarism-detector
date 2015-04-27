{$M 20000000}
var
used:array[0..10]of boolean;
a:array[0..1100,0..1100]of byte;
num,b:array[0..1100,0..1100]of longint;
x,y:array[0..2100*1100]of longint;
i1,j1,xx,yy,e,l,si,i,j,n,m:longint;
ch:char;

procedure run(x,y,tt:longint);
 begin
  num[x,y]:=e;
  dec(b[x-1,y]);
  dec(b[x+1,y]);
  dec(b[x,y-1]);
  dec(b[x,y+1]);
  b[x,y]:=-1;

  if (a[x-1,y]=0)then used[num[x-1,y]]:=false;
  if (a[x+1,y]=0)then used[num[x+1,y]]:=false;
  if (a[x,y-1]=0)then used[num[x,y-1]]:=false;
  if (a[x,y+1]=0)then used[num[x,y+1]]:=false;

  if b[x+1,y]=0 then
    begin
     run(x+1,y,1);
     tt:=1;
    end;
  if b[x-1,y]=0 then
    begin
     run(x-1,y,1);
     tt:=1;
    end;
  if b[x,y+1]=0 then
    begin
     run(x,y+1,1);
     tt:=1;
    end;
  if b[x,y-1]=0 then
    begin
     run(x,y-1,1);
     tt:=1;
    end;

  if tt=0 then
    begin
     if (a[x+1,y]=0)and(num[x+1,y]=0) then run(x+1,y,1)
     else
     if (a[x-1,y]=0)and(num[x-1,y]=0) then run(x-1,y,1)
     else
     if (a[x,y-1]=0)and(num[x,y-1]=0) then run(x,y-1,1)
     else
     if (a[x,y+1]=0)and(num[x,y+1]=0) then run(x,y+1,1);
    end;
 end;

procedure gen(x,y:longint);
 begin
  if (num[x,y]=e)and(num[x,y]<>l) then
    begin
     num[x,y]:=l;
     gen(x-1,y);
     gen(x+1,y);
     gen(x,y-1);
     gen(x,y+1);
    end;
 end;

 begin
  readln(n,m);
  for i:=0 to n+1 do
    for j:=0 to m+1 do
      a[i,j]:=1;
  for i:=1 to n do
   begin
    for j:=1 to m do
      begin
       read(ch);
       if ch='.' then a[i,j]:=0;
      end;
    readln;
   end;

  si:=0;
  fillchar(b,sizeof(b),0);

  for i:=1 to n do
    for j:=1 to m do
     if a[i,j]=0 then
       begin
        b[i,j]:=4-a[i-1,j]-a[i+1,j]-a[i,j-1]-a[i,j+1];
        if b[i,j]=0 then
          begin
           writeln(-1);
           halt(0);
          end;
       end;

  for i:=1 to n do
    for j:=1 to m do
     if a[i,j]=0 then
     if num[i,j]=0 then
      begin
       e:=e+1;
       if e>10 then e:=10;
       fillchar(used,sizeof(used),true);
       run(i,j,0);
       used[e]:=true;
       l:=0;
       while not used[l] do l:=l+1;

       gen(i,j);
      end;

  for i:=1 to n do
   begin
    for j:=1 to m do
     if a[i,j]=1 then write('#')else
      write(num[i,j]);
    writeln;
   end;
 end.
