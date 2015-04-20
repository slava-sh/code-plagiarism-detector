{$r-,s-,q-,i-,o+}
const
  p=911;
  mo=1000000007;

var
  mar : array [0..1001,0..1001] of longint;
  o1,o4,h : array [0..1000000] of longint;
  o2,o3 : array [0..1000000,1..14] of longint;
  xx,yy,c,pos : int64;
  i,j,n,x,y,ans,m,f,k,k1,kol,k2 : longint;
  s :array [0..200] of string;
  procedure qs(l,r:longint);
    var
      i,j,xx:longint;
    begin
      i:=l; j:=r;
      xx:=h[random(r-l+1)+l];
      repeat
        while (xx>h[i]) do inc(i);
        while (xx<h[j]) do dec(j);
        if i<=j
          then begin
                 h[0]:=h[i]; h[i]:=h[j]; h[j]:=h[0];
                 inc(i); dec(j);
               end;
      until i>j;
      if i<r then qs(i,r);
      if l<j then qs(l,j);
    end;
  procedure sort(ii,l,r:longint);
    var
      i,j,xx,yy,k,c:longint;
    begin
      i:=l; j:=r;
      k:=random(r-l+1)+l;
      xx:=o2[ii,k];
      yy:=o3[ii,k];
      repeat
        while (xx>o2[ii,i]) or ((xx=o2[ii,i]) and (yy>o3[ii,i])) do inc(i);
        while (xx<o2[ii,j]) or ((xx=o2[ii,j]) and (yy<o3[ii,j])) do dec(j);
        if i<=j
          then begin
                  c:=o2[ii,i];
                  o2[ii,i]:=o2[ii,j];
                  o2[ii,j]:=c;
                   c:=o3[ii,i];
                  o3[ii,i]:=o3[ii,j];
                  o3[ii,j]:=c;

                 inc(i); dec(j);
               end;
      until i>j;
      if i<r then sort(ii,i,r);
      if l<j then sort(ii,l,j);
    end;
begin
  assign(input,'virus.in'); reset(input);
  assign(output,'virus.out'); rewrite(output);
  randomize;
  readln(n,m,k);
  for i:=1 to n do readln(s[i]);
  i:=1;
  j:=1;
  for k1:=1 to n do
  for k2:=1 to m do
   if s[k1,k2]='*' then begin inc(o1[i]); o2[i,o1[i]]:=k1; o3[i,o1[i]]:=k2; end;
  o4[i]:=0; kol:=0;
  while (i<=j) do
   begin
    if o4[i]=k then
    begin
      sort(i,1,o1[i]);
      inc(kol); h[kol]:=0;
      for k1:=1 to o1[i] do
        begin
          xx:=o2[i,k1];
          yy:=o3[i,k1];
          pos:=m*(yy-1)+xx;
          h[kol]:=(int64(h[kol])*p+pos) mod mo;
        end;
    end
    else
    begin
    inc(f);
    for k1:=1 to o1[i] do mar[o2[i,k1],o3[i,k1]]:=f;
    for k1:=1 to o1[i] do
     begin
      x:=o2[i,k1];
      y:=o3[i,k1];
      if (x+1<=n) and (mar[x+1,y]<>f) then
       begin
        inc(j);
        o1[j]:=o1[i]+1;
        for k2:=1 to o1[i] do begin o2[j,k2]:=o2[i,k2]; o3[j,k2]:=o3[i,k2]; end;
        o2[j,o1[j]]:=x+1;
        o3[j,o1[j]]:=y;
        mar[x+1,y]:=f;
        o4[j]:=o4[i]+1;
       end;
      if (x-1>=1) and (mar[x-1,y]<>f) then
       begin
        inc(j);
        o1[j]:=o1[i]+1;
        for k2:=1 to o1[i] do begin o2[j,k2]:=o2[i,k2]; o3[j,k2]:=o3[i,k2]; end;
        o2[j,o1[j]]:=x-1;
        o3[j,o1[j]]:=y;
        mar[x-1,y]:=f;
        o4[j]:=o4[i]+1;
       end;
      if (y+1<=m) and (mar[x,y+1]<>f) then
       begin
        inc(j);
        o1[j]:=o1[i]+1;
        for k2:=1 to o1[i] do begin o2[j,k2]:=o2[i,k2]; o3[j,k2]:=o3[i,k2]; end;
        o2[j,o1[j]]:=x;
        o3[j,o1[j]]:=y+1;
        mar[x,y+1]:=f;
        o4[j]:=o4[i]+1;
       end;
      if (y-1>=1) and (mar[x,y-1]<>f) then
       begin
        inc(j);
        o1[j]:=o1[i]+1;
        for k2:=1 to o1[i] do begin o2[j,k2]:=o2[i,k2]; o3[j,k2]:=o3[i,k2]; end;
        o2[j,o1[j]]:=x;
        o3[j,o1[j]]:=y-1;
        mar[x,y-1]:=f;
        o4[j]:=o4[i]+1;
       end;
     end;
     end;
    inc(i);
   end;
  qs(1,kol);
  ans:=1;
  for i:=2 to kol do if h[i]<>h[i-1] then inc(ans);
  writeln(ans);

end.
