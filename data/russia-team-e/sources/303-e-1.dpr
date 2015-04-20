//{$A8,B-,C+,D+,E-,F-,G+,H+,I+,J-,K-,L+,M-,N+,O-,P+,Q+,R+,S-,T-,U-,V+,W-,X+,Y+,Z1}

Uses SysUtils;
Var m:Array [0..1000,0..1000] of String[20];
    kol:Array [0..100000] of LongInt;
    d:Array [0..100000] of String;
    n,c,k,i,j,nn,q,len:LongInt;
    s,copys,ans,copy2,copyans:String;
    f:Boolean;
Begin
     ReSet (input,'number.in');ReWrite (output,'number.out');
     Readln (n);
     For I:=1 to n do
     Begin
          Readln (c,k);
          kol[i]:=k;
          d[i]:=IntToStr (c);
          For J:=1 to k do
          Begin
               Readln (m[i,j]);
          End;
     End;
     Readln (nn);
     For I:=1 to nn do
     Begin
          Readln (s);
          ans:='';
          copys:=s;
          f:=False;
          If s[1]='0'
          then Begin
                    Writeln ('Incorrect');
                    Continue;
               End;
          For J:=1 to n do
          Begin
               ans:='';
               s:=copys;
               If Pos (d[j],s)=1
               then Begin
                         ans:=ans+'+'+d[j];
                         Delete (s,1,Length (d[j]));
                         copy2:=s;
                          copyans:=ans;
                          If s[1]='0'
                                        then Begin
                                                  ans:='Incorrect';
                                                  f:=True;
                                                  Break;
                                             End;
                         For Q:=1 to kol[j] do
                         Begin
                              s:=copy2;
                              ans:=copyans;
                              If Pos (m[j,q],s)=1
                              then Begin
                                        ans:=ans+'('+m[j,q]+')';
                                        Delete (s,1,Length (m[j,q]));
                                        If s[1]='0'
                                        then Begin
                                                  ans:='Incorrect';
                                                  f:=True;
                                                  Break;
                                             End;
                                        len:=Length (s);
                                        If len=3
                                        then Begin
                                                  ans:=ans+s;
                                                  f:=True;
                                             End
                                        else If len=4
                                             then Begin
                                                       ans:=ans+s[1]+s[2]+'-'+s[3]+s[4];
                                                       f:=True;
                                                  End
                                             else If len=5
                                                  then Begin
                                                            ans:=ans+s[1]+s[2]+s[3]+'-'+s[4]+s[5];
                                                            f:=True;
                                                       ENd
                                                  else If len=6
                                                  then Begin
                                                            ans:=ans+s[1]+s[2]+'-'+s[3]+s[4]+'-'+s[5]+s[6];
                                                            f:=True;
                                                       ENd
                                                  else If len=7
                                                  then Begin
                                                            ans:=ans+s[1]+s[2]+s[3]+'-'+s[4]+s[5]+'-'+s[6]+s[7];
                                                            f:=True;
                                                       ENd;
                                   End;
                              If f then Break;
                         End;
                         If f then Break;
                    End;
                    If f then Break;
          End;
          If f
          then Writeln (ans)
          else Writeln ('Incorrect');
     End;
End.
