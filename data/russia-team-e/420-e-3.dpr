program e;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type mascode = array[1..200, -1..200] of string;

var a:mascode;
    s,numb,oper:string;
    n,m,k,i,j,a1,b1:longint;

function check(s1,s2:string):boolean;
var i:longint;
    p:boolean;
begin
  i:=1;
  p:=true;
  while (i<=length(s1)) and p do
  begin
    if (s1[i] <> s2[i]) then p:=false;
    inc(i);
  end;

  check:=p;
end;

function findoper(k:longint; s:string):string;
var
   i,qwe:longint;
   p:string;
begin
  p:='-';
  i:=1;
  delete(s,1,length(a[k,-1]));
  qwe:=strtoint(a[k,0]);
  while (i<=qwe) and (p='-') do
  begin
    if check(a[k,i],s) then p:=a[k,i];
    inc(i);
  end;
  findoper:=p;
end;

function getNumb(s:string):string;
begin
  case length(s) of
  3: getNumb:=s;
  4: getNumb:=copy(s,1,2)+'-'+copy(s,3,2);
  5: getNumb:=copy(s,1,3)+'-'+copy(s,4,2);
  6: getNumb:=copy(s,1,2)+'-'+copy(s,3,2)+'-'+copy(s,5,2);
  7: getNumb:=copy(s,1,3)+'-'+copy(s,4,2)+'-'+copy(s,6,2);
  end;
end;

begin
  reset(input, 'numbers.in');
  rewrite(output, 'numbers.out');
  readln(n);
  for i:=1 to n do
  begin
//    readln(a[i,-1], a[i,0]);
    readln(a1,b1);
    a[i,-1]:=inttostr(a1);
    a[i,0]:=inttostr(b1);
    for j:=1 to strtoint(a[i,0]) do readln(a[i,j]);
  end;

  readln(m);
  for i:=1 to m do
  begin
    readln(s);
    j:=1;
    while (j<=n) do
    begin
      if check(a[j,-1],s) then
      begin
        //writeln('>>',a[j,-1],'<<');
        oper:=findoper(j,s);
        if oper<>'-' then begin
                          numb:=s;
                          delete(numb, 1, length(a[j,-1]));
                          delete(numb, 1, length(oper));
                          numb:=getNumb(numb);
                          if ((numb[1]<>'0') and (a[j,-1][1]<>'0')) and (oper[1]<>'0') then
                          begin
                            writeln('+',a[j,-1],'(',oper,')',numb);
                            j:=n+2;
                            end;
                          end;

      end;
      inc(j);
    end;
    if (j>n) AND (j<>n+3) then writeln('Incorrect');
  end;
end.
