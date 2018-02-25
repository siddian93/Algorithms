def find_target(str):
    for s in strs:
        if (s == tar):
            return 1
    return 0

N = input()
strs = []
for i in xrange(N):
    strs.append(input())

print strs
tar = input()
print find_target(strs)
    

