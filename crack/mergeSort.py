import unittest

def mergeSort(alist):
    if len(alist) <= 1:
        return
    else:
        mid = len(alist)//2
        leftList = alist[mid:]
        rightList = alist[:mid]

        mergeSort(leftList)
        mergeSort(rightList)

        i = 0
        j = 0
        k = 0

        while i < len(leftList) and j < len(rightList):
            if leftList[i] < rightList[j]:
                alist[k] = leftList[i]
                i = i+1
            else:
                alist[k] = rightList[j]
                j = j+1
            k = k+1
        while i < len(leftList):
            alist[k] = leftList[i]
            i = i + 1
            k = k + 1
        while j < len(rightList):
            alist[k] = rightList[j]
            j = j + 1
	    k = k + 1


class TestMergeSort(unittest.TestCase):

    def test_merge_sort(self):
        self.assertEqual('foo'.upper(), 'FOO')
        list1 = [54, 26, 93, 17, 77, 31, 44, 55, 20]
        mergeSort(list1)
        expected_list = [17, 20, 26, 31, 44, 54, 55, 77, 93]
        self.assertEquals(list1, expected_list) 


if __name__ == '__main__':
    unittest.main()
