module main;

import std.stdio;
import std.string;
import std.math;

int main()
{
    stdin=File("abcd.in", "rt");
    stdout=File("abcd.out", "wt");
    long t, z, y, x, d;
    string s;
    readf(" %s", &t);
    s=readln().strip();
    for (int i=1; i<=t; i++){
        s=readln().strip();
        z = cast (long) s[0];
        z-=48;
        y = cast (long) s[1];
        y-=48;
        x = cast (long) s[2];
        x-=48;
        d = cast (long) s[3];
        d-=48;
        if (z!=0 && x!=0){
            z = (z*10+y)*(z*10+y);
            x = (x*10+d)*(x*10+d);
        }
        if (z==0){z=y*y;}
        if (x==0){x=d*d;}
        y = z+x;
        y = y%7;
        if (y==1){writeln("YES");}else{writeln("NO");}
    }
	return 0;
}
