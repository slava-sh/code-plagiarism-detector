Var x,y:Int64;
Begin
     ReSet (input,'prizes.in');
     ReWrite (output,'prizes.out');
     Readln (x,y);
     If (x=1) and (y=1)
     then Begin
               Writeln (0);
               Halt (0);
          End;
     If x=1
     then Begin
               Writeln ((y+1) div 4);
               Halt (0)
          End;

     If y=1
     then Begin
               Writeln ((x+1) div 4);
               Halt (0)
          End;
     If (x=2) or (y=2)
     then Begin
               Writeln (0);
               Halt (0)
          End;
     Writeln (1);
End.

