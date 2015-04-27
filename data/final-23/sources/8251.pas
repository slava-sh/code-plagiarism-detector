program ZACHET_SIGN;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const k = 2*131072;
var tree:array[0..2*k] of integer;
    n,i,m,l,r,x,typ,sign:integer;
    c:char;
Procedure build;
var
  i:longint;
begin
  For i:=1 to k Do
    tree[k-1+i]:=0;
  for i:=1 to n do
    begin
      read(tree[k-1+i]);
      if i mod 2=0 then tree[k-1+i]:=-tree[k-1+i];
    end;
  For i:=k-1 downto 1 do
    tree[i]:=tree[2*i]+tree[2*i+1];
end;

Procedure add(ind,p:longint);
var
  x,i:longint;
begin
  if ind mod 2=0
    then
      tree[k-1+ind]:=-p
    else
      tree[k-1+ind]:=p;


  x:=(k-1+ind) div 2;
  While (x>0) Do
    begin
      tree[x]:=tree[2*x]+tree[2*x+1];
      x:=x div 2;
    end;
end;


Function get_sum(i, il, ir, l, r : longint):integer;
var
  m:longint;
begin
  if (r < il) or (ir < l) then
    begin
      Result := 0;
      exit;
    end;
  if (il >= l) and (ir <= r) then
    begin
      Result := tree[i];
      exit;
    end;

  m:=(il+ir) div 2;
  Result:=get_sum(2*i,il,m,l,r)+get_sum(2*i+1,m+1,ir,l,r)
end;

begin
  reset(input,'signchange.in');
  rewrite(output,'signchange.out');
  readln(n);
  build;
  readln(m);
  for i:=1 to m do
    begin
      readln(typ,l,r);
      if typ=1 then
        if tree[k-1+l]>=0 then
          begin
            writeln(get_sum(1,1,k,l,r));
          end
        else
          begin
            writeln(-get_sum(1,1,k,l,r));
          end
      else
        add(l,r);
    end;
  close(output);
end.

