def selectionSort(alist):
    for fill_slot in range(len(alist)-1, 0, -1):
        positionOfMax = 0
        for item in range(1, fill_slot):
           if alist[item] > alist[positionOfMax]:
                positionOfMax = item
        alist[fill_slot], alist[positionOfMax] = alist[positionOfMax], alist[fill_slot]
   
alist = [54, 26, 93, 17, 77, 31, 44, 55, 20]
selectionSort(alist)
print alist
