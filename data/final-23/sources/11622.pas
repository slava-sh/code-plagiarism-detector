program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

const shift=262144;

type iRSQ=record
           value:integer;
           s:integer;
         end;
     mas=array [0..shift*2] of iRSQ;

var n,m,i:integer;
    l,r,x:integer;
    chet,nechet:mas;

Procedure Push(v,l,r:integer; var t:mas);
begin
  if t[v].value=-1 then
    exit;

  t[2*v].value:=t[v].value;
  t[2*v+1].value:=t[v].value;
  t[v].value:=-1;

  t[2*v].s:=((r-l+1)div 2)*t[v*2].value;
  t[2*v+1].s:=((r-l+1)div 2)*t[v*2+1].value;

end;

Function RSQ(l,r,Left,Right,v:integer; var t:mas):integer;
begin
  if (r<Left) or (l>Right)
    then
      begin
        RSQ:=0;
        exit;
      end;
  if (l<=Left) and (Right<=r)
    then
      begin
        RSQ:=t[v].s;
        exit;
      end;
  Push(v,Left,Right,t);

  RSQ:=RSQ(l, r, Left, (Left+Right) div 2, 2*v, t) + RSQ(l, r, (Left+Right) div 2 +1, Right, 2*v+1, t);
end;

Procedure Change(l,r,x,Left,Right,v:integer; var t:mas);
var j,m:integer;
begin
  if (r<Left) or (l>Right)
    then
      exit;
  if (l<=Left) and (Right<=r)
    then
      begin
        t[v].value:=x;
        t[v].s:=(right-left+1)*x;
        exit;
      end;

  Push(v,Left,Right,t);

  m:=(left+right)div 2;
  Change(l, r, x, Left, m, 2*v, t);
  Change(l, r, x, m + 1, Right, 2*v + 1, t);

  t[v].s:=t[2*v].s+t[2*v+1].s;
end;

begin
  reset(input,'signchange.in');
  rewrite(output,'signchange.out');

  readln(n);

  for i:=shift to shift+n-1 do
    begin
      read(x);
      if (i-shift+1) mod 2 = 0 then chet[i].s:=x
                               else chet[i].s:=-x;
      nechet[i].s:=-chet[i].s;
    end;
  for i:=1 to 2*shift do
    begin
      nechet[i].value:=-1;
      chet[i].value:=-1;
    end;
  for i:=shift-1 downto 1 do
    begin
      chet[i].s:=chet[i*2].s+chet[i*2+1].s;
      nechet[i].s:=nechet[i*2].s+nechet[i*2+1].s;
    end;

  readln(m);

  for i:=1 to m do
    begin
      readln(x,l,r);
      if x=0 then
        begin
          if l mod 2 = 0 then
            begin
              Change(l,l,r,1,shift,1,chet);
              Change(l,l,-r,1,shift,1,nechet);
            end
          else
            begin
              Change(l,l,-r,1,shift,1,chet);
              Change(l,l,r,1,shift,1,nechet);
            end;
        end
      else
        begin
          if l mod 2=0 then writeln(RSQ(l,r,1,shift,1,chet))
                       else writeln(RSQ(l,r,1,shift,1,nechet));
        end;
    end;

end.


