{$APPTYPE CONSOLE}
type
 mas=record
 b : array [0..262144] of int64;
end;
var
 fq,sq : mas;
 a : array [0..100001] of int64;
 n,m : int64;
 i,k,x,y : longint;
procedure definec(i,d : int64);
begin
 a[i]:=d;
 i:=i+n-1;
 sq.b[i]:=d;
 while i <> 1 do
  begin
   i:=i div 2;
   sq.b[i]:=(sq.b[i*2]+sq.b[i*2+1]);
  end;
end;
procedure defineb(i,d : int64);
begin
 a[i]:=d;
 i:=i+n-1;
 fq.b[i]:=d;
 while i<>1 do
  begin
   i:=i div 2;
   fq.b[i]:=(fq.b[i*2]+fq.b[i*2+1]);
  end;
end;
function getsumc(l,r : int64) : int64;
var
 sum : int64;
begin
 l:=l+n-1;
 r:=r+n-1;
 sum:=0;
 while l<=r do
  begin
   if l mod 2 =1 then
    begin
     sum:=sum+sq.b[l];
     inc(l);
    end;
   if r mod 2 = 0 then
    begin
     sum:=sum+sq.b[r];
     dec(r);
    end;
   l:=l div 2;
   r:=r div 2;
  end;
 getsumc:=sum;
end;
function getsumb(l,r : int64) : int64;
var
 sum : int64;
begin
 l:=l+n-1;
 r:=r+n-1;
 sum:=0;
 while l<=r do
  begin
   if l mod 2=1 then
    begin
     sum:=sum+fq.b[l];
     inc(l);
    end;
   if r mod 2=0 then
    begin
     sum:=sum+fq.b[r];
     dec(r);
    end;
   l:=l div 2;
   r:=r div 2;
  end;
 getsumb:=sum;
end;
begin
 reset(input, 'signchange.in');
 rewrite(output, 'signchange.out');
 read(n);
 for i:=1 to n do
  begin
   read(k);
   if i mod 2 = 1 then
    fq.b[i-1+n]:=k;
   a[i]:=k;
   if i mod 2 = 0 then
    sq.b[i-1+n]:=k;
  end;
 for i:=n-1 downto 1 do
  fq.b[i]:=(fq.b[2*i]+fq.b[2*i+1]);
 for i:=n-1 downto 1 do
  sq.b[i]:=(sq.b[2*i]+sq.b[2*i+1]);
 read(m);
 for i:=1 to m do
  begin
   read(k,x,y);
   if k = 0 then
    begin
     if x mod 2=1 then
      defineb(x,y)
     else
      definec(x,y)
    end
   else
    if x mod 2=1 then
     writeln(getsumb(x,y)-getsumc(x,y))
    else
     writeln(getsumc(x,y)-getsumb(x,y));
  end;
end.
