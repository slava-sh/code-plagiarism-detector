__task__ = "seq"
__author__ = "Ale <ale@songbee.net>"

INF = float('+inf')

class Continue(Exception):
  pass

def seq(l, h):
  l = list(l)
  min_i, min_hs = -1, INF
  
  for i in range(len(l)-h):
    if l[i] <= 1:
      s = 0
      try:
        for j in range(1, h):
          if l[i+j] > j+1:
            raise Continue()
          s += l[i+j]
          if h-s >= min_hs:
            raise Continue()
      except Continue:
        continue
      else:
        if h-s < min_hs:
          min_i, min_hs = i, h-s

  if min_i == -1:
    return -1, -1

  return min_i, (h * (h+1))//2 - sum(l[i:i+h-1]) - 1
      
if __name__ == "__main__":
  with open(__task__ + ".in") as fi:
    h = int(fi.readline().split()[1])
    a = map(int, fi.readline().split())
    #print(seq(a,h))
    i, s = seq(a,h)
    with open(__task__ + ".out", 'w') as fo:
      fo.write(str(s))
