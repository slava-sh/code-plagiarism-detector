program Seq;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var n,h,i,f,s,ai:longint; sum,summin:int64;
 a:array[1..200001] of longint;
begin
   assign(input,'seq.in');
  assign(output,'seq.out');
  reset(input);
  rewrite(output);
  readln(n,h);
  for i:=1 to n do read (a[i]);
  f:=0;
  i:=1;
  while (i<=n-h+1) do
    begin
    if (a[i]=0) or (a[i]=1) then
      begin
      s:=1;
      ai:=2;
      sum:=0;
      if (a[i]=0) then sum:=sum+1;
      while (a[i+ai-1]<=ai)and (i+ai-1<=n)and(s<h) do
        begin
        s:=s+1;
        sum:=sum-a[i+ai-1]+ai;
        ai:=ai+1;
        end;
      if (s=h) then
        begin
        f:=f+1;
        if(f=1) then summin:=sum else if(sum<summin) then summin:=sum;
        i:=i+1;
        end
        else i:=i+ai-1;
        end
      else i:=i+1;
      end;
  if (f=0) then writeln(-1) else writeln(summin);
  close(input);
  close(output);
end.
