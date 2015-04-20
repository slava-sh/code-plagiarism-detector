{$A8,B-,C+,D+,E-,F-,G+,H+,I+,J-,K-,L+,M-,N+,O+,P+,Q-,R-,S-,T-,U-,V+,W-,X+,Y+,Z1}
{$MINSTACKSIZE $00004000}
{$MAXSTACKSIZE $10000000}
{$IMAGEBASE $00400000}
{$APPTYPE GUI}
{$WARN SYMBOL_DEPRECATED ON}
{$WARN SYMBOL_LIBRARY ON}
{$WARN SYMBOL_PLATFORM ON}
{$WARN UNIT_LIBRARY ON}
{$WARN UNIT_PLATFORM ON}
{$WARN UNIT_DEPRECATED ON}
{$WARN HRESULT_COMPAT ON}
{$WARN HIDING_MEMBER ON}
{$WARN HIDDEN_VIRTUAL ON}
{$WARN GARBAGE ON}
{$WARN BOUNDS_ERROR ON}
{$WARN ZERO_NIL_COMPAT ON}
{$WARN STRING_CONST_TRUNCED ON}
{$WARN FOR_LOOP_VAR_VARPAR ON}
{$WARN TYPED_CONST_VARPAR ON}
{$WARN ASG_TO_TYPED_CONST ON}
{$WARN CASE_LABEL_RANGE ON}
{$WARN FOR_VARIABLE ON}
{$WARN CONSTRUCTING_ABSTRACT ON}
{$WARN COMPARISON_FALSE ON}
{$WARN COMPARISON_TRUE ON}
{$WARN COMPARING_SIGNED_UNSIGNED ON}
{$WARN COMBINING_SIGNED_UNSIGNED ON}
{$WARN UNSUPPORTED_CONSTRUCT ON}
{$WARN FILE_OPEN ON}
{$WARN FILE_OPEN_UNITSRC ON}
{$WARN BAD_GLOBAL_SYMBOL ON}
{$WARN DUPLICATE_CTOR_DTOR ON}
{$WARN INVALID_DIRECTIVE ON}
{$WARN PACKAGE_NO_LINK ON}
{$WARN PACKAGED_THREADVAR ON}
{$WARN IMPLICIT_IMPORT ON}
{$WARN HPPEMIT_IGNORED ON}
{$WARN NO_RETVAL ON}
{$WARN USE_BEFORE_DEF ON}
{$WARN FOR_LOOP_VAR_UNDEF ON}
{$WARN UNIT_NAME_MISMATCH ON}
{$WARN NO_CFG_FILE_FOUND ON}
{$WARN MESSAGE_DIRECTIVE ON}
{$WARN IMPLICIT_VARIANTS ON}
{$WARN UNICODE_TO_LOCALE ON}
{$WARN LOCALE_TO_UNICODE ON}
{$WARN IMAGEBASE_MULTIPLE ON}
{$WARN SUSPICIOUS_TYPECAST ON}
{$WARN PRIVATE_PROPACCESSOR ON}
{$WARN UNSAFE_TYPE OFF}
{$WARN UNSAFE_CODE OFF}
{$WARN UNSAFE_CAST OFF}

Uses math;
Var kol,i,n,i1,j1,rez:longint;
rr,dp,m,pred,z:Array [0..10000000] of longint;
ss:array [0..10000000] of boolean;
procedure add(i,j:longint);
begin
  inc(kol);
  m[kol]:=j;
  pred[kol]:=z[i];
  z[i]:=kol;
end;
procedure dfs(v,p:longint);
Var i:longint;
begin
  if v=j1
  then ss[v]:=true;
  dp[v]:=1;
  i:=z[v];
  while i<>0 do
  begin
    if m[i]<>p
    then begin
          dfs(m[i],v);
          dp[v]:=max(dp[v],dp[m[i]]+1);
          ss[v]:=ss[v] or ss[m[i]];
         end;
    i:=pred[i];
  end;  
end;
procedure dfs2(v,p,zz:longint);
Var i:longint;
begin
  if v=i1
  then exit;
  i:=z[v];
  rr[v]:=zz;
  while i<>0 do
  begin
    if ss[m[i]]=false
    then begin rr[v]:=max(rr[v],zz+dp[m[i]]); i:=pred[i]; continue; end;
    if m[i]=p
    then begin rr[v]:=max(rr[v],rr[m[i]]); i:=pred[i]; continue; end;
    dfs2(m[i],v,zz+1);    
    i:=pred[i];
  end;
end;
procedure dfs3(v,p,zz:longint);
Var zzz,i:longint;
begin
  if v=j1
  then exit;
  zzz:=zz;
  i:=z[v];
  while i<>0 do
  begin
    if (m[i]<>p)and(not ss[m[i]])
    then zzz:=max(zzz,zz+dp[m[i]]);
    i:=pred[i];
  end;
  i:=z[v];
  while i<>0 do
  begin
    if (m[i]<>p)and(ss[m[i]])
    then rez:=max(rez,min(zzz,rr[m[i]]));
    i:=pred[i];
  end;
  i:=z[v];
  while i<>0 do
  begin
    if (m[i]<>p)and(ss[m[i]])
    then dfs3(m[i],v,zz+1);
    i:=pred[i];
  end;
end;
begin
  Assign(input,'dwarfs.in'); reset(input);
  Assign(output,'dwarfs.out'); rewrite(output);
  read(n);
  kol:=0;
  for i:=1 to n-1 do
  begin
    read(i1,j1);
    add(i1,j1);
    add(j1,i1);
  end;
  read(i1,j1);
  dfs(i1,-1);
  dfs2(j1,-1,1);
  rez:=1;
  dfs3(i1,-1,1);
  writeln(rez)
end.
 
