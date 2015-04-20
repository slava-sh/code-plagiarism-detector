uses math;
Var b,n,m,t,t1,ans:longint;
  begin
    assign(input,'prizes.in');
    reset(input);
    assign(output,'prizes.out');
    rewrite(output);
    read(n,m);
    if n>m then
     begin
       t:=n;
       n:=m;
       m:=t;
     end;
    t:=min(n div 3,m div 3);
    ans:=ans+t;
    n:=n-t*3;
    m:=m-t*3;
    n:=n-1;
    m:=m-1;
    t:=min(n,m);
    if t=2 then inc(ans);
    if (t=0) then t1:=1;
    n:=n-t;
    m:=m-t;
    if t1=1 then
     begin
       t1:=m div 4;
       inc(ans,t1);
       t1:=m mod 4;
       if t1>=2 then inc(ans);
     end;
    writeLn(ans);
  end.