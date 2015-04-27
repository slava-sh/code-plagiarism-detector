

def main():
  n=input()
  x=raw_input().split()
  ps=[float(s) for s in x]
  ret=0.0
  for a in xrange(n):
    for b in xrange(a+1,n+1):
      if 2*a>n or 2*b<n:continue
      ca=( (0.5*n)-b ) / (a-b)
      cb=( (0.5*n)-a ) / (b-a)
      ret=max(ret, ca*ps[a]+cb*ps[b])
  print "%.9f"%ret

main()
