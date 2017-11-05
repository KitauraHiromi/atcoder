# python2.7
DEBUG = False

def binary_search_in(val, li):
    # required: li is sorted list.
    # return val is in li or not.
    if DEBUG:
        print(li)
    if li == []:
        return False
    if val == li[0]:
        return True
    N = len(li)
    if val < li[N/2]:
        return binary_search(val, li[:N/2+1])
    else:
        return binary_search(val, li[N/2:])

def binary_search(li, val, lower=0, upper=None):
    # required: li is sorted list.
    # return index of val
    if lower < 0:
        return ValueError("lower must be non-negative")
    if upper is None:
        upper = len(li)
    while lower < upper:
        mid = (lower + upper) // 2
        if DEBUG:
            print(li[mid])
        if val == li[mid]:
            return mid
        if val < li[mid]:
            upper = mid
        else:
            lower = mid + 1
    return None
print(binary_search([1,2,3,4,5,6,7,8,9,10,11,12,13], 6))