__task__ = "seq"
__author__ = "Ale <ale@songbee.net>"

INF = float('+inf')

class Continue(Exception):
  pass

def seq(l, h):
  l = list(l)
  min_i, min_diff = -1, INF
  
  for i in range(len(l)-h+1):
    #print("seq[%i]" % i)
    if l[i] <= 1:
      diff = 1 - l[i]
      try:
        for j in range(1, h):
          if l[i+j] > j+1:
            raise Continue()
          diff += j+1 - l[i+j]
          if diff >= min_diff:
            raise Continue()
      except Continue:
        #print("seq[%i] continuing" % i)
        continue
      else:
        if diff < min_diff:
          min_i, min_diff = i, diff
          #print("seq: new min_i, min_diff == %r" % ((min_i, min_diff),))

  if min_i == -1:
    return -1, -1

  return min_i, min_diff # (h * (h+1))//2 - sum(l[i:i+h-1]) - 1
      
if __name__ == "__main__":
  with open(__task__ + ".in") as fi:
    h = int(fi.readline().split()[1])
    a = map(int, fi.readline().split())
    #print(seq(a,h))
    i, s = seq(a,h)
    with open(__task__ + ".out", 'w') as fo:
      fo.write(str(s))
