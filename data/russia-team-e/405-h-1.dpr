{$A8,B-,C+,D+,E-,F-,G+,H+,I+,J-,K-,L+,M-,N+,O-,P+,Q+,R+,S-,T-,U-,V+,W-,X+,Y+,Z1}
{$MINSTACKSIZE $00004000}
{$MAXSTACKSIZE $00100000}
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
program sol;

uses
  SysUtils,math;

Var m1,m3:array[1..5000,0..5000]of longint;
    mass:array[1..5000] of LongInt;
    F:array[1..5000] of Boolean;
    F1:Boolean;
    n,i,l,m,I1,J1,minI,minJ,c,l1,l2,d,a:longint;
    k,kend,minimum,minSum:int64;
{Procedure QSort(L,R:LongInt);
Var I,J,b,k,x:LongInt;
begin
   I:=L;
   J:=R;
   k:=L+Random(R-L);
   x:=m[k];
   Repeat
      While m[I]>x do
      Inc(I);
      While m[J]<x do
      Dec(J);
      If I<=J
      then begin
           b:=m[I];
           m[I]:=m[J];
           m[J]:=b;
           Inc(I);
           Dec(J);
           end;
   Until I>J;
   If I<=R
   then QSort(I,R);
   If J>=L
   then QSort(L,J);
end;}
Procedure Poisk(I1,J1,Sum:LongInt);
Var I:Integer;
begin
   If mass[J1]=2
   then begin
        If minSum>Sum
        then begin
             minSum:=Sum;
             minI:=I1;
             minJ:=J1;
             F1:=True;
             end;
        end
   else
   For I:=1 to m1[J1,0] do
   If ((not F[m1[J1,I]]) and (mass[m1[J1,I]]=0)) or (mass[m1[J1,I]]=2)
   then begin
        F[m1[J1,I]]:=True;
        Poisk(I1,m1[J1,I],Sum+m3[J1,m1[J1,I]]);
        F[m1[J1,I]]:=False;
        end;
end;
begin
  ///assign(input,'input.txt');
  assign(input,'secure.in');
  reset(input);
  ///assign(output,'output.txt');
  assign(output,'secure.out');
  rewrite(output);
  readln(N,M);
  For I:=1 to N do
  read(mass[I]);
  readln;
  F1:=False;
  For I:=1 to m do
  begin
  readln(I1,J1,c);
  Inc(m1[I1,0]);
  m1[I1,m1[I1,0]]:=J1;
  Inc(m1[J1,0]);
  m1[J1,m1[J1,0]]:=I1;
  m3[I1,J1]:=c;
  m3[J1,I1]:=c;
  end;
  minSum:=10000000000;
  For I:=1 to N do
  If (not F[I]) and (mass[I]=1)
  then begin
       F[I]:=True;
       Poisk(I,I,0);
       end;
  If not F1
  then write('-1')
  else write(minI,' ',minJ,' ',minSum);
end.
