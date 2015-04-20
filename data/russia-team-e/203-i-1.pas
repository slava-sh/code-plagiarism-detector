Var n,d,t,max1,max2,max,ans,m,m1,maxx,maxxx:int64;
    i:longint;
    b,a,c:array[0..1000000] of int64;
  begin
    assign(input,'sochi.in');
    reset(input);
    assign(output,'sochi.out');
    rewrite(output);
    Read(n,d);
    for i:=1 to n do
     read(a[i]);
    for i:=1 to n do
     if a[i]>maxxx then maxxx:=a[i];
    for i:=1 to n do
     begin
       if a[i]-2*d>=d then begin inc(m1); c[m1]:=a[i]-2*d; end
       else if a[i]-d>=0 then begin inc(m); b[m]:=a[i]-d; end;
     end;
    t:=0;
    for i:=1 to m do
     if b[i]>max1 then begin max1:=b[i]; max:=i; t:=1; end;
    for i:=1 to m do
     if (b[i]>max2) and (i<>max) then begin max2:=b[i]; t:=2;end;
    if (n=1) and (t=0) then begin WriteLn(a[1]); exit; end;
    if t<=1 then
     begin
       max:=0;
       max2:=0;
       for i:=1 to m1 do
        if c[i]>max2 then begin max2:=c[i]; max:=i; end;
       c[max]:=c[max]+d;
       max2:=0;
     end;
    if t=0 then
     begin
       maxx:=0;
       max1:=0;
       for i:=1 to m1 do
        if (c[i]>max1) and (i<>max) then begin max1:=c[i]; maxx:=i; end;
       c[maxx]:=c[maxx]+d;
       max1:=0;
     end;
    for i:=1 to m1 do
     ans:=ans+c[i];
    ans:=ans+max1+max2;
    if maxxx>ans then ans:=maxxx;
    writeLn(ans);
    close(input);
    close(output);
  end.