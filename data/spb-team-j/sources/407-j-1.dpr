program po;

{$APPTYPE CONSOLE}

{%File 'seq.in'}
{%File 'seq.out'}

uses
  SysUtils;

var
  n,h,i,j,ones_count,min,an,sum:longint;
  ones,a,ans,b:array[1..200000] of integer;
procedure pr(wrk:integer);
var
  l:integer;
begin
  l:=2;
  while (l <= h) do begin
    if (b[wrk+1] > l) then begin
      ans[an]:=-1;
      l:=200001;
    end
    else begin
      ans[an]:=ans[an]+(l-b[wrk+1]);
      inc(wrk);
      b[wrk]:=l;
      inc(l);

    end;
  end;
end;
begin
assign(input,'seq.in');
assign(output,'seq.out');
  read(n,h);
  ones_count:=0;
  for i:=1 to n do begin
    read(a[i]);
    if a[i]=1 then begin
      inc(ones_count);
      ones[ones_count]:=i;
    end;
  end;
  an:=0;
  for i:=1 to ones_count do begin
    for j:=1 to n do
    b[j]:=a[j];
    inc(an);
      pr(ones[i]);
  end;
  min:=ans[1];
  for i:=2 to an do
    if ((ans[i]<min)) then min:=ans[i];
  write(min);



end.
