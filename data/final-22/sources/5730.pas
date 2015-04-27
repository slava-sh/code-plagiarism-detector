program graph;

{$APPTYPE CONSOLE}
{$R+,Q+}
uses
  SysUtils,Math;
const
  inf=100000000;
var
  i,z,otv,n,m:integer;
  num,cop,rast:array[1..500001] of integer;
  rebra: array[1..800001,1..3] of integer;
  a,b:array[1..500001] of array of integer;
  ocher: array[1..12] of array of integer;
  head,tail:array[1..12] of integer;

procedure bfs;
var
  i:integer;
begin
  while not( (head[12]=tail[12]) and (head[6]=tail[6]) and (head[3]=tail[3]) and (head[4]=tail[4]) ) do begin
    if not( (head[12]=tail[12])) then begin
      inc(head[12]);
      for i:=1 to num[ocher[12,head[12]]] do begin
        if  (rast[ocher[12,head[12]]]+b[ocher[12,head[12]],i]<rast[a[ocher[12,head[12]],i]]) then begin
          inc(tail[b[ocher[12,head[12]],i]]);
          ocher[b[ocher[12,head[12]],i],tail[b[ocher[12,head[12]],i]]]:=a[ocher[12,head[12]],i];
          rast[a[ocher[12,head[12]],i]]:=rast[ocher[12,head[12]]]+b[ocher[12,head[12]],i];
        end;
      end;
    //  col[ocher[12,head[12]]]:=1;
    end;

    if not( (head[6]=tail[6])) then begin
      inc(head[6]);
      for i:=1 to num[ocher[6,head[6]]] do begin
        if  (rast[ocher[6,head[6]]]+b[ocher[6,head[6]],i]<rast[a[ocher[6,head[6]],i]]) then begin
          inc(tail[b[ocher[6,head[6]],i]]);
          ocher[b[ocher[6,head[6]],i],tail[b[ocher[6,head[6]],i]]]:=a[ocher[6,head[6]],i];
          rast[a[ocher[6,head[6]],i]]:=rast[ocher[6,head[6]]]+b[ocher[6,head[6]],i];
        end;
      end;
    //  col[ocher[6,head[6]]]:=1;
    end;

    if not( (head[4]=tail[4])) then begin
      inc(head[4]);
      for i:=1 to num[ocher[4,head[4]]] do begin
        if (rast[ocher[4,head[4]]]+b[ocher[4,head[4]],i]<rast[a[ocher[4,head[4]],i]]) then begin
          inc(tail[b[ocher[4,head[4]],i]]);
          ocher[b[ocher[4,head[4]],i],tail[b[ocher[4,head[4]],i]]]:=a[ocher[4,head[4]],i];
          rast[a[ocher[4,head[4]],i]]:=rast[ocher[4,head[4]]]+b[ocher[4,head[4]],i];
        end;
      end;
    //  col[ocher[4,head[4]]]:=1;
    end;

    if not( (head[3]=tail[3])) then begin
      inc(head[3]);
      for i:=1 to num[ocher[3,head[3]]] do begin
        if (rast[ocher[3,head[3]]]+b[ocher[3,head[3]],i]<rast[a[ocher[3,head[3]],i]]) then begin
          inc(tail[b[ocher[3,head[3]],i]]);
          ocher[b[ocher[3,head[3]],i],tail[b[ocher[3,head[3]],i]]]:=a[ocher[3,head[3]],i];
          rast[a[ocher[3,head[3]],i]]:=rast[ocher[3,head[3]]]+b[ocher[3,head[3]],i];
        end;
      end;
    //  col[ocher[3,head[3]]]:=1;
    end;
  end;
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
  reset(input,'graph.in');
  rewrite(output,'graph.out');
  readln(n,m);

  for i:=1 to m do begin
    readln(rebra[i,1],rebra[i,2],rebra[i,3]);
    if rebra[i,3]=1 then rebra[i,3]:=12 else
    if rebra[i,3]=2 then rebra[i,3]:=6 else
    if rebra[i,3]=3 then rebra[i,3]:=4 else
    if rebra[i,3]=4 then rebra[i,3]:=3;
    inc(num[rebra[i,1]]);
    inc(num[rebra[i,2]]);
  end;
{  for i:=m+1 to 2*m do begin
    rebra[i,1]:=rebra[i-m,2];
    rebra[i,2]:=rebra[i-m,1];
    rebra[i,3]:=rebra[i-m,3];
    inc(num[rebra[i,1]]);
  end; }
  for i:= 1 to n do begin
    setlength(a[i],(num[i]+1));
    setlength(b[i],(num[i]+1));
  end;
  for i:=1 to m do begin
    inc(cop[rebra[i,1]]);
    a[rebra[i,1],cop[rebra[i,1]]]:=rebra[i,2];
    b[rebra[i,1],cop[rebra[i,1]]]:=rebra[i,3];
  end;
  for i:=m+1 to 2*m do begin
    inc(cop[rebra[i-m,2]]);
    a[rebra[i-m,2],cop[rebra[i-m,2]]]:=rebra[i-m,1];
    b[rebra[i-m,2],cop[rebra[i-m,2]]]:=rebra[i-m,3];
  end;
  setlength(ocher[3],400002);
  setlength(ocher[4],400002);
  setlength(ocher[6],400002);
  setlength(ocher[12],400002);
  for i:=2 to n do
    rast[i]:=inf;
  for i:=1 to num[1] do begin
    if (0+b[1,i]<rast[a[1,i]]) then begin
      inc(tail[b[1,i]]);
      ocher[b[1,i],tail[b[1,i]]]:=a[1,i];
      rast[a[1,i]]:=0+b[1,i];
    end;
  end;
  //col[1]:=1;

  bfs;
  for i:=2 to n do begin
    writeln(rast[i]/12:0:8);
  end;
end.