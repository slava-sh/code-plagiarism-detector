program graph;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var q,i,j,n,m,kol,r,modi:longint;
    x,y,c,uk:array[1..1600000] of longint;
    queue:array[0..12,0..500000] of longint;
    used:array[1..500000] of boolean;
    d:array[1..500000] of longint;
procedure qsort(l,r:longint);
var i,j,p,q:longint;
begin
   randomize;
   i:=l;
   j:=r;
   p:=x[random(r-l)+l];

   while i<=j do
     if x[i]<p then
       inc(i)
     else
       if x[j]>p then
         dec(j)
       else
       begin
          q:=x[i];
          x[i]:=x[j];
          x[j]:=q;

          q:=y[i];
          y[i]:=y[j];
          y[j]:=q;

          q:=c[i];
          c[i]:=c[j];
          c[j]:=q;

          inc(i);
          dec(j);
       end;
   if i<r then
     qsort(i,r);
   if j>l then
     qsort(l,j);
end;
function min(a,b:longint):longint;
begin
  if a<b then min:=a
  else min:=b;
end;
begin
   reset(input,'graph.in');
   rewrite(output,'graph.out');
   read(n,m);

   for i:=1 to m do
   begin
     read(x[i],y[i],c[i]);
     x[i+m]:=y[i];
     y[i+m]:=x[i];
     c[i]:=12 div c[i];
     c[i+m]:=c[i];
   end;
   m:=m*2;
   qsort(1,m);
   for i:=1 to m do
    if uk[x[i]]=0 then
     uk[x[i]]:=i;
   kol:=1;
   for i:=1 to n do
    d[i]:=maxlongint div 2;
   d[1]:=0;
   queue[0,1]:=1;
   queue[0,0]:=1;
   i:=0;
   while kol>0 do
   begin
      q:=queue[i,0];
      for j:=q downto 1 do
      begin
        r:=uk[queue[i,j]]-1;
        if (uk[queue[i,j]]<>0) and (used[queue[i,j]]=false) then
         repeat
           inc(r);
           if d[y[r]]>d[x[r]]+c[r] then
           begin
            inc(kol);
            d[y[r]]:=d[x[r]]+c[r];
            modi:=d[y[r]] mod 13;
            queue[modi,0]:=queue[modi,0]+1;
            queue[modi,queue[modi,0]]:=y[r];
           end;
         until (r>=m) or (x[r]<>x[r+1]);
        dec(kol);
        used[queue[i,j]]:=true;
        dec(queue[i,0]);
      end;
      i:=(i+1) mod 13;
   end;

   for i:=2 to n do
    writeln(d[i]/12:0:8);
   close(input);
   close(output);
end.
