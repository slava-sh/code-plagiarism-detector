{$r-,s-,q-,i-,o+}
var
  bb:array [0..1000000,0..9] of longint;
  s:string;
  kv,v,xx,qq,ko,m,i,j,k,l,r,mid,ok,x,n:longint;
  le,re,num,a,b,col,qw:array [0..1000000] of longint;
  procedure qs(l,r:longint);
    var
      i,j,xx,yy,k:longint;
    begin
      i:=l; j:=r;
      k:=random(r-l+1)+l; xx:=b[k]; yy:=a[k];
      repeat
        while (xx>b[i]) or ((xx=b[i]) and (yy>a[i])) do inc(i);
        while (xx<b[j]) or ((xx=b[j]) and (yy<a[j])) do dec(j);
        if i<=j
          then begin
                 a[0]:=a[i]; a[i]:=a[j]; a[j]:=a[0];
                 b[0]:=b[i]; b[i]:=b[j]; b[j]:=b[0];
                 inc(i); dec(j);
               end;
      until i>j;
      if i<r then qs(i,r);
      if l<j then qs(l,j);
    end;

begin
  randomize;
  assign(input,'numbers.in'); reset(input);
  assign(output,'numbers.out'); rewrite(output);
  ko:=0; m:=0;
  readln(n);
  for i:=1 to n do
    begin
      readln(x,k); num[i]:=x;
      for j:=1 to k do
        begin
          inc(m);
          readln(a[m]);
          b[m]:=i;
        end;
      qq:=0;
      while (x>0) do
        begin
          inc(qq); qw[qq]:=x mod 10;
          x:=x div 10;
        end;
      v:=0;
      for j:=qq downto 1 do
        begin
          if bb[v,qw[j]]=0
            then begin inc(kv); bb[v,qw[j]]:=kv; end;
          v:=bb[v,qw[j]];
        end;
      col[v]:=i;
    end;
  qs(1,m);
  for i:=1 to n do begin le[i]:=0; re[i]:=0; end;
  for i:=1 to m do
    begin
      if le[b[i]]=0 then le[b[i]]:=i;
      re[b[i]]:=i;
    end;
  readln(qq);
  while (qq>0) do
    begin
      readln(s);
      for i:=1 to 11 do qw[i]:=ord(s[i])-ord('0');
      v:=0; ok:=0;
      for i:=1 to 3 do
        begin
          if s[1]='0' then break;
          if ok=1 then break;
          if bb[v,qw[i]]=0 then break;
          v:=bb[v,qw[i]];
          if col[v]=0 then continue;
          xx:=0;
          if s[i+1]='0' then continue;
          for j:=i+1 to i+2 do xx:=xx*10+ord(s[j])-ord('0');
          for j:=i+3 to i+5 do
            begin
              xx:=xx*10+ord(s[j])-ord('0');
              if s[j+1]='0' then continue;
              if ok=1 then break;
              l:=le[col[v]]; r:=re[col[v]];
              while (r-l>1) do
                begin
                  mid:=(l+r) div 2;
                  if a[mid]<xx
                    then l:=mid+1
                    else r:=mid;
                end;
              if (a[l]=xx) or (a[r]=xx)
                then begin
                       ok:=1;
                       write('+');
                       for k:=1 to i do write(qw[k]);
                       write('(');
                       for k:=i+1 to j do write(qw[k]);
                       write(')');
                       l:=j+1;
                       while (l<=11) do
                         begin
                           if (11-l+1) mod 2<>0
                             then begin write(qw[l],qw[l+1],qw[l+2]); l:=l+3; end
                             else begin write(qw[l],qw[l+1]); l:=l+2; end;
                           if l<11 then write('-');
                         end;
                       writeln;
                       break;
                     end;
            end;
        end;
      if ok=0 then writeln('Incorrect');
      dec(qq);
    end;
  close(input);
  close(output);
end.
