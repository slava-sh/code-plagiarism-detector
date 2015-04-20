var
  n,d,uk,max,i : longint;
  ans : int64;
  a : array [0..3000000] of longint;
  f : array [0..3000000] of boolean;
begin
  assign(input,'sochi.in'); reset(input);
  assign(output,'sochi.out'); rewrite(output);
  readln(n,d);
  for i:=1 to n do f[i]:=false;
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
    if a[i]>=3*d then
      begin
        f[i]:=true;
        ans:=ans+a[i]-d-d;
      end;
  max:=-1;
  uk:=-1;
  for i:=1 to n do
    if (f[i]=false) and (a[i]>2*d) and (a[i]>max) then begin max:=a[i]; uk:=i; end;
  if max<>-1
    then begin
        ans:=ans+a[uk]-d;
         f[uk]:=true;
      end
    else ans:=ans+d;
  max:=-1;
  uk:=-1;
  for i:=1 to n do
    if (f[i]=false) and (a[i]>2*d) and (a[i]>max) then begin max:=a[i]; uk:=i; end;
  if max<>-1
    then begin
        ans:=ans+a[uk]-d;
        f[uk]:=true;
      end
    else ans:=ans+d;
  writeln(ans);
  close(input); close(output);
end.

