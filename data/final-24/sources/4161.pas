var
 ind:array[1..3]of longint;
 cc1,cc2,s1,s2,s,cc:array[1..1000000]of char;
 p,pr1,pr2:array[1..100000]of longint;
 f1,f2:array[1..1000000]of boolean;
 ff:array[0..1000000]of boolean;
 ll,pp,kk,n1,n2,k,ln1,ln2,kol,z,stn,i,j,n,l:longint;
 f:boolean;
begin
 assign(input,'input.txt'); assign(output,'output.txt');
 reset(input); rewrite(output);
 ind[1]:=0; ind[2]:=0; ind[3]:=0; kol:=0; n:=0;
 readln(l); while not eoln(input) do begin inc(n); read(cc[n]); end;
 for i:=1 to n do inc(ind[ord(cc[i])-96]);
 for i:=1 to 3 do if ind[i]=0 then inc(kol);
 if kol=2 then begin writeln(1); writeln(cc[1]); halt; end;
 if l=1 then
 begin
  writeln(3-kol);
  for i:=1 to 3 do if ind[i]<>0 then writeln(chr(i+96));
  halt;
 end;
 if n<=l then
 begin
  writeln(1);
  for i:=1 to n do write(cc[i]);
  writeln;
  halt;
 end;
 kk:=kol;
 for i:=2 to l+1 do
 begin
  stn:=1; s[1]:=cc[1];
  p[1]:=0;
  f:=true;
  for j:=2 to i-1 do
  begin
   inc(stn); s[stn]:=cc[j];
   z:=p[j-1];
   while (z<>0)and(s[stn]<>s[z+1]) do z:=p[z];
   if s[z+1]=s[stn] then p[stn]:=z+1 else p[stn]:=0;
  end; inc(stn); s[stn]:='#'; p[stn]:=0;
  kol:=0;
  for j:=i to n do
  begin inc(stn); s[stn]:=cc[j];
   z:=p[stn-1]; inc(kol);
   while (z<>0)and(s[z+1]<>s[stn]) do z:=p[z];
   if s[z+1]=s[stn] then p[stn]:=z+1 else p[stn]:=0;
   if (kol=i-1)and(p[stn]<>kol) then begin f:=false; break; end;
   if (kol=i-1)and(p[stn]=kol) then kol:=0;
  end;
  if (f=false)or(kol<>0) then continue;
  writeln(1);
  for j:=1 to i-1 do write(cc[j]);
  writeln;
  halt;
 end;

 if kk=1 then
 begin
  writeln(2);
  for i:=1 to 3 do if ind[i]<>0 then writeln(chr(i+96));
  halt;
 end;
 for ln1:=1 to l do
 begin
  for k:=1 to n do f1[k]:=false;
  for k:=1 to ln1 do cc1[k]:=cc[k];
  for k:=1 to ln1 do s1[k]:=cc1[k];
  n1:=ln1+1; s1[n1]:='#';
  for k:=1 to n do begin inc(n1); s1[n1]:=cc[k]; end;
  pr1[1]:=0;
  for k:=2 to n1 do
  begin z:=pr1[k-1];
   while (z<>0)and(s1[z+1]<>s1[k]) do z:=pr1[z];
   if s1[z+1]=s1[k] then pr1[k]:=z+1 else pr1[k]:=0;
   if k>ln1+1 then if pr1[k]=ln1 then f1[k-ln1-1]:=true;
  end;
  ll:=1;
  pp:=-ln1;
  for k:=1 to n do
  begin
   if cc[k]=cc1[ll] then inc(ll) else break;
   if ll>ln1 then
   begin
    ll:=1;
    inc(pp,ln1);
   end;
  end;
  for ln2:=1 to l do
  begin
   for k:=1 to n do f2[k]:=false;
   for k:=ln1+1 to ln2+ln1 do cc2[k-ln1]:=cc[k+pp];
   for k:=1+ln1 to ln2+ln1 do s2[k-ln1]:=cc[k+pp];
   n2:=ln2+1; s2[n2]:='#';
   for k:=1 to n do begin inc(n2); s2[n2]:=cc[k]; end;
   pr2[1]:=0;
   for k:=2 to n2 do
   begin z:=pr2[k-1];
    while (z<>0)and(s2[z+1]<>s2[k]) do z:=pr2[z];
    if s2[z+1]=s2[k] then pr2[k]:=z+1 else pr2[k]:=0;
    if k>ln2+1 then if pr2[k]=ln2 then f2[k-ln2-1]:=true;
   end;
   ff[0]:=true;
   for k:=1 to n do
   begin
    ff[k]:=false;
    if f1[k] then ff[k]:=ff[k] or ff[k-ln1];
    if f2[k] then ff[k]:=ff[k] or ff[k-ln2];
   end;
   if ff[n] then
   begin
    writeln(2);
    for k:=1 to ln1 do write(cc1[k]); writeln;
    for k:=1 to ln2 do write(cc2[k]); writeln;
    halt;
   end;
  end;
 end;
 if kk=0 then
 begin
  writeln(3);
  writeln('a');
  writeln('b');
  writeln('c');
 end else writeln('NO');
end.

sdfsdgg
