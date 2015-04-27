{$M 10000000}
uses math;

var h,t,r:longint;
j,size,n,m,i:longint;
draw:boolean;
hg,tg,hh,th:array[0..1000]of longint;
x,y,tt:array[0..100000]of longint;
so:array[0..500,0..500]of longint;
b:array[0..500,0..500]of boolean;

procedure add(xx,yy,px,py:longint);
 begin
  xx:=xx+px;
  yy:=yy+py;

  if (xx=0)and(yy=0) then
    begin
     writeln('Ivan');
     writeln(tt[i]+1);
     halt(0);
    end;

  if xx+yy>r then exit;

  if not b[xx,yy] then
     exit;

  b[xx,yy]:=false;
  inc(size);
  x[size]:=xx;
  y[size]:=yy;
  tt[size]:=tt[i]+1;
 end;

procedure run(xx,yy:longint);
var i:longint;
 begin
  if xx+yy>r then exit;
  so[xx,yy]:=1;
  for i:=1 to n do
    if i>xx then break
    else
     begin
      if so[xx-i+hg[i],yy+tg[i]]=0 then run(xx-i+hg[i],yy+tg[i])
      else if so[xx-i+hg[i],yy+tg[i]]=1 then
        begin
         writeln('Draw');
         halt(0);
        end;
     end;

  for i:=1 to m do
    if i>yy then break
    else
     begin
      if so[xx+hh[i],yy-i+th[i]]=0 then run(xx+hh[i],yy-i+th[i])
      else if so[xx+hh[i],yy-i+th[i]]=1 then
        begin
         writeln('Draw');
         halt(0);
        end;
     end;
  so[xx,yy]:=2;
 end;

function ff(xx,yy:longint):longint;
var i:longint;
 begin
  if xx+yy>r then
    begin
     ff:=0;
     exit;
    end;

  if so[xx,yy]<>0 then
    begin
     ff:=so[xx,yy];
     exit;
    end;

  so[xx,yy]:=0;

  for i:=1 to n do
    if i>xx then break
    else
     begin
      so[xx,yy]:=max(so[xx,yy],ff(xx-i+hg[i],yy+tg[i]));
     end;

  for i:=1 to m do
    if i>yy then break
    else
     begin
      so[xx,yy]:=max(so[xx,yy],ff(xx+hh[i],yy-i+th[i]));
     end;

  so[xx,yy]:=so[xx,yy]+1;

  ff:=so[xx,yy];
 end;

 begin
  read(h,t,r);
  read(n);
  for i:=1 to n do
    read(hg[i],tg[i]);

  read(m);
  for i:=1 to m do
    read(hh[i],th[i]);


  fillchar(b,sizeof(b),true);
  b[h,t]:=false;
  size:=1;
  i:=1;
  draw:=false;
  x[1]:=h;
  y[1]:=t;
  tt[1]:=0;
  while i<=size do
    begin
     for j:=1 to n do
       if j>x[i] then break
                 else
         add(x[i]-j,y[i],hg[j],tg[j]);

     for j:=1 to m do
       if j>y[i] then break
                 else
         add(x[i],y[i]-j,hh[j],th[j]);

     i:=i+1;
    end;

  fillchar(so,sizeof(so),0);

  run(h,t);

  writeln('Zmey');
  fillchar(so,sizeof(so),0);
  writeln(ff(h,t));
 end.
