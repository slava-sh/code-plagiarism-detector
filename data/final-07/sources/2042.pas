{$M 20000000}
var
mm,tt,m,n,i:longint;
xx,yy,x,y:array[0..300000]of longint;

    procedure sort(l,r: longint);
      var
         i,j,xx,yy,zz: longint;
      begin
         i:=l;
         j:=r;
         tt:=l+random(r-l);
         xx:=x[tt];
         zz:=y[tt];
         repeat
           while (x[i]<xx)or((x[i]=xx)and(y[i]<zz)) do
            inc(i);
           while (xx<x[j])or((xx=x[j])and(zz<y[j])) do
            dec(j);
           if not(i>j) then
             begin
                yy:=x[i];
                x[i]:=x[j];
                x[j]:=yy;
                yy:=y[i];
                y[i]:=y[j];
                y[j]:=yy;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

procedure gen(l,r:longint);
 begin
  if l>=r then exit;

  gen(l,(l+r) div 2);
  gen((l+r) div 2+1,r);

  for i:=l to r do
    begin
     m:=m+1;
     xx[m]:=x[(l+r) div 2];
     yy[m]:=y[i];
    end;
 end;

 begin
{  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);}
  read(n);
  for i:=1 to n do
    read(x[i],y[i]);

  sort(1,n);

  m:=n;
  for i:=1 to n do
    begin
     xx[i]:=x[i];
     yy[i]:=y[i];
    end;
  gen(1,n);

  x:=xx;
  y:=yy;

  sort(1,m);

  mm:=0;
  x[0]:=-1000000001;
  for i:=1 to m do
    if (x[i]<>x[i-1])or(y[i]<>y[i-1]) then
      begin
       mm:=mm+1;
       xx[mm]:=x[i];
       yy[mm]:=y[i];
      end;


  writeln(mm);
  for i:=1 to mm do writeln(xx[i],' ',yy[i]);
 end.