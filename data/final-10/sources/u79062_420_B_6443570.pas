type
     tree=^node;
     node=record
       data:boolean;
       lnum,rnum:longint;
       lch,rch:tree;
     end;

var
    i,n,m,cnt:longint;
    a,c,ans,b,pre:array[-1..100010] of longint;
    ch:array[0..100010] of char;
    s:array[-1..100010] of int64;
    ok:array[0..100010] of boolean;

begin {main}
  readln(n,m);
  fillchar(c,sizeof(c),0);
  for i:=1 to m do readln(ch[i],a[i]);
  for i:=1 to n do pre[i]:=0;
  for i:=1 to m do
    begin
      if ch[i]='-' then
        begin
          inc(c[pre[a[i]]]);dec(c[i]);pre[a[i]]:=0;
        end
      else
        pre[a[i]]:=i;
    end;
  for i:=1 to n do if pre[i]>0 then inc(c[pre[i]]);
  b[-1]:=0;
  for i:=0 to m do b[i]:=b[i-1]+c[i];
  s[-1]:=0;
  for i:=0 to m do s[i]:=s[i-1]+int64(b[i]);
  for i:=1 to n do pre[i]:=0;
  fillchar(ok,sizeof(ok),true);
  for i:=1 to m do
    begin
      if ch[i]='+' then
        begin
          if s[i-1]-s[pre[a[i]]-1]>0 then ok[a[i]]:=false;pre[a[i]]:=0;
        end
      else
        pre[a[i]]:=i;
    end;
  for i:=1 to n do if (pre[i]>0) and (s[m]-s[pre[i]-1]>0) then ok[i]:=false;
  cnt:=0;
  for i:=1 to n do if ok[i] then begin inc(cnt);ans[cnt]:=i;end;
  writeln(cnt);
  if cnt<>0 then
    begin
      for i:=1 to cnt-1 do write(ans[i],' ');
      writeln(ans[cnt]);
    end;
end.
