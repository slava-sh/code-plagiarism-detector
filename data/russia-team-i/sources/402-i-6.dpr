program I1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  A: array [1..100000] of integer;
  i, ind, n, ind1, max, d, sum, indx, indy, x, y: integer;

begin
  reset(input, 'sochi.in');
  rewrite(output, 'sochi.out');
  read(n, d);

  for i:=1 to n do
    read(A[i]);

  for i:= 1 to n do
    A[i]:=A[i]-2*d;

  ind:=0;

  for i:=1 to n do
    if A[i]>0 then
      ind:=1;

  if ind = 0 then
  begin;
    max:=-2*d;

    for i:=1 to n do
      if A[i]> max then
        max:=A[i];

    write(max+2*d);
  end;

  if ind = 1 then
  begin

    ind1:=0;

    for i:=1 to n do if (A[i]>=1) and (A[i]<d) then
      inc(ind1);

    if (ind1 = 0) or (ind1=1) then
    begin;
      sum:=0;

      for i:=1 to n do
        if A[i]>=0 then
          sum:=sum+A[i];

      write(sum+2*d);
    end;

    if ind1>=2 then
    begin;
      for i:=1 to n do
        if A[i]>=d then
          sum:=sum+A[i];

      x:=0;
      y:=0;

      for i:=1 to n do if (A[i]>x) and (A[i]<d) then begin;
        x:=A[i]; indx:=i;
      end;

      for i:=1 to n do
        if (A[i]>y) and (i<>indx) and (A[i]<d) then
          begin;
            y:=A[i];
            indy:=i;
          end;
      sum:=sum+x+y;
      write(sum+d*2);
   end;
  end;
end.
