program Main;
  Uses MATH;
  var T : LongInt;
      N , M , K : LongInt;
      Count , X : Array [ 1 .. 100001 ] of LongInt;
      CantBeFirst , AnswerArr : Array [ 1 .. 100001 ] of Boolean;
      MinDish , FirstAngry , FreeCount : LongInt;

  procedure ClearAndInit ( ) ;
    var I : LongInt;
  begin
    for i := 1 to N do
      X [ i ] := 0;
    for i := 1 to K do
    begin
      Count [ i ] := 0;
      CantBeFirst [ i ] := false;
      AnswerArr [ i ] := false;
    end;
    FirstAngry := 0;
    FreeCount := 0;
    MinDish := MaxLongInt;
  end;

  procedure ReadInput ( ) ;
    var I : LongInt;
        Y : LongInt;
  begin
    for i := 1 to K do
      read ( Count [ i ] ) ;
    for i := 1 to N do
    begin
      readLn ( X[i] , Y ) ;
      if ( Y = 1 ) and ( FirstAngry = 0 ) then
        FirstAngry := I;
      if ( FirstAngry <> 0 ) then
        if ( X[i] <> 0 ) then
          CantBeFirst [ X[i] ] := true;
    end;
  end;

  procedure Solve ( ) ; // AnswerArr = true => N!!!!
    var I : LongInt;
  begin
    if ( FirstAngry = 0 ) then
    begin

      For i := 1 to N do
      begin
        if ( X[i] = 0 ) then
          inc ( FreeCount )
        else
          dec ( Count[X[i]] ) ;
      end;

      for i := 1 to K do
      begin
        if ( Count[i] <= FreeCount ) then
          AnswerArr[i] := true;
      end;

    end
    else
    begin


      for i := 1 to FirstAngry-1 do
      begin
        if ( X[i] = 0 ) then
          inc ( FreeCount )
        else
          dec ( Count[X[i]] ) ;
      end;

      for i := 1 to K do
      begin
        if ( CantBeFirst [ i ] = false ) and ( Count[ i] <= FreeCount ) then
        begin
          AnswerArr [ i ] := true;
          MinDish := Min ( MinDish , Count [ i ] ) ;
        end;
      end;

      for i := FirstAngry to N do
      begin
        if ( X[i] = 0 ) then
          inc ( FreeCount )
        else
          dec ( Count[X[i]] ) ;
      end;

      for i := 1 to K do
      begin
        if ( AnswerArr[i] ) then
          Continue
        else
          if ( FreeCount-MinDish >= Count[i] )or(Count[i] = 0) then
            AnswerArr[i] := true;
      end;
    end;

    for i := 1 to K do
    begin
      if ( AnswerArr[i] ) then
        write ( 'Y' )
      else
        write ( 'N' ) ;
    end;
    writeLn();
  end;

  var I , J : LongInt;
begin
  //Assign ( Input , 'in.txt' ) ;
  //reset ( Input ) ;

  readLn ( T ) ;

  for i := 1 to T do
  begin
    readLn () ;
    readLn ( M , K ) ;
    N := M-1;
    ClearAndInit ( ) ;
    ReadInput ( ) ;

    Solve ( ) ;

  end;
end.
