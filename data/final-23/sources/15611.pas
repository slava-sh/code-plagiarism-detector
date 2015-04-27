program signchange;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;

var m,ch,nech,k,pow,a,b,j,n,i,c,l,r:longint;
    t1,t2:array[0..500000]of longint;


function power(a,b:longint):longint;
begin
  if b=0 then
    result:=1
  else
    if b mod 2=0 then
      result:=sqr(power(a,b div 2))
    else
      result:=a*power(a,b-1);
end;

function rsq1(l,r:longint):longint;
var s:longint;
begin
  s:=0;
  l:=l+pow-1;
  r:=r+pow-1;
  while l<r do
    begin
      if l mod 2=1 then
        s:=s+t1[l];
      if r mod 2=0 then
        s:=s+t1[r];
      l:=(l+1)div 2;
      r:=(r-1) div 2;
    end;
  if l=r then
    s:=s+t1[l];
  result:=s;
end;


function rsq2(l,r:longint):longint;
var s:longint;
begin
  s:=0;
  l:=l+pow-1;
  r:=r+pow-1;
  while l<r do
    begin
      if l mod 2=1 then
        s:=s+t2[l];
      if r mod 2=0 then
        s:=s+t2[r];
      l:=(l+1) div 2;
      r:=(r-1) div 2;
    end;
  if l=r then
    s:=s+t2[l];
  result:=s;
end;

procedure update1(i,x:longint);
begin
  i:=i+pow-1;
  t1[i]:=x;
  while i>1 do
    begin
      i:=i div 2;
      t1[i]:=t1[2*i]+t1[2*i+1];
    end;
end;

procedure update2(i,x:longint);
begin
  i:=i+pow-1;
  t2[i]:=x;
  while i>1 do
    begin
      i:=i div 2;
      t2[i]:=t2[2*i]+t2[2*i+1];
    end;
end;


begin
  reset(input,'signchange.in');
  rewrite(output,'signchange.out');
  readln(n);
  k:=0;
  while power(2,k)<n do
    inc(k);
  pow:=power(2,k);
  for i:=1 to n do
    begin
      read(a);
      if i mod 2=0 then
        update2(i,a)
      else
        update1(i,a);
    end;
  readln;  
  readln(m);
  for i:=1 to m do
    begin
      readln(a,b,c);
      if a=0 then
        if b mod 2=0 then
          update2(b,c)
        else
          update1(b,c)
      else
        begin
          ch:=rsq2(b,c);
          nech:=rsq1(b,c);
          if b mod 2=0 then
            writeln(ch-nech)
          else
            writeln(nech-ch);
        end;
    end;
  close(input);
  close(output);
end.
