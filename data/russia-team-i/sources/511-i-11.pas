var
  a,f:array [0..1000000] of int64;
  d,sum,sum1,ko,ko1,ans,n:int64;
  i,j:longint;
  function max(a,b:int64):int64; begin if a>b then max:=a else max:=b; end;

begin
  assign(input,'sochi.in'); reset(input);
  assign(output,'sochi.out'); rewrite(output);
  readln(n,d); ko:=0; sum:=0;
  for i:=1 to n do
    begin
      read(a[i]);
      if a[i]>=3*d then begin inc(ko); sum:=sum+a[i]; end;
    end;
  for i:=0 to 1000 do f[i]:=0;
  for i:=1 to n do inc(f[a[i]]);
  ans:=0;
  for i:=1 to n do ans:=max(ans,a[i]);
  for i:=1 to 1000 do
    for j:=1 to 1000 do
      begin
        if (i>=2*d) and (j>=2*d)
          then begin
                 if ((i<>j) and (f[i]>=1) and (f[j]>=1)) or
                   ((i=j) and (f[i]>=2))
                  then begin
                 sum1:=sum; ko1:=ko;
                 if i>=3*d then begin dec(sum1,i); dec(ko1); end;
                 if j>=3*d then begin dec(sum1,j); dec(ko1); end;
                 ans:=max(ans,sum1-int64(ko1)*2*d+i+j-2*int64(d));
                 end;
               end;
      end;
  writeln(ans);
  close(input); close(output);
end.

