program Signchange;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const size=131072;
type tarr=array[1..2*size] of integer;
var n,m,i,v,l,r:integer;
    tree1,tree2,a:tarr;
procedure init(var tree:tarr;const st:integer);
var i,j:integer;
begin
  fillchar(tree,sizeof(tree),0);
  i:=st;
  j:=1;
  while i<=n do
    begin
      tree[j+size-1]:=a[i];
      inc(j);
      inc(i,2);
    end;
  for i:=size-1 downto 1 do
    tree[i]:=tree[2*i]+tree[2*i+1];
end;
function GetSum(const tree:tarr;l,r:integer):integer;
begin
  inc(l,size-1);
  inc(r,size-1);
  Result:=0;
  while l<=r do
    begin
      if l mod 2=1
        then begin
          inc(Result,tree[l]);
          inc(l);
        end;
      if r mod 2=0
        then begin
          inc(Result,tree[r]);
          dec(r);
        end;
      if l>r
        then break;
      l:=l div 2;
      r:=r div 2;
    end;
end;
procedure modify(var tree:tarr;i,x:integer);
begin
  inc(i,size-1);
  tree[i]:=x;
  while i>1 do
    begin
      i:=i div 2;
      tree[i]:=tree[2*i]+tree[2*i+1];
    end;
end;
begin
  assign(input,'signchange.in');
  assign(output,'signchange.out');
  reset(input);
  rewrite(output);
  read(n);
  for i:=1 to n do
    read(a[i]);
  init(tree1,1);
  init(tree2,2);
  read(m);
  for i:=1 to m do
    begin
      read(v,l,r);
      if v=0
        then begin
          if l mod 2=0
            then modify(tree2,l div 2,r)
            else modify(tree1,l div 2+1,r);
        end
        else begin
          if l mod 2=0
            then writeln(GetSum(tree2,l div 2,r div 2)-GetSum(tree1,l div 2+1,r div 2+r mod 2))
            else writeln(GetSum(tree1,l div 2+1,r div 2+r mod 2)-GetSum(tree2,l div 2+1,r div 2));
        end;
    end;
  close(input);close(output);
end.
