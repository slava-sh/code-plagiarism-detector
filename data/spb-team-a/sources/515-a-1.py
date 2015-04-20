def abcd(ab, cd):
  print((ab, cd))
  return (ab**2 + cd**2) % 7 == 1

if __name__ == "__main__":
  with open("abcd.in") as fi:
    with open("abcd.out", 'w') as fo:
      fi.readline()
      for l in fi:
        ab, cd = int(l[0:2]), int(l[2:4])
        fo.write(("YES" if abcd(ab, cd) else "NO")+"\n")
