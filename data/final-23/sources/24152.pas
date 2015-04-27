{$A+,B-,C+,D+,E-,F-,G+,H+,I+,J-,K-,L+,M-,N+,O-,P+,Q+,R+,S-,T-,U-,V+,W-,X+,Y+,Z1}
program Signchange;

{$APPTYPE CONSOLE}

uses
  SysUtils;                      
type tree=array[1..300000]of integer;
var k,n,m,i,l,r,q:integer;
    t:tree;
    a:array[1..100000]of integer;
procedure update(v,x:integer);
begin
  v:=v+(1 shl k)-1;
  t[v]:=x;
  while v>1 do begin
    v:=v div 2;
    t[v]:=t[2*v]+t[2*v+1];
  end;
end;
function rsq(l,r,LL,RR,v:integer):integer;
begin
  if (r<LL)or(RR<l) then
    result:=0 else
    if (l<=LL)and(RR<=r) then
      result:=t[v] else
      result:=rsq(l,r,LL,(RR+LL)div 2,v*2)+rsq(l,r,((RR+LL)div 2)+1,RR,2*v+1);
end;
begin
  reset(input,'signchange.in');
  rewrite(output,'signchange.out');
  readln(n);
  for i:=1 to n do
    read(a[i]);
  k:=0;
  while (1 shl k)<n do
    inc(k);
  for i:=1 to n do
    if i mod 2=0 then begin
      t[i+(1 shl k)-1]:=-a[i];
    end else begin
      t[i+(1 shl k)-1]:=a[i];
    end;
  for i:=n+(1 shl k) to (2 shl k)-1 do begin
    t[i]:=0;
  end;
  for i:=(1 shl k)-1 downto 1 do begin
    t[i]:=t[i*2]+t[i*2+1];
  end;
  readln(m);
  for i:=1 to m do begin
    read(q,l,r);
    if q=0 then begin
      if l mod 2=0 then begin
        update(l,-r);
      end else begin
        update(l,r);
      end;
    end else begin
      if l mod 2=0 then
        writeln(-rsq(l,r,1,(1 shl k),1)) else
        writeln(rsq(l,r,1,(1 shl k),1));
    end;
  end;
end.
