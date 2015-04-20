__task__ = "names"
__author__ = "Ale <ale@songbee.net>"

def names(nn):
  nnn = []
  is_name = {}

  for n in nn:
    nnn.append(n)
    if n[0] in is_name:
      is_name[n[0]] = True
    else:
      is_name[n[0]] = False
      
    if n[1] in is_name:
      is_name[n[1]] = True
    else:
      is_name[n[1]] = False

  for n in nnn:
    if is_name[n[0]]:
      yield "%s %s %s" % (n[2], n[0], n[1])
    else:
      yield " ".join(n)

if __name__ == "__main__":
  with open(__task__ + ".in") as fi:
    fi.readline()
    nms = map(lambda x: x.split()[:3], fi)
    with open(__task__ + ".out", 'w') as fo:
      for name in sorted(names(nms)):
        fo.write(name + "\n")
