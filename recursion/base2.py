class Stack:
   def __init__(self):
       self.numbers = []

   def push(self, item):
       print "pushing " + str(item)
       self.numbers.append(item)

   def pop(self):
       return self.numbers.pop()

   def is_empty(self):
       return (self.numbers == [])

def toStr(n , base):
   convertStr = "0123456789ABCDEF"
   #print "n is " + str(n)
   #print "base is " + str(base)
   return_value = 0
   myStack = Stack()
   while n > 0:
      result = n%base
      print result
      myStack.push(convertStr[result])
      n = n//base
      #print  str("") + convertStr[result] + str(""),
   string = ""
   while (not myStack.is_empty()):
      string +=  str(myStack.pop())

   return string
print toStr(1453, 16)
