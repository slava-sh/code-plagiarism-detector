program signchange;

{$APPTYPE CONSOLE}{$R+}{$Q+}

uses
  SysUtils;
const rmqmax=131072;
var rmq:array[1..2*rmqmax-1] of longint;
    n,m:longint;
procedure init;
var i:longint;
begin
 assign(input,'signchange.in');
 assign(output,'signchange.out');
 reset(input);
 rewrite(output);
 read(n);
 for i:=1 to n do
  begin
   read(rmq[i+rmqmax-1]);
   if not odd(i)
    then
     rmq[i+rmqmax-1]:=-rmq[i+rmqmax-1];
  end;   
 read(m);
 for i:=rmqmax-1 downto 1 do
  rmq[i]:=rmq[2*i]+rmq[2*i+1];
end;
procedure Pout;
begin

 close(input);
 close(output);
 halt(0);
end;
procedure update(v:longint);
begin
 if v=0
  then
   exit;
 rmq[v]:=rmq[v*2]+rmq[v*2+1];
 update(v div 2);
end;
procedure Passign(a,b:longint);
begin
 if odd(a)
  then
   rmq[rmqmax+a-1]:=b
  else
   rmq[rmqmax+a-1]:=-b;
 update((rmqmax+a-1) div 2);
end;
function Fgetsum(v,l,r,ll,rr:longint):longint;
begin
 if (r<ll) or(rr<l)
  then
   begin
    result:=0;
    exit;
   end;
 if (l<=ll)and(rr<=r)
  then
   begin
    result:=rmq[v];
    exit;
   end;
 result:=Fgetsum(2*v,l,r,ll,(ll+rr) div 2)+Fgetsum(2*v+1,l,r,(ll+rr) div 2+1,rr);  
end;
procedure getsum(l,r:longint);
begin
 if odd(l)
  then
   writeln(Fgetsum(1,rmqmax-1+l,rmqmax-1+r,rmqmax,rmqmax*2-1))
  else
   writeln(-Fgetsum(1,rmqmax-1+l,rmqmax-1+r,rmqmax,rmqmax*2-1));
end;
procedure proc(t,a,b:longint);
begin
 if t=0
  then
   Passign(a,b)
  else
   getsum(a,b);
end;
procedure solve;
var i,t,a,b:longint;
begin
 for i:=1 to m do
  begin
   read(t,a,b);
   proc(t,a,b);
  end;
end;
begin
 init;
 solve;
 Pout;
end.
