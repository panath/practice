def toStr(n , base):
   convertStr = "0123456789ABCDEF"
   #print "n is " + str(n)
   #print "base is " + str(base)
   if n < base:
      return convertStr[n]
   else:
      return toStr(n//base,base) + convertStr[n%base]

print toStr(5,2)
