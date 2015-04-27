{$A8,B-,C+,D+,E-,F-,G+,H+,I+,J-,K-,L+,M-,N+,O+,P+,Q-,R-,S-,T-,U-,V+,W-,X+,Y+,Z1}
{$MINSTACKSIZE $00004000}
{$MAXSTACKSIZE $00100000}
{$IMAGEBASE $00400000}
{$APPTYPE CONSOLE}

const filename='f';
      oo=maxlongint div 2;
      eps=1e-6;
      eee=1e-21;

var qq,cc:array[0..1000000]of longint;
    qc:array[0..1,-4..504,-4..504]of int64;
    s,ss,sss,s0,s1,s2,s3:string;
    x,y,z,xx,yy,zz,x0,y0,z0,x1,x2,x3,y1,y2,y3,z1,z2,z3:extended;
    ee,dd,nt,ii,jj,kk,nn,mm,n,m,q,c,q0,c0,q1,c1,q2,c2,q3,c3,cur,res,max,min:longint;
    test,ll,t,tt:longint;
    b,bb,bbb,b0,b1,b2,b3:boolean;


    


function mx(q,c:longint):longint;
  begin
  if q>c then mx:=q else mx:=c;
  end;


function mn(q,c:longint):longint;
  begin
  if q<c then mn:=q else mn:=c;
  end;


procedure init;
  begin
  assign(input,filename+'.in');
  assign(output,filename+'.out');
  reset(input);
  rewrite(output);
  end;


procedure fin;
  begin
  close(input);
  close(output);
  end;


procedure clear;
var i,j,k:longint;
  begin
  fillchar(qc,sizeof(qc),0);
  end;


procedure load;
var i,j,k:longint;
  begin
  end;


procedure save;
var i,j,k:longint;
  begin
  end;


procedure run;
var i,j,k:longint;
  begin
  //init;
  fillchar(qq,sizeof(qq),0);
  readln(n,m,mm);
  for i:=1 to m do
    begin
    readln(s);
    for j:=1 to length(s) do
      begin
      if s[j]='1' then inc(qq[j]);
      end;
    end;
  ee:=0;
  dd:=0;
  for i:=1 to n do
    begin
    if qq[i]=0 then inc(dd);
    if qq[i]=1 then inc(ee);
    end;
    
  n:=n-m;
  qc[n mod 2,ee,dd]:=1;

  for kk:=n downto 1 do
    begin

    k:=kk mod 2;
    for i:=0 to ee+dd do
      for j:=0 to dd do
        qc[1-k,i,j]:=0;

    for i:=0 to ee+dd do
      for j:=0 to dd do
        if qc[k,i,j]>0 then
        begin
        qc[1-k,i-2,j]:=  (qc[1-k,i-2,j]   + qc[k,i,j]*i*(i-1) div 2) mod mm;
        qc[1-k,i,j-1]:=  (qc[1-k,i,j-1]   + qc[k,i,j]*i*j)           mod mm;
        qc[1-k,i+2,j-2]:=(qc[1-k,i+2,j-2] + qc[k,i,j]*j*(j-1) div 2) mod mm;
        end;

    end;

  writeln(qc[0,0,0]);

  //fin;
  end;


begin
nt:=1;
//readln(nt);
for test:=1 to nt do
  begin
  clear;
  load;
  run;
  save;
  end;
end.
