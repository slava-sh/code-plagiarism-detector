var
  a,l,c1,c2:array[1..100000] of int64;
  d,e:array[0..100] of int64;
  n,size,ll,p,y,o,c,k,x,q:int64;
  i,j,z:longint;
  good:boolean;

begin
  assign(input,'numbers.in');
  reset(input);
  assign(output,'numbers.out');
  rewrite(output);
  readln(n);
  size:=0;
  for i:=1 to n do
  begin
    readln(c,k);
    p:=0;
    x:=c;
    while (x<>0) do
    begin
      inc(p);
      x:=x div 10;
    end;
    for j:=1 to k do
    begin
      readln(q);
      y:=q;
      ll:=0;
      while (q<>0) do
      begin
        inc(ll);
        d[ll]:=q mod 10;
        q:=q div 10;
      end;
      x:=c;
      for z:=ll downto 1 do x:=x*10+d[z];
      inc(size);
      a[size]:=x;
      l[size]:=ll+p;
      c1[size]:=c;
      c2[size]:=y;
    end;
  end;
  readln(n);
  for i:=1 to n do
  begin
    readln(y);
    p:=y;
    for j:=11 downto 1 do
    begin
      e[j]:=y mod 10;
      y:=y div 10;
    end;
    d[0]:=0;
    for j:=1 to 11 do d[j]:=(d[j-1]*10)+e[j];
    good:=false;
    for j:=1 to size do
    begin
      if (a[j]<>d[l[j]]) then continue;
      if (e[l[j]+1]=0) then continue;
      good:=true;
      write('+',c1[j]);
      write('(',c2[j],')');
      ll:=11-l[j];
      case ll of
      3:writeln(e[9],e[10],e[11]);
      4:writeln(e[8],e[9],'-',e[10],e[11]);
      5:writeln(e[7],e[8],e[9],'-',e[10],e[11]);
      6:writeln(e[6],e[7],'-',e[8],e[9],'-',e[10],e[11]);
      7:writeln(e[5],e[6],e[7],'-',e[8],e[9],'-',e[10],e[11]);
      end;
      break;
    end;
    if (not good) then writeln('Incorrect');
  end;
  close(input);
  close(output);
end.
