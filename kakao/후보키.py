from itertools import combinations

# 1. 유일성 만족
# 2. 최소성 만족
def check(relation, colLst, rows):
    # 각각의 tuple에 해당하는 속성 가지는 배열 새로 만들기
    tmp = [tuple([item[idx] for idx in colLst]) for item in relation]
    # 집합으로 바꿔서 중복이 있는지 확인
    if len(set(tmp)) != rows: 
        return False
    else: 
        return True

def solution(relation):
    rows = len(relation)
    cols = len(relation[0])
    colLst = range(cols)
    lst = []
    
    for l in range(1, cols + 1):
        com = combinations(colLst, l)
        for n in list(com):
            if check(relation, n, rows):
                lst.append(set(n))

    for l1 in lst[:]:
        for l2 in lst[:]:
            if l1 == l1 & l2:
                if l1 != l2:
                    lst.remove(l2)
    return len(lst)
