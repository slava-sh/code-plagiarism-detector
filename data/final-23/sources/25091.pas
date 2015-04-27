uses Math;
type t=array [0..300000] of longint;
var c1,c2:char;
    tree,tree1,a:t;
    xx,x,y,z,n1,n,l,r:longint;
    m,i,k:longint;




procedure build;
var st,k,i:longint;
begin
  k:=0;
  st:=1;
  while st<n do
    begin
      st:=st*2;
      k:=k+1;
    end;
  n:=st;
  for i:=n to 2*n-1do
    begin
      if i mod 2=0 then tree[i]:=a[i-n+1] else tree[i]:=-a[i-n+1];
      if i mod 2=1 then tree1[i]:=a[i-n+1] else tree1[i]:=-a[i-n+1];
    end;
  for i:=n-1 downto 1 do
   begin
     tree[i]:=tree[2*i]+tree[2*i+1];
     tree1[i]:=tree1[2*i]+tree1[2*i+1];
   end;
end;


procedure update(i:longint; a:longint);
var j:longint;
begin
  j:=n+i-1;
  tree[j]:=a;
  while j<>0 do
    begin
      j:=j div 2;
      tree[j]:=tree[2*j]+tree[2*j+1];
    end;
end;

procedure update1(i:longint; a:longint);
var j:longint;
begin
  j:=n+i-1;
  tree1[j]:=a;
  while j<>0 do
    begin
      j:=j div 2;
      tree1[j]:=tree1[2*j]+tree1[2*j+1];
    end;
end;




function getsum( v,l,r,a,b:longint):longint;
begin
  if (l>=a) and (r<=b) then getsum:=tree[v] else
  if (r<a) or (l>b) then getsum:=0 else
  getsum:=getsum(v*2,l,(l+r)div 2,a,b) + getsum(v*2+1,(l+r)div 2+1,r,a,b);
end;

function getsum1(v,l,r,a,b:longint):longint;
begin
  if (l>=a) and (r<=b) then getsum1:=tree1[v] else
  if (r<a) or (l>b) then getsum1:=0 else
  getsum1:=getsum1(v*2,l,(l+r)div 2,a,b) + getsum1(v*2+1,(l+r)div 2+1,r,a,b);
end;


begin
  assign(input,'signchange.in');
  assign(output,'signchange.out');
  reset(input);
  rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  build;
  read(m);

  for i:=1 to m do
    begin
      read(x,y,z);
      if x=0 then
        begin
          if a[y]=tree[y+n-1]  then
            begin
              update(y,z);
              update1(y,-z);
              a[y]:=z;
            end else
            begin
              update(y,-z);
              update1(y,z);
              a[y]:=z;
            end;
        END else
        begin
          if a[y]=tree[y+n-1] then
            begin
              xx:=getsum(1,n,2*n-1,y+n-1,z+n-1);
              writeln(xx);

            end else
            begin
              xx:=getsum1(1,n,2*n-1,y+n-1,z+n-1);
              writeln(xx);
            end;
        end;
    end;

  close(input);
  close(output);
end.
