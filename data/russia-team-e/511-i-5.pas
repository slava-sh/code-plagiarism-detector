var
  a: array [0..1000000] of int64;
 ans,d : int64;
  l,r,i,n :longint;
  procedure sort(l,r : longint);
   var
   i,j,c,x : longint;
    begin
     i:=l;
     j:=r;
     x:=a[random(r-l+1)+l];
     repeat
      while (a[i]<x) do inc(i);
      while (a[j]>x) do dec(j);
      if i<=j then
       begin
        c:=a[i];
        a[i]:=a[j];
        a[j]:=c;
        inc(i);
        dec(j);
       end;
     until i>j;
     if i<r then sort(i,r);
     if l<j then sort(l,j);
    end;
begin
  randomize;
  assign(input,'sochi.in'); reset(input);
  assign(output,'sochi.out'); rewrite(output);
  readln(n,d);
  for i:=1 to n do read(a[i]);
  sort(1,n);
  l:=a[n];
  r:=a[n];
  ans:=a[n];
  for i:=n-1 downto 1 do
  if a[i]<=2*d then break
  else
   begin
    if (l>=2*d) then
     begin
      ans:=ans+a[i]-2*d;
      l:=a[i]-d;
     end
    else
    if (r>=2*d) then
     begin
      ans:=ans+a[i]-2*d;
      r:=a[i]-d;
     end;
   end;
  writeln(ans);
  close(input);
  close(output);
end.
