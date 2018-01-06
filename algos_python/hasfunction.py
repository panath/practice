import unittest

class HashTable:
     def __init__(self, size):
         self.size = size
         self.slots = [None]*size
         self.data = [None]*size

     def put(self, key, value):
         hash_value = self.hash(key, self.size)

         if self.slots[hash_value] == None:
             self.slots[hash_value] = key
             self.data[hash_value] = value

         else:
             rehash = self.rehash(key, self.size)
             while (self.slots[rehash] != None or self.slots[rehash] != key):
                 rehash = self.rehash(rehash, self.size)

             if self.slots[rehash] == None:
                 self.slots[rehash] = key
                 self.data[rehash] = value
             else:
                 self.data[rehash] = value

     def __putitem__(self, key, data):
         return self.put(key, data)

     def __getitem__(self, key):
         return self.get(key)

     def get(self, key):
         hash_value = self.hash(key, self.size)
         if self.slots[hash_value] == key:
              return self.data[hash_value]
         else:
             rehash =  hash_value 
             stop = False
             while self.slots[rehash] != key and stop == False:
                 rehash = self.rehash(rehash, self.size)
                 if rehash == hash_value:
                     stop = True

             if self.slots[rehash] == key:
                 return self.data[rehash]
             else:
                return None

     def hash(self, key, size):
         return key%size

     def rehash(self, key, size):
         return (key+1)%size

class TestHashTable(unittest.TestCase):

    def test_hash(self):
        hashTable = HashTable(11)
        value = hashTable.hash(123, 11)
        self.assertEqual(value, 2)

    def test_rehash(self):
        hashTable = HashTable(11)
        value = hashTable.rehash(123, 11)
        self.assertEqual(value, 3)

    def test_push(self):
        hashTable = HashTable(11)
        hashTable.put(123, 12)
        self.assertEqual(hashTable.size, 11)
        self.assertEqual(hashTable.slots[2], 123)
        self.assertEqual(hashTable.data[2], 12)

    def test_get(self):
        hashTable = HashTable(11)
        hashTable.put(123, 12)
        hashTable.put(123, 13)
        self.assertEqual(hashTable.size, 11)
        self.assertEqual(hashTable.slots[2], 123)
        self.assertEqual(hashTable.data[2], 12)
        #value = hashTable.get(123)
        #self.assertEqual(value, 12)

if __name__ == '__main__':
    unittest.main()
