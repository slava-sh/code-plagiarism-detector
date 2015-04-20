Var n,rr,l,r,x,c,ans1,ans:int64;
    i:longint;
    a:array[0..1000000] of int64;
  begin
    assign(input,'che.in');
    reset(input);
    assign(output,'che.out');
    rewrite(output);
    read(n,rr);
    for i:=1 to n do
     read(a[i]);
    for i:=1 to n do
     begin
       x:=a[i];
       l:=i;
       r:=n;
       while l+1<r do
        begin
          c:=(l+r) div 2;
          if a[c]-x>rr then r:=c
          else l:=c;
        end;
       if a[l]-x>rr then ans1:=l
       else if a[r]-x>rr then ans1:=r
       else ans1:=n+1;
       ans:=ans+(n-ans1+1);
     end;
    writeln(ans);
    close(input);
    close(output);
  end.