var
ans,e1,r1,e2,r2,e3,r3,s,m,n,i:longint;
aa,bb,cc,h1,h2,e,c,a:array[0..200000]of longint;

procedure swap(var xx,yy:longint);
var zz:longint;
 begin
  zz:=xx;
  xx:=yy;
  yy:=zz;
 end;

procedure up(v:longint);
 begin
  while (v>1)and(h1[v]>h1[v div 2]) do
    begin
     swap(h1[v],h1[v div 2]);
     swap(h2[v],h2[v div 2]);
     v:=v div 2;
    end;
 end;

procedure down(v:longint);
var p:longint;
 begin
  while true do
    begin
     if v*2>s then exit;

     p:=v;

     if (h1[v]<h1[v*2]) then p:=v*2;

     if (v*2<s)and(h1[v*2+1]>h1[p]) then p:=v*2+1;

     if p=v then exit;

     swap(h1[v],h1[p]);
     swap(h2[v],h2[p]);
     v:=p;
    end;
 end;

procedure del;
 begin
  swap(h1[1],h1[s]);
  swap(h2[1],h2[s]);
  s:=s-1;
  down(1);
 end;

procedure add(v1,v2:longint);
 begin
  s:=s+1;
  h1[s]:=v1;
  h2[s]:=v2;
  up(s);
 end;

    procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[l+random(r-l)];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

 begin
  read(n);
  for i:=1 to n do read(a[i]);
  sort(1,n);

  m:=0;
  a[0]:=-1;
  for i:=1 to n do
   begin
    if a[i]>a[i-1] then m:=m+1;
    c[m]:=c[m]+1;
    e[m]:=a[i];
   end;

  for i:=1 to m do
   begin
    add(c[i],e[i]);
   end;

  while s>2 do
    begin
     e1:=h1[1]-1;
     r1:=h2[1];
     del;
     e2:=h1[1]-1;
     r2:=h2[1];
     del;
     e3:=h1[1]-1;
     r3:=h2[1];
     del;
         //         writeln(r1,' ',r2,' ',r3,'   ',e1,' ',e2,' ',e3,' ',s);
     ans:=ans+1;

     aa[ans]:=r1;
     bb[ans]:=r2;
     cc[ans]:=r3;

     if e1>0 then
     add(e1,r1);
     if e2>0 then
     add(e2,r2);
     if e3>0 then
     add(e3,r3);
    end;

  writeln(ans);
  for i:=1 to ans do
    begin
     if aa[i]>bb[i] then swap(aa[i],bb[i]);
     if aa[i]>cc[i] then swap(aa[i],cc[i]);
     if bb[i]>cc[i] then swap(bb[i],cc[i]);
     writeln(cc[i],' ',bb[i],' ',aa[i]);
    end;
 end.